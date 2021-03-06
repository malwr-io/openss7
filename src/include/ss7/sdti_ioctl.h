/*****************************************************************************

 @(#) src/include/ss7/sdti_ioctl.h

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

#ifndef __SDTI_IOCTL_H__
#define __SDTI_IOCTL_H__

/* This file can be processed by doxygen(1). */

#include <linux/ioctl.h>

#define SDT_IOC_MAGIC 't'

/*
 *  PROTOCOL VARIANT AND OPTIONS
 */

#define SDT_IOCGOPTIONS	_IOR(  SDT_IOC_MAGIC, 0, lmi_option_t )
#define SDT_IOCSOPTIONS	_IOW(  SDT_IOC_MAGIC, 1, lmi_option_t )

/*
 *  CONFIGURATION
 */
#ifdef __KERNEL__
#ifdef _MPS_SOURCE
typedef struct sdt_timers {
	mblk_t *t8;			/* T8 timer */
} sdt_timers_t;
#else				/* _MPS_SOURCE */
typedef struct sdt_timers {
	toid_t t8;			/* T8 timer */
} sdt_timers_t;
#endif				/* _MPS_SOURCE */
#endif				/* __KERNEL__ */

typedef struct sdt_config {
	sdt_ulong t8;			/* T8 timeout (milliseconds) */
	sdt_ulong Tin;			/* AERM normal proving threshold */
	sdt_ulong Tie;			/* AERM emergency proving threshold */
	sdt_ulong T;			/* SUERM error threshold */
	sdt_ulong D;			/* SUERM error rate parameter */
	sdt_ulong Te;			/* EIM error threshold */
	sdt_ulong De;			/* EIM correct decrement */
	sdt_ulong Ue;			/* EIM error increment */
	sdt_ulong N;			/* octets per su in octet-counting mode */
	sdt_ulong m;			/* maximum SIF size */
	sdt_ulong b;			/* transmit block size */
	sdt_ulong f;			/* number of flags between frames */
} sdt_config_t;

#define SDT_FLAGS_ONE	    0
#define SDT_FLAGS_SHARED    1
#define SDT_FLAGS_TWO	    2
#define SDT_FLAGS_THREE	    3

#define SDT_IOCGCONFIG	_IOWR( SDT_IOC_MAGIC, 2, sdt_config_t )
#define SDT_IOCSCONFIG	_IOWR( SDT_IOC_MAGIC, 3, sdt_config_t )
#define SDT_IOCTCONFIG	_IOWR( SDT_IOC_MAGIC, 4, sdt_config_t )
#define SDT_IOCCCONFIG	_IOWR( SDT_IOC_MAGIC, 5, sdt_config_t )

/*
 *  STATE
 */

typedef struct sdt_statem {
	sdt_ulong aerm_state;		/* AERM state variable */
	sdt_ulong aborted_proving;	/* AERM aborted proving */
	sdt_long Ca;			/* AERM error counter */
	sdt_ulong Ti;			/* AERM threshold */
	sdt_ulong suerm_state;		/* SUERM state variable */
	sdt_long Cs;			/* SUERM error counter */
	sdt_ulong Ns;			/* SUERM su counter */
	sdt_ulong eim_state;		/* EIM state variable */
	sdt_long Ce;			/* EIM counter */
	sdt_ulong su_received;		/* EIM su received flag */
	sdt_ulong interval_error;	/* EIM interval error flag */
	sdt_ulong daedt_state;		/* DAEDT state variable */
	sdt_ulong daedr_state;		/* DAEDR state variable */
	sdt_ulong octet_counting_mode;	/* receivers freewheeling */
} sdt_statem_t;

#define SDT_STATE_IDLE		0x00
#define SDT_STATE_IN_SERVICE	0x01
#define SDT_STATE_MONITORING    SDT_STATE_IN_SERVICE
#define SDT_STATE_CONGESTED	0x02

#define SDT_IOCGSTATEM	_IOR(  SDT_IOC_MAGIC, 6, sdt_statem_t )
#define SDT_IOCCMRESET	_IOR(  SDT_IOC_MAGIC, 7, sdt_statem_t )

/*
 *  STATISTICS
 */

typedef struct sdt_stats {
	lmi_sta_t header;
	sdt_ulong tx_bytes;
	sdt_ulong tx_sus;
	sdt_ulong tx_sus_repeated;
	sdt_ulong tx_underruns;
	sdt_ulong tx_aborts;
	sdt_ulong tx_buffer_overflows;
	sdt_ulong tx_sus_in_error;
	sdt_ulong rx_bytes;
	sdt_ulong rx_sus;
	sdt_ulong rx_sus_compressed;
	sdt_ulong rx_overruns;
	sdt_ulong rx_aborts;
	sdt_ulong rx_buffer_overflows;
	sdt_ulong rx_sus_in_error;
	sdt_ulong rx_sync_transitions;
	sdt_ulong rx_bits_octet_counted;
	sdt_ulong rx_crc_errors;
	sdt_ulong rx_frame_errors;
	sdt_ulong rx_frame_overflows;
	sdt_ulong rx_frame_too_long;
	sdt_ulong rx_frame_too_short;
	sdt_ulong rx_residue_errors;
	sdt_ulong rx_length_error;	/* error in length indicator */
	sdt_ulong carrier_cts_lost;
	sdt_ulong carrier_dcd_lost;
	sdt_ulong carrier_lost;
} sdt_stats_t;

#define SDT_IOCGSTATSP	_IOR(  SDT_IOC_MAGIC,  8, lmi_sta_t )
#define SDT_IOCSSTATSP	_IOWR( SDT_IOC_MAGIC,  9, lmi_sta_t )
#define SDT_IOCGSTATS	_IOR(  SDT_IOC_MAGIC, 10, sdt_stats_t )
#define SDT_IOCCSTATS	_IOW(  SDT_IOC_MAGIC, 11, sdt_stats_t )

/*
 *  EVENTS
 */
typedef struct sdt_notify {
	sdt_ulong events;
} sdt_notify_t;

#define SDT_EVT_LOST_SYNC	0x00000001
#define SDT_EVT_SU_ERROR	0x00000002
#define SDT_EVT_TX_FAIL		0x00000004
#define SDT_EVT_RX_FAIL		0x00000008
#define SDT_EVT_CARRIER		0x00000010

#define SDT_IOCGNOTIFY	_IOR(  SDT_IOC_MAGIC, 12, sdt_notify_t )
#define SDT_IOCSNOTIFY	_IOW(  SDT_IOC_MAGIC, 13, sdt_notify_t )
#define SDT_IOCCNOTIFY	_IOW(  SDT_IOC_MAGIC, 14, sdt_notify_t )

/*
 *  PASS
 */
typedef struct sdt_pass {
	sdt_long index;			/* lower multiplex index */
	sdt_ulong cmd;			/* embedded input-output control command */
	/* followed by cmd specific structure */
} sdt_pass_t;

#define	SDT_IOCCPASS	_IOWR(  SDT_IOC_MAGIC, 15, sdt_pass_t  )

/*
   for testing only 
 */
#define SDT_IOCCABORT	_IO(   SDT_IOC_MAGIC, 16 )

#define SDT_IOC_FIRST    0
#define SDT_IOC_LAST    16
#define SDT_IOC_PRIVATE 32

#endif				/* __SDTI_IOCTL_H__ */
