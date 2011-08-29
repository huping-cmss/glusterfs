/*
  Copyright (c) 2007-2011 Gluster, Inc. <http://www.gluster.com>
  This file is part of GlusterFS.

  GlusterFS is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.

  GlusterFS is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/>.
*/

#include "xdr-common.h"

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "glusterfs3-xdr.h"

bool_t
xdr_gf_statfs (XDR *xdrs, gf_statfs *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_u_quad_t (xdrs, &objp->bsize))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->frsize))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->blocks))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->bfree))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->bavail))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->files))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->ffree))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->favail))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->fsid))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->flag))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->namemax))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_proto_flock (XDR *xdrs, gf_proto_flock *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->whence))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->start))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->len))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->pid))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->owner))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_iatt (XDR *xdrs, gf_iatt *objp)
{
	register int32_t *buf;
        buf = NULL;


	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_opaque (xdrs, objp->ia_gfid, 16))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_ino))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_dev))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_u_int (xdrs, &objp->mode))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_nlink))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_uid))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_gid))
				 return FALSE;

		} else {
		IXDR_PUT_U_LONG(buf, objp->mode);
		IXDR_PUT_U_LONG(buf, objp->ia_nlink);
		IXDR_PUT_U_LONG(buf, objp->ia_uid);
		IXDR_PUT_U_LONG(buf, objp->ia_gid);
		}
		 if (!xdr_u_quad_t (xdrs, &objp->ia_rdev))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_size))
			 return FALSE;
		 if (!xdr_u_int (xdrs, &objp->ia_blksize))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_blocks))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 6 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_u_int (xdrs, &objp->ia_atime))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_atime_nsec))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_mtime))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_mtime_nsec))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_ctime))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_ctime_nsec))
				 return FALSE;
		} else {
			IXDR_PUT_U_LONG(buf, objp->ia_atime);
			IXDR_PUT_U_LONG(buf, objp->ia_atime_nsec);
			IXDR_PUT_U_LONG(buf, objp->ia_mtime);
			IXDR_PUT_U_LONG(buf, objp->ia_mtime_nsec);
			IXDR_PUT_U_LONG(buf, objp->ia_ctime);
			IXDR_PUT_U_LONG(buf, objp->ia_ctime_nsec);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_opaque (xdrs, objp->ia_gfid, 16))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_ino))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_dev))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_u_int (xdrs, &objp->mode))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_nlink))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_uid))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_gid))
				 return FALSE;

		} else {
		objp->mode = IXDR_GET_U_LONG(buf);
		objp->ia_nlink = IXDR_GET_U_LONG(buf);
		objp->ia_uid = IXDR_GET_U_LONG(buf);
		objp->ia_gid = IXDR_GET_U_LONG(buf);
		}
		 if (!xdr_u_quad_t (xdrs, &objp->ia_rdev))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_size))
			 return FALSE;
		 if (!xdr_u_int (xdrs, &objp->ia_blksize))
			 return FALSE;
		 if (!xdr_u_quad_t (xdrs, &objp->ia_blocks))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 6 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_u_int (xdrs, &objp->ia_atime))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_atime_nsec))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_mtime))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_mtime_nsec))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_ctime))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->ia_ctime_nsec))
				 return FALSE;
		} else {
			objp->ia_atime = IXDR_GET_U_LONG(buf);
			objp->ia_atime_nsec = IXDR_GET_U_LONG(buf);
			objp->ia_mtime = IXDR_GET_U_LONG(buf);
			objp->ia_mtime_nsec = IXDR_GET_U_LONG(buf);
			objp->ia_ctime = IXDR_GET_U_LONG(buf);
			objp->ia_ctime_nsec = IXDR_GET_U_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_opaque (xdrs, objp->ia_gfid, 16))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->ia_ino))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->ia_dev))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_nlink))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_uid))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_gid))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->ia_rdev))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->ia_size))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_blksize))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->ia_blocks))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_atime))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_atime_nsec))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_mtime))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_mtime_nsec))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_ctime))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->ia_ctime_nsec))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_stat_req (XDR *xdrs, gfs3_stat_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_stat_rsp (XDR *xdrs, gfs3_stat_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_readlink_req (XDR *xdrs, gfs3_readlink_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_readlink_rsp (XDR *xdrs, gfs3_readlink_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->buf))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_mknod_req (XDR *xdrs, gfs3_mknod_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->dev))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_mknod_rsp (XDR *xdrs, gfs3_mknod_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_mkdir_req (XDR *xdrs, gfs3_mkdir_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_mkdir_rsp (XDR *xdrs, gfs3_mkdir_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_unlink_req (XDR *xdrs, gfs3_unlink_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_unlink_rsp (XDR *xdrs, gfs3_unlink_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_rmdir_req (XDR *xdrs, gfs3_rmdir_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_rmdir_rsp (XDR *xdrs, gfs3_rmdir_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_symlink_req (XDR *xdrs, gfs3_symlink_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->linkname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_symlink_rsp (XDR *xdrs, gfs3_symlink_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_rename_req (XDR *xdrs, gfs3_rename_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->oldgfid, 16))
		 return FALSE;
	 if (!xdr_opaque (xdrs, objp->newgfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->oldpath, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->oldbname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->newpath, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->newbname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_rename_rsp (XDR *xdrs, gfs3_rename_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preoldparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postoldparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->prenewparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postnewparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_link_req (XDR *xdrs, gfs3_link_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->oldgfid, 16))
		 return FALSE;
	 if (!xdr_opaque (xdrs, objp->newgfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->oldpath, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->newpath, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->newbname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_link_rsp (XDR *xdrs, gfs3_link_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_truncate_req (XDR *xdrs, gfs3_truncate_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_truncate_rsp (XDR *xdrs, gfs3_truncate_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->prestat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->poststat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_open_req (XDR *xdrs, gfs3_open_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->wbflags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_open_rsp (XDR *xdrs, gfs3_open_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_read_req (XDR *xdrs, gfs3_read_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_read_rsp (XDR *xdrs, gfs3_read_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_lookup_req (XDR *xdrs, gfs3_lookup_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_lookup_rsp (XDR *xdrs, gfs3_lookup_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_write_req (XDR *xdrs, gfs3_write_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_write_rsp (XDR *xdrs, gfs3_write_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->prestat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->poststat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_statfs_req (XDR *xdrs, gfs3_statfs_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_statfs_rsp (XDR *xdrs, gfs3_statfs_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_statfs (xdrs, &objp->statfs))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_lk_req (XDR *xdrs, gfs3_lk_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->cmd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_gf_proto_flock (xdrs, &objp->flock))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_lk_rsp (XDR *xdrs, gfs3_lk_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_proto_flock (xdrs, &objp->flock))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_inodelk_req (XDR *xdrs, gfs3_inodelk_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->cmd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_gf_proto_flock (xdrs, &objp->flock))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volume, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_finodelk_req (XDR *xdrs, gfs3_finodelk_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->cmd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_gf_proto_flock (xdrs, &objp->flock))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volume, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_flush_req (XDR *xdrs, gfs3_flush_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fsync_req (XDR *xdrs, gfs3_fsync_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->data))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fsync_rsp (XDR *xdrs, gfs3_fsync_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->prestat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->poststat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_setxattr_req (XDR *xdrs, gfs3_setxattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fsetxattr_req (XDR *xdrs, gfs3_fsetxattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_xattrop_req (XDR *xdrs, gfs3_xattrop_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_xattrop_rsp (XDR *xdrs, gfs3_xattrop_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fxattrop_req (XDR *xdrs, gfs3_fxattrop_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fxattrop_rsp (XDR *xdrs, gfs3_fxattrop_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_getxattr_req (XDR *xdrs, gfs3_getxattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->namelen))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_getxattr_rsp (XDR *xdrs, gfs3_getxattr_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fgetxattr_req (XDR *xdrs, gfs3_fgetxattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->namelen))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fgetxattr_rsp (XDR *xdrs, gfs3_fgetxattr_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_removexattr_req (XDR *xdrs, gfs3_removexattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_opendir_req (XDR *xdrs, gfs3_opendir_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_opendir_rsp (XDR *xdrs, gfs3_opendir_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fsyncdir_req (XDR *xdrs, gfs3_fsyncdir_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->data))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_readdir_req (XDR *xdrs, gfs3_readdir_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_readdirp_req (XDR *xdrs, gfs3_readdirp_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_setvolume_req (XDR *xdrs, gf_setvolume_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_setvolume_rsp (XDR *xdrs, gf_setvolume_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_access_req (XDR *xdrs, gfs3_access_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->mask))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_create_req (XDR *xdrs, gfs3_create_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->pargfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->bname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_create_rsp (XDR *xdrs, gfs3_create_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->preparent))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->postparent))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_ftruncate_req (XDR *xdrs, gfs3_ftruncate_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_ftruncate_rsp (XDR *xdrs, gfs3_ftruncate_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->prestat))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->poststat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fstat_req (XDR *xdrs, gfs3_fstat_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fstat_rsp (XDR *xdrs, gfs3_fstat_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_entrylk_req (XDR *xdrs, gfs3_entrylk_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->cmd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->namelen))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volume, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fentrylk_req (XDR *xdrs, gfs3_fentrylk_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->cmd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->namelen))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volume, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_setattr_req (XDR *xdrs, gfs3_setattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stbuf))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->valid))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_setattr_rsp (XDR *xdrs, gfs3_setattr_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->statpre))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->statpost))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fsetattr_req (XDR *xdrs, gfs3_fsetattr_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stbuf))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->valid))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_fsetattr_rsp (XDR *xdrs, gfs3_fsetattr_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->statpre))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->statpost))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_rchecksum_req (XDR *xdrs, gfs3_rchecksum_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->offset))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->len))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_rchecksum_rsp (XDR *xdrs, gfs3_rchecksum_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op_ret))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op_errno))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->weak_checksum))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->op_ret);
		IXDR_PUT_LONG(buf, objp->op_errno);
		IXDR_PUT_U_LONG(buf, objp->weak_checksum);
		}
		 if (!xdr_bytes (xdrs, (char **)&objp->strong_checksum.strong_checksum_val, (u_int *) &objp->strong_checksum.strong_checksum_len, ~0))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op_ret))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op_errno))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->weak_checksum))
				 return FALSE;

		} else {
		objp->op_ret = IXDR_GET_LONG(buf);
		objp->op_errno = IXDR_GET_LONG(buf);
		objp->weak_checksum = IXDR_GET_U_LONG(buf);
		}
		 if (!xdr_bytes (xdrs, (char **)&objp->strong_checksum.strong_checksum_val, (u_int *) &objp->strong_checksum.strong_checksum_len, ~0))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->weak_checksum))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->strong_checksum.strong_checksum_val, (u_int *) &objp->strong_checksum.strong_checksum_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_getspec_req (XDR *xdrs, gf_getspec_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->key, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_getspec_rsp (XDR *xdrs, gf_getspec_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->spec, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_log_req (XDR *xdrs, gf_log_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_bytes (xdrs, (char **)&objp->msg.msg_val, (u_int *) &objp->msg.msg_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_notify_req (XDR *xdrs, gf_notify_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->buf, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_notify_rsp (XDR *xdrs, gf_notify_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op_ret))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op_errno))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->flags))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->op_ret);
		IXDR_PUT_LONG(buf, objp->op_errno);
		IXDR_PUT_U_LONG(buf, objp->flags);
		}
		 if (!xdr_string (xdrs, &objp->buf, ~0))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op_ret))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op_errno))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->flags))
				 return FALSE;

		} else {
		objp->op_ret = IXDR_GET_LONG(buf);
		objp->op_errno = IXDR_GET_LONG(buf);
		objp->flags = IXDR_GET_U_LONG(buf);
		}
		 if (!xdr_string (xdrs, &objp->buf, ~0))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->buf, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_releasedir_req (XDR *xdrs, gfs3_releasedir_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_release_req (XDR *xdrs, gfs3_release_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_opaque (xdrs, objp->gfid, 16))
		 return FALSE;
	 if (!xdr_quad_t (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_common_rsp (XDR *xdrs, gf_common_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_dirlist (XDR *xdrs, gfs3_dirlist *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_u_quad_t (xdrs, &objp->d_ino))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->d_off))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->d_len))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->d_type))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nextentry, sizeof (gfs3_dirlist), (xdrproc_t) xdr_gfs3_dirlist))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_readdir_rsp (XDR *xdrs, gfs3_readdir_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->reply, sizeof (gfs3_dirlist), (xdrproc_t) xdr_gfs3_dirlist))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_dirplist (XDR *xdrs, gfs3_dirplist *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_u_quad_t (xdrs, &objp->d_ino))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->d_off))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->d_len))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->d_type))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_gf_iatt (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nextentry, sizeof (gfs3_dirplist), (xdrproc_t) xdr_gfs3_dirplist))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gfs3_readdirp_rsp (XDR *xdrs, gfs3_readdirp_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->reply, sizeof (gfs3_dirplist), (xdrproc_t) xdr_gfs3_dirplist))
		 return FALSE;
	return TRUE;
}
