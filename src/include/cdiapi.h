/*****************************************************************************

 @(#) src/include/cdiapi.h

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 *****************************************************************************/

#ifndef __CDIAPI_H__
#define __CDIAPI_H__

#include <sys/cdi.h>

#define CDI_CTL_BUF_SIZE	(sizeof(union CD_primitives) + 32)
#define CDI_DATA_BUF_SIZE	4096

extern int *_cdi_data_cnt(void);
extern int *_cdi_ctl_cnt(void);
extern unsigned char *_cdi_data_buf(void);
extern unsigned char *_cdi_ctl_buf(void);

#define cdi_data_cnt	(*_cdi_data_cnt())
#define cdi_ctl_cnt	(*_cdi_ctl_cnt())
#define cdi_data_buf	(_cdi_data_buf())
#define cdi_ctl_buf	(_cdi_ctl_buf())

#define Return_error_ack	(1<<0)
#define Return_info_ack		(1<<1)
#define Return_unidata_ack	(1<<2)
#define Return_error_ind	(1<<3)
#define Return_disable_con	(1<<4)
#define Return_enable_con	(1<<5)
#define RetryOnSignal		(1<<6)
#define Return_ok_ack		(1<<7)
#define Return_bad_frame_ind	(1<<8)
#define Return_modem_sig_ind	(1<<9)

#define CDI_LOG_FILE		(1<<0)
#define CDI_LOG_STDERR		(1<<1)
#define CDI_LOG_RX_PROTOS	(1<<2)
#define CDI_LOG_TX_PROTOS	(1<<3)
#define CDI_LOG_ERRORS		(1<<4)
#define CDI_LOG_SIGNALS		(1<<5)
#define CDI_LOG_RX_DATA		(1<<6)
#define CDI_LOG_TX_DATA		(1<<7)
#define CDI_LOG_DISCARDS	(1<<8)
#define CDI_LOG_VERBOSE		(1<<9)
#define CDI_LOG_DEFAULT		(CDI_LOG_FILE|CDI_LOG_STDERR|CDI_LOG_ERRORS)

extern int *_cerrno(void);
#define cerrno (*(_cerrno()))

#ifdef __BEGIN_DECLS
__BEGIN_DECLS
#endif
extern int cdi_allow_input_req(int fd, int *state_ptr);
extern int cdi_attach_req(int fd, long ppa, int *state_ptr);
extern int cdi_close(int fd);
extern void cdi_decode_ctl(char *p);
extern char *cdi_decode_modem_sigs(unsigned sigs);
extern int cdi_detach_req(int fd, int *state_ptr);
extern int cdi_dial_req(int fd, unsigned int ppa, unsigned int sigs, char *dial_string, int dial_length);
extern int cdi_disable_req(int fd, unsigned long disposal, int *state_ptr);
extern int cdi_enable_req(int fd, int *state_ptr);
extern int cdi_get_a_msg(int fd, char *buf, int size);
extern int cdi_get_modem_sigs(int fd, int flag);
extern int cdi_init(int log_optns, char *log_name);
extern int cdi_init_FILE(int log_optns, FILE * filestream);
extern int cdi_modem_sig_poll(int fd);
extern int cdi_modem_sig_req(int fd, unsigned sigs);
extern int cdi_open_data(void);
extern int cdi_open(char *hostname);
extern void cdi_perror(char *msg);
extern int cdi_printf(char *fmt, ...);
extern void cdi_print_msg(unsigned char *p, unsigned n, int indent);
extern int cdi_put_allow_input_req(int fd);
extern int cdi_put_attach_req(int fd, long ppa);
extern int cdi_put_both(int fd, char *header, int hdr_length, char *data_ptr, int data_length,
			int flags);
extern int cdi_put_data(int fd, char *data_ptr, int length, long flags);
extern int cdi_put_detach_req(int fd);
extern int cdi_put_dial_req(int fd, char *dial_string, int dial_length);
extern int cdi_put_disable_req(int fd, unsigned long disposal);
extern int cdi_put_enable_req(int fd);
extern int cdi_put_frame(int fd, unsigned char address, unsigned char control, unsigned char *ptr,
			 int count);
extern int cdi_put_proto(int cid, int length, long flags);
extern int cdi_rcv_msg(int fd, char *data_ptr, int bfr_len, long flags);
extern int cdi_read_data(int cdi_data, char *buf, int cnt);
extern int cdi_set_log_size(long nbytes);
extern int cdi_wait_ack(int fd, unsigned long primitive, int *state_ptr);
extern int cdi_write_data(int cdi_data, char *buf, int cnt);
extern int cdi_xray_req(int fd, int upa, int on_off, int hi_wat, int lo_wat);

#ifdef __END_DECLS
__END_DECLS
#endif
#include <sys/cdi.h>
#endif				/* __CDIAPI_H__ */
