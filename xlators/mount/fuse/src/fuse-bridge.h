/*
   Copyright (c) 2006-2012 Red Hat, Inc. <http://www.redhat.com>
   This file is part of GlusterFS.

   This file is licensed to you under your choice of the GNU Lesser
   General Public License, version 3 or any later version (LGPLv3 or
   later), or the GNU General Public License, version 2 (GPLv2), in all
   cases as published by the Free Software Foundation.
*/
#ifndef _GF_FUSE_BRIDGE_H_
#define _GF_FUSE_BRIDGE_H_

#include <stdint.h>
#include <signal.h>
#include <pthread.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/mount.h>
#include <sys/time.h>
#include <fnmatch.h>

#include <glusterfs/logging.h>
#include <glusterfs/statedump.h>

#ifdef GF_DARWIN_HOST_OS
#include "fuse_kernel_macfuse.h"
#else
#include "fuse_kernel.h"
#endif
#include "fuse-misc.h"
#include "fuse-mount.h"
#include "fuse-mem-types.h"

#include <glusterfs/list.h>
#include <glusterfs/dict.h>
#include <glusterfs/syncop.h>
#include <glusterfs/gidcache.h>

#define GLUSTERFS_XATTR_LEN_MAX 65536

#define MAX_FUSE_PROC_DELAY 1

typedef struct fuse_in_header fuse_in_header_t;
typedef void(fuse_handler_t)(xlator_t *this, fuse_in_header_t *finh, void *msg,
                             struct iobuf *iobuf);

enum fusedev_errno {
    FUSEDEV_ENOENT,
    FUSEDEV_ENOTDIR,
    FUSEDEV_ENODEV,
    FUSEDEV_EPERM,
    FUSEDEV_ENOMEM,
    FUSEDEV_ENOTCONN,
    FUSEDEV_ECONNREFUSED,
    FUSEDEV_EOVERFLOW,
    FUSEDEV_EBUSY,
    FUSEDEV_ENOTEMPTY,
    FUSEDEV_EMAXPLUS
};

struct fuse_private {
    int fd;
    uint32_t proto_minor;
    char *volfile;
    size_t volfile_size;
    char *mount_point;
    struct iobuf *iobuf;

    pthread_t *fuse_thread;
    uint32_t reader_thread_count;
    char fuse_thread_started;

    uint32_t direct_io_mode;
    size_t *msg0_len_p;

    double entry_timeout;
    double negative_timeout;
    double attribute_timeout;

    pthread_cond_t sync_cond;
    pthread_mutex_t sync_mutex;
    char event_recvd;

    char init_recvd;

    gf_boolean_t strict_volfile_check;

    fuse_handler_t **fuse_ops;
    fuse_handler_t **fuse_ops0;
    pthread_mutex_t fuse_dump_mutex;
    int fuse_dump_fd;

    glusterfs_graph_t *next_graph;
    xlator_t *active_subvol;

    pid_t client_pid;
    gf_boolean_t client_pid_set;
    unsigned uid_map_root;
    gf_boolean_t acl;
    gf_boolean_t selinux;
    gf_boolean_t read_only;
    int32_t fopen_keep_cache;
    time_t gid_cache_timeout;
    gf_boolean_t enable_ino32;
    /* This is the mount option for disabling the root-squash for the
       mount irrespective of whether the root-squash option for the
       volume is set or not. But this option is honoured only for
       thr trusted clients. For non trusted clients this value does
       not have any affect and the volume option for root-squash is
       honoured.
    */
    gf_boolean_t no_root_squash;
    fdtable_t *fdtable;
    gid_cache_t gid_cache;
    char *fuse_mountopts;

    /* For fuse-reverse-validation */
    struct list_head invalidate_list;
    pthread_cond_t invalidate_cond;
    pthread_mutex_t invalidate_mutex;
    gf_boolean_t reverse_fuse_thread_started;
    uint64_t invalidate_count;
    /* For communicating with separate mount thread. */
    int status_pipe[2];

    /* for fuse queue length and congestion threshold */
    int background_qlen;
    int congestion_threshold;

    /* for using fuse-kernel readdirp*/
    gf_boolean_t use_readdirp;

    /* fini started, helps prevent multiple epoll worker threads
     * firing up the fini routine */
    gf_boolean_t fini_invoked;

    /* resolve gid with getgrouplist() instead of /proc/%d/status */
    gf_boolean_t resolve_gids;

    /* Enable or disable capability support */
    gf_boolean_t capability;

    /* Enable or disable event history */
    gf_boolean_t event_history;

    /* whether to run the unmount daemon */
    gf_boolean_t auto_unmount;

    /* Load the thin volfile, and connect to gfproxyd*/
    gf_boolean_t thin_client;
    gf_boolean_t mount_finished;
    gf_boolean_t handle_graph_switch;
    pthread_cond_t migrate_cond;

    /* Writeback cache support */
    gf_boolean_t kernel_writeback_cache;
    int attr_times_granularity;

    /* Delayed fuse response */
    struct list_head timed_list;
    pthread_cond_t timed_cond;
    pthread_mutex_t timed_mutex;
    gf_boolean_t timed_response_fuse_thread_started;

    /* Interrupt subscription */
    struct list_head interrupt_list;
    pthread_mutex_t interrupt_mutex;

    gf_boolean_t flush_handle_interrupt;
    gf_boolean_t setlk_handle_interrupt;
    gf_boolean_t fuse_auto_inval;

    /* LRU Limit, if not set, default is 64k for now */
    uint32_t lru_limit;
    uint32_t inode_table_size;
    uint32_t invalidate_limit;
    uint32_t fuse_dev_eperm_ratelimit_ns;

    /* counters for fusdev errnos */
    uint8_t fusedev_errno_cnt[FUSEDEV_EMAXPLUS];
    pthread_mutex_t fusedev_errno_cnt_mutex;
};
typedef struct fuse_private fuse_private_t;

typedef uint64_t errnomask_t[2];
#define MASK_ERRNO(mask, n) ((mask)[(n) >> 6] |= ((uint64_t)1 << ((n)&63)))
#define GET_ERRNO_MASK(mask, n) ((mask)[(n) >> 6] & ((uint64_t)1 << ((n)&63)))
#define ERRNOMASK_MAX (64 * (sizeof(errnomask_t) / sizeof(uint64_t)))

#define INVAL_BUF_SIZE                                                         \
    (sizeof(struct fuse_out_header) +                                          \
     max(sizeof(struct fuse_notify_inval_inode_out),                           \
         sizeof(struct fuse_notify_inval_entry_out) + NAME_MAX + 1))

struct fuse_invalidate_node {
    errnomask_t errnomask;
    struct list_head next;
    char inval_buf[INVAL_BUF_SIZE];
};
typedef struct fuse_invalidate_node fuse_invalidate_node_t;

struct fuse_timed_message {
    struct fuse_out_header fuse_out_header;
    void *fuse_message_body;
    struct timespec scheduled_ts;
    errnomask_t errnomask;
    struct list_head next;
};
typedef struct fuse_timed_message fuse_timed_message_t;

enum fuse_interrupt_state {
    INTERRUPT_NONE,
    INTERRUPT_SQUELCHED,
    INTERRUPT_HANDLED,
    INTERRUPT_WAITING_HANDLER,
};
typedef enum fuse_interrupt_state fuse_interrupt_state_t;
struct fuse_interrupt_record;
typedef struct fuse_interrupt_record fuse_interrupt_record_t;
typedef void (*fuse_interrupt_handler_t)(xlator_t *this,
                                         fuse_interrupt_record_t *);
struct fuse_interrupt_record {
    fuse_in_header_t fuse_in_header;
    void *data;
    gf_boolean_t hit;
    fuse_interrupt_state_t interrupt_state;
    fuse_interrupt_handler_t interrupt_handler;
    pthread_cond_t handler_cond;
    pthread_mutex_t handler_mutex;
    struct list_head next;
};

struct fuse_graph_switch_args {
    xlator_t *this;
    xlator_t *old_subvol;
    xlator_t *new_subvol;
};
typedef struct fuse_graph_switch_args fuse_graph_switch_args_t;

#define FUSE_EVENT_HISTORY_SIZE 1024

#define _FH_TO_FD(fh) ((fd_t *)(uintptr_t)(fh))

#define FH_TO_FD(fh) ((_FH_TO_FD(fh)) ? (fd_ref(_FH_TO_FD(fh))) : ((fd_t *)0))

/* Use the same logic as the Linux NFS-client */
#define GF_FUSE_SQUASH_INO(ino) (((uint32_t)ino) ^ (ino >> 32))

#define FUSE_FOP(state, ret, op_num, fop, args...)                             \
    do {                                                                       \
        xlator_t *xl = NULL;                                                   \
        call_frame_t *frame = NULL;                                            \
                                                                               \
        xl = state->active_subvol;                                             \
        if (!xl) {                                                             \
            gf_log_callingfn(state->this->name, GF_LOG_ERROR,                  \
                             "No active subvolume");                           \
            send_fuse_err(state->this, state->finh, ENOENT);                   \
            free_fuse_state(state);                                            \
            break;                                                             \
        }                                                                      \
                                                                               \
        frame = get_call_frame_for_req(state, op_num);                         \
        if (!frame) {                                                          \
            /* This is not completely clean, as some                           \
             * earlier allocations might remain unfreed                        \
             * if we return at this point, but still                           \
             * better than trying to go on with a NULL                         \
             * frame ...                                                       \
             */                                                                \
            send_fuse_err(state->this, state->finh, ENOMEM);                   \
            free_fuse_state(state);                                            \
            /* ideally, need to 'return', but let the */                       \
            /* calling function take care of it */                             \
            break;                                                             \
        }                                                                      \
                                                                               \
        frame->root->state = state;                                            \
        frame->root->op = op_num;                                              \
        frame->op = op_num;                                                    \
                                                                               \
        if (state->this->history)                                              \
            gf_log_eh("%" PRIu64                                               \
                      ", %s, path: (%s), gfid: "                               \
                      "(%s)",                                                  \
                      frame->root->unique, gf_fop_list[frame->root->op],       \
                      state->loc.path,                                         \
                      (state->fd == NULL)                                      \
                          ? uuid_utoa(state->loc.gfid)                         \
                          : uuid_utoa(state->fd->inode->gfid));                \
        STACK_WIND(frame, ret, xl, xl->fops->fop, args);                       \
    } while (0)

#define GF_SELECT_LOG_LEVEL(_errno)                                            \
        (((_errno == ENOENT) || (_errno == ESTALE))?    \
         GF_LOG_DEBUG)

#define GET_STATE(this, finh, state)                                           \
    do {                                                                       \
        state = get_fuse_state(this, finh);                                    \
        if (!state) {                                                          \
            gf_log("glusterfs-fuse", GF_LOG_ERROR,                             \
                   "FUSE message unique %" PRIu64                              \
                   " opcode %d:"                                               \
                   " state allocation failed",                                 \
                   finh->unique, finh->opcode);                                \
                                                                               \
            send_fuse_err(this, finh, ENOMEM);                                 \
            GF_FREE(finh);                                                     \
                                                                               \
            return;                                                            \
        }                                                                      \
    } while (0)

#define FUSE_ENTRY_CREATE(this, priv, finh, state, fci, op)                    \
    do {                                                                       \
        if (priv->proto_minor >= 12)                                           \
            state->mode &= ~fci->umask;                                        \
        if (priv->proto_minor >= 12 && priv->acl) {                            \
            state->xdata = dict_new();                                         \
            if (!state->xdata) {                                               \
                gf_log("glusterfs-fuse", GF_LOG_WARNING,                       \
                       "%s failed to allocate "                                \
                       "a param dictionary",                                   \
                       op);                                                    \
                send_fuse_err(this, finh, ENOMEM);                             \
                free_fuse_state(state);                                        \
                return;                                                        \
            }                                                                  \
            state->umask = fci->umask;                                         \
                                                                               \
            ret = dict_set_int16(state->xdata, "umask", fci->umask);           \
            if (ret < 0) {                                                     \
                gf_log("glusterfs-fuse", GF_LOG_WARNING,                       \
                       "%s Failed adding umask"                                \
                       " to request",                                          \
                       op);                                                    \
                send_fuse_err(this, finh, ENOMEM);                             \
                free_fuse_state(state);                                        \
                return;                                                        \
            }                                                                  \
            ret = dict_set_int16(state->xdata, "mode", fci->mode);             \
            if (ret < 0) {                                                     \
                gf_log("glusterfs-fuse", GF_LOG_WARNING,                       \
                       "%s Failed adding mode "                                \
                       "to request",                                           \
                       op);                                                    \
                send_fuse_err(this, finh, ENOMEM);                             \
                free_fuse_state(state);                                        \
                return;                                                        \
            }                                                                  \
        }                                                                      \
    } while (0)

#define fuse_log_eh_fop(this, state, frame, op_ret, op_errno)                  \
    do {                                                                       \
        fuse_private_t *priv = this->private;                                  \
        if (this->history && priv->event_history) {                            \
            if (state->fd)                                                     \
                gf_log_eh(                                                     \
                    "op_ret: %d, op_errno: %d, "                               \
                    "%" PRIu64 ", %s () => %p, gfid: %s",                      \
                    op_ret, op_errno, frame->root->unique,                     \
                    gf_fop_list[frame->root->op], state->fd,                   \
                    uuid_utoa(state->fd->inode->gfid));                        \
            else                                                               \
                gf_log_eh(                                                     \
                    "op_ret: %d, op_errno: %d, "                               \
                    "%" PRIu64 ", %s () => %s, gfid: %s",                      \
                    op_ret, op_errno, frame->root->unique,                     \
                    gf_fop_list[frame->root->op], state->loc.path,             \
                    uuid_utoa(state->loc.gfid));                               \
        }                                                                      \
    } while (0)

#define fuse_log_eh(this, args...)                                             \
    do {                                                                       \
        fuse_private_t *priv = this->private;                                  \
        if (this->history && priv->event_history)                              \
            gf_log_eh(args);                                                   \
    } while (0)

static inline xlator_t *
fuse_active_subvol(xlator_t *fuse)
{
    fuse_private_t *priv = NULL;

    priv = fuse->private;

    return priv->active_subvol;
}

typedef enum {
    RESOLVE_MUST = 1,
    RESOLVE_NOT,
    RESOLVE_MAY,
    RESOLVE_DONTCARE,
    RESOLVE_EXACT
} fuse_resolve_type_t;

typedef struct {
    fuse_resolve_type_t type;
    fd_t *fd;
    char *path;
    char *bname;
    u_char gfid[16];
    inode_t *hint;
    u_char pargfid[16];
    inode_t *parhint;
    int op_ret;
    int op_errno;
    loc_t resolve_loc;
} fuse_resolve_t;

typedef struct {
    void *pool;
    xlator_t *this;
    xlator_t *active_subvol;
    inode_table_t *itable;
    loc_t loc;
    loc_t loc2;
    fuse_in_header_t *finh;
    int32_t flags;

    off_t off;
    /*
     * The man page of copy_file_range tells that the offset
     * arguments are of type loff_t *. Here in fuse state, the values of
     * those offsets are saved instead of pointers as the kernel sends
     * the values of the offsets from those pointers instead of pointers.
     * But the type loff_t is linux specific and is actually a typedef of
     * off64_t. Hence using off64_t
     */
    off64_t off_in;  /* for copy_file_range source fd */
    off64_t off_out; /* for copy_file_range destination fd */
    size_t size;
    unsigned long nlookup;
    fd_t *fd;
    fd_t *fd_dst; /* for copy_file_range destination */
    dict_t *xattr;
    dict_t *xdata;
    char *name;
    char is_revalidate;
    gf_boolean_t truncate_needed;
    gf_lock_t lock;
    uint64_t lk_owner;

    /* used within resolve_and_resume */
    /* */
    fuse_resolve_t resolve;
    fuse_resolve_t resolve2;

    loc_t *loc_now;
    fuse_resolve_t *resolve_now;

    void *resume_fn;

    int valid;
    int mask;
    dev_t rdev;
    mode_t mode;
    mode_t umask;
    struct iatt attr;
    struct gf_flock lk_lock;
    struct iovec vector;

    uuid_t gfid;
    uint32_t io_flags;
    int32_t fd_no;

    gf_seek_what_t whence;
    struct iobuf *iobuf;
} fuse_state_t;

typedef struct {
    uint32_t open_flags;
    char migration_failed;
    fd_t *activefd;
} fuse_fd_ctx_t;

typedef void (*fuse_resume_fn_t)(fuse_state_t *state);

GF_MUST_CHECK int32_t
fuse_loc_fill(loc_t *loc, fuse_state_t *state, ino_t ino, ino_t par,
              const char *name);
call_frame_t *
get_call_frame_for_req(fuse_state_t *state, int op_num);
fuse_state_t *
get_fuse_state(xlator_t *this, fuse_in_header_t *finh);
void
free_fuse_state(fuse_state_t *state);
void
gf_fuse_stat2attr(struct iatt *st, struct fuse_attr *fa,
                  gf_boolean_t enable_ino32);
void
gf_fuse_fill_dirent(gf_dirent_t *entry, struct fuse_dirent *fde,
                    gf_boolean_t enable_ino32);
uint64_t
inode_to_fuse_nodeid(inode_t *inode);
xlator_t *
fuse_active_subvol(xlator_t *fuse);
inode_t *
fuse_ino_to_inode(uint64_t ino, xlator_t *fuse);
int
send_fuse_err(xlator_t *this, fuse_in_header_t *finh, int error);
int
fuse_gfid_set(fuse_state_t *state);
int
fuse_flip_xattr_ns(struct fuse_private *priv, char *okey, char **nkey);
fuse_fd_ctx_t *
__fuse_fd_ctx_check_n_create(xlator_t *this, fd_t *fd);
fuse_fd_ctx_t *
fuse_fd_ctx_check_n_create(xlator_t *this, fd_t *fd);

int
fuse_resolve_and_resume(fuse_state_t *state, fuse_resume_fn_t fn);
int
fuse_resolve_inode_init(fuse_state_t *state, fuse_resolve_t *resolve,
                        ino_t ino);
int
fuse_resolve_entry_init(fuse_state_t *state, fuse_resolve_t *resolve, ino_t par,
                        char *name);
int
fuse_resolve_fd_init(fuse_state_t *state, fuse_resolve_t *resolve, fd_t *fd);
int
fuse_ignore_xattr_set(fuse_private_t *priv, char *key);
void
fuse_fop_resume(fuse_state_t *state);
int
fuse_check_selinux_cap_xattr(fuse_private_t *priv, char *name);
#endif /* _GF_FUSE_BRIDGE_H_ */
