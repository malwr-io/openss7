/*****************************************************************************

 @(#) src/include/ss7/zapata.h

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

#ifndef __SS7_ZAPATA_H__
#define __SS7_ZAPATA_H__

/* This file can be processed by doxygen(1). */

/* Per-span configuration values */
#define ZT_CONFIG_TXLEVEL	7	/* bits 0-2 are tx level */

/* Line configuration */
/* These apply to T1 */
#define ZT_CONFIG_D4		((1 <<  4))
#define ZT_CONFIG_ESF		((1 <<  5))
#define ZT_CONFIG_AMI		((1 <<  6))
#define ZT_CONFIG_B8ZS		((1 <<  7))
/* These apply to E1 */
#define ZT_CONFIG_CCS		((1 <<  8))	/* CCS (ISDN) instead of CAS (Robbed Bit) */
#define ZT_CONFIG_HDB3		((1 <<  9))	/* HDB3 instead of AMI (line coding) */
#define ZT_CONFIG_CRC4		((1 << 10))	/* CRC4 framing */
#define ZT_CONFIG_NOTOPEN	((1 << 16))

/* Signalling types */
#define __ZT_SIG_FXO		((1 << 12))	/* Never use directly */
#define __ZT_SIG_FXS		((1 << 13))	/* Never use directly */

#define ZT_SIG_NONE		0	/* Channel not configured */
#define ZT_SIG_FXSLS		((1 <<  0) | __ZT_SIG_FXS)	/* FXS, Loopstart */
#define ZT_SIG_FXSGS		((1 <<  1) | __ZT_SIG_FXS)	/* FXS, Groundstart */
#define ZT_SIG_FXSKS		((1 <<  2) | __ZT_SIG_FXS)	/* FXS, Kewlstart */

#define ZT_SIG_FXOLS		((1 <<  3) | __ZT_SIG_FXO)	/* FXO, Loopstart */
#define ZT_SIG_FXOGS		((1 <<  4) | __ZT_SIG_FXO)	/* FXO, Groupstart */
#define ZT_SIG_FXOKS		((1 <<  5) | __ZT_SIG_FXO)	/* FXO, Kewlstart */

#define ZT_SIG_EM		((1 <<  6))	/* Ear & Mouth (E&M) */

/* The following are all variations on clear channel */

#define __ZT_SIG_DACS		((1 << 16))

#define ZT_SIG_CLEAR		((1 <<  7))	/* Clear channel */
#define ZT_SIG_HDLCRAW		((1 <<  8) | ZT_SIG_CLEAR)	/* Raw unchecked HDLC */
#define ZT_SIG_HDLCFCS		((1 <<  9) | ZT_SIG_HDLCRAW)	/* HDLC with FCS calculation */
#define ZT_SIG_HDLCNET		((1 << 10) | ZT_SIG_HDLCFCS)	/* HDLC Network */
#define ZT_SIG_SLAVE		((1 << 11))	/* Slave to another channel */
#define ZT_SIG_SF		((1 << 14))	/* Single Freq. tone only, no sig bits */
#define ZT_SIG_CAS		((1 << 15))	/* Just get bits */
#define ZT_SIG_DACS		(__ZT_SIG_DACS | ZT_SIG_CLEAR)	/* Cross connect */
#define ZT_SIG_EM_E1		((1 << 17))	/* E1 E&M Variation */
#define ZT_SIG_DACS_RBS		((1 << 18) | __ZT_SIG_DACS)	/* Cross connect w/ RBS */

/* tone flag values */
#define ZT_REVERSE_RXTONE	1	/* reverse polarity rx tone logic */
#define ZT_REVERSE_TXTONE	2	/* reverse polarity tx tone logic */

#define ZT_ABIT			8
#define ZT_BBIT			4
#define ZT_CBIT			2
#define ZT_DBIT			1

#define ZT_MAJOR		  196

#define ZT_CODE			'J'

/* Default chunk size for conferences and such -- static right now, might make variable sometime. 8
   samples = 1 ms = most frequent service interval possible for a USB device */
#define ZT_CHUNKSIZE		    8
#define ZT_MIN_CHUNKSIZE	 ZT_CHUNKSIZE
#define ZT_DEFAULT_CHUNKSIZE	 ZT_CHUNKSIZE
#define ZT_MAX_CHUNKSIZE 	 ZT_CHUNKSIZE
#define ZT_CB_SIZE		    2

#define ZT_MAX_BLOCKSIZE 	 8192
#define ZT_DEFAULT_NUM_BUFS	    2
#define ZT_MAX_NUM_BUFS		   32
#define ZT_MAX_BUF_SPACE	32768

#define ZT_DEFAULT_BLOCKSIZE	 1024
#define ZT_DEFAULT_MTR_MRU	 2048

#define ZT_POLICY_IMMEDIATE	    0	/* Start play/record immediately */
#define ZT_POLICY_WHEN_FULL	    1	/* Start play/record when buffer is full */

#define RING_DEBOUNCE_TIME	 2000	/* 2000 ms ring debounce time */

#define ZT_GET_PARAMS_RETURN_MASTER 0x40000000

typedef struct zt_params {
	int channo;			/* Channel number */
	int spanno;			/* Span itself */
	int chanpos;			/* Channel number in span */
	int sigtype;			/* read-only */
	int sigcap;			/* read-only */
	int rxisoffhook;		/* read-only */
	int rxbits;			/* read-only */
	int txbits;			/* read-only */
	int txhooksig;			/* read-only */
	int rxhooksig;			/* read-only */
	int curlaw;			/* read-only -- one of ZT_LAW_MULAW or ZT_LAW_ALAW */
	int idlebits;			/* read-only -- What is considered the idle state */
	char name[40];			/* Name of channel */
	int prewinktime;
	int preflashtime;
	int winktime;
	int flashtime;
	int starttime;
	int rxwinktime;
	int rxflashtime;
	int debouncetime;
	int pulsebreaktime;
	int pulsemaketime;
	int pulseaftertime;
} ZT_PARAMS;

typedef struct zt_spaninfo {
	int spanno;			/* span number (or -1 to use name) */
	char name[20];			/* Name of span */
	char desc[40];			/* Description of span */
	int alarms;			/* alarms status */
	int txlevel;			/* what TX level is set to */
	int rxlevel;			/* current RX level */
	int bpvcount;			/* current BPV count */
	int crc4count;			/* current CRC4 error count */
	int ebitcount;			/* current E-bit error count */
	int fascount;			/* current FAS error count */
	int irqmisses;			/* current IRQ misses */
	int syncsrc;			/* span # of current sync source, or 0 for free run */
	int numchans;			/* number of configured channels on this span */
	int totalchans;			/* total number of channels on the span */
	int totalspans;			/* total number of zaptel spans in entire system */
} ZT_SPANINFO;

typedef struct zt_maintinfo {
	int spanno;			/* span number 1-2 */
	int command;			/* command */
} ZT_MAINTINFO;

typedef struct zt_confinfo {
	int chan;			/* channel number, 0 for current */
	int confno;			/* conference number */
	int confmode;			/* conferencing mode */
} ZT_CONFINFO;

typedef struct zt_gains {
	int chan;			/* channel number, 0 for current */
	unsigned char rxgain[256];	/* Receive gain table */
	unsigned char txgain[256];	/* Transmit gain table */
} ZT_GAINS;

typedef struct zt_lineconfig {
	int span;			/* Which span number (0 to use name) */
	char name[20];			/* Name of span to use */
	int lbo;			/* line build-outs */
	int lineconfig;			/* line config parameters (framing, coding) */
	int sync;			/* what level of sync source we are */
} ZT_LINECONFIG;

typedef struct zt_chanconfig {
	int chan;			/* Channel we're applying this to (0 to use name) */
	char name[40];			/* Name of channel to use */
	int sigtype;			/* Signal type */
	int deflaw;			/* Default law (ZT_LAW_DEFAULT, ZT_LAW_MULAW, or
					   ZT_LAW_ALAW */
	int master;			/* Master channel if sigtype is ZT_SLAVE */
	int idlebits;			/* Idle bits (if this is a CAS channel) or channel to
					   monitor (if this is DACS channel) */
} ZT_CHANCONFIG;

typedef struct zt_sfconfig {
	int chan;			/* Channel we're applying this to (0 to use name) */
	char name[40];			/* Name of channel to use */
	long rxp1;			/* receive tone det. p1 */
	long rxp2;			/* receive tone det. p2 */
	long rxp3;			/* receive tone det. p3 */
	int txtone;			/* Tx tone factor */
	int tx_v2;			/* initial v2 value */
	int tx_v3;			/* initial v3 value */
	int toneflag;			/* Tone flags */
} ZT_SFCONFIG;

typedef struct zt_bufferinfo {
	int txbufpolicy;		/* Policy for handling receive buffers */
	int rxbufpolicy;		/* Policy for handling receive buffers */
	int numbufs;			/* How many buffers to use */
	int bufsize;			/* How big each buffer is */
	int readbufs;			/* How many read buffers are full (read-only) */
	int writebufs;			/* How many write buffers are full (read-only) */
} ZT_BUFFERINFO;

typedef struct zt_dialparams {
	int mfv1_tonelen;		/* MF tone length (KP = this * 5/3) */
	int dtmf_tonelen;		/* DTMF tone length */
	int reserved[4];		/* Reserved for future expansion -- always set to 0 */
} ZT_DIAL_PARAMS;

typedef struct zt_dynamic_span {
	char driver[20];		/* Which low-level driver to use */
	char addr[40];			/* Destination address */
	int numchans;			/* Number of channels */
	int timing;			/* Timing source preference */
	int spanno;			/* Span number (filled in by zaptel) */
} ZT_DYNAMIC_SPAN;

/* Define the max # of outgoing DTMF or MFv1 digits to queue in-kernel */
#define ZT_MAX_DTMF_BUF 256

#define ZT_DIAL_OP_APPEND	1
#define ZT_DIAL_OP_REPLACE	2
#define ZT_DIAL_OP_CANCEL	3

#define ZT_LAW_DEFAULT	0	/* Default law for span */
#define ZT_LAW_MULAW	1	/* Mu-law */
#define ZT_LAW_ALAW	2	/* A-law */

typedef struct zt_dialoperation {
	int op;
	char dialstr[ZT_MAX_DTMF_BUF];
} ZT_DIAL_OPERATION;

typedef struct zt_indirect_data {
	int chan;
	int op;
	void *data;
} ZT_INDIRECT_DATA;

/* ioctl definitions */
#define ZT_CODE		'J'

#define ZT_GET_BLOCKSIZE	_IOR  (ZT_CODE,  1, int)	/* Get Transfer Block Size.  */
#define ZT_SET_BLOCKSIZE	_IOW  (ZT_CODE,  2, int)	/* Set Transfer Block Size.  */
#define ZT_FLUSH		_IOW  (ZT_CODE,  3, int)	/* Flush Buffer(s) and stop I/O */
#define ZT_SYNC			_IOW  (ZT_CODE,  4, int)	/* Wait for Write to Finish */
#define ZT_GET_PARAMS		_IOR  (ZT_CODE,  5, struct zt_params)	/* Get channel parameters */
#define ZT_SET_PARAMS		_IOW  (ZT_CODE,  6, struct zt_params)	/* Get channel parameters */
#define ZT_HOOK			_IOW  (ZT_CODE,  7, int)	/* Set Hookswitch Status */
#define ZT_GETEVENT		_IOR  (ZT_CODE,  8, int)	/* Get Signalling Event */
#define ZT_IOMUX		_IOWR (ZT_CODE,  9, int)	/* Wait for something to happen (IO
								   Mux) */
#define ZT_SPANSTAT		_IOWR (ZT_CODE, 10, struct zt_spaninfo)	/* Get Span Status */
#define ZT_MAINT		_IOW  (ZT_CODE, 11, struct zt_maintinfo)	/* Set Maintenance
										   Mode */
#define ZT_GETCONF		_IOWR (ZT_CODE, 12, struct zt_confinfo)	/* Get Conference Mode */
#define ZT_SETCONF		_IOWR (ZT_CODE, 13, struct zt_confinfo)	/* Set Conference Mode */
#define ZT_CONFLINK		_IOW  (ZT_CODE, 14, struct zt_confinfo)	/* Setup or Remove
									   Conference Link */
#define ZT_CONFDIAG		_IOR  (ZT_CODE, 15, int)	/* Display Conference Diagnostic
								   Information on Console */
#define ZT_GETGAINS		_IOWR (ZT_CODE, 16, struct zt_gains)	/* Get Channel audio gains */
#define ZT_SETGAINS		_IOWR (ZT_CODE, 17, struct zt_gains)	/* Set Channel audio gains */
#define ZT_SPANCONFIG		_IOW  (ZT_CODE, 18, struct zt_lineconfig)	/* Set Line (T1)
										   Configurations
										   and start system
										 */
#define ZT_CHANCONFIG		_IOW  (ZT_CODE, 19, struct zt_chanconfig)	/* Set Channel
										   Configuration */
#define ZT_CONFMUTE		_IOW  (ZT_CODE, 20, int)	/* Set Conference to mute mode */
#define ZT_SENDTONE		_IOW  (ZT_CODE, 21, int)	/* Send a particular tone (see
								   ZT_TONE_*) */
#define ZT_SETTONEZONE		_IOW  (ZT_CODE, 22, int)	/* Set your region for tones (see
								   ZT_TONE_ZONE_*) */
#define ZT_GETTONEZONE		_IOR  (ZT_CODE, 23, int)	/* Retrieve current region for
								   tones (see ZT_TONE_ZONE_*) */
#define ZT_DEFAULTZONE		_IOW  (ZT_CODE, 24, int)	/* Master unit only -- set default
								   zone (see ZT_TONE_ZONE_*) */
#define ZT_LOADZONE		_IOW  (ZT_CODE, 25, struct zt_tone_def_header)	/* Load a tone zone
										   from a
										   ZT_tone_def_header,
										   see below...  */
#define ZT_FREEZONE		_IOW  (ZT_CODE, 26, int)	/* Free a tone zone */
#define ZT_SET_BUFINFO		_IOW  (ZT_CODE, 27, struct zt_bufferinfo)	/* Set buffer
										   policy */
#define ZT_GET_BUFINFO		_IOR  (ZT_CODE, 28, struct zt_bufferinfo)	/* Get current
										   buffer info */
#define ZT_GET_DIALPARAMS	_IOR  (ZT_CODE, 29, struct zt_dialparams)	/* Get dialing
										   parameters */
#define ZT_SET_DIALPARAMS	_IOW  (ZT_CODE, 30, struct zt_dialparams)	/* Set dialing
										   parameters */
#define ZT_DIAL			_IOW  (ZT_CODE, 31, struct zt_dialoperation)	/* Append, replace,
										   or cancel a dial
										   string */
#define ZT_AUDIOMODE		_IOW  (ZT_CODE, 32, int)	/* Set a clear channel into audio
								   mode */
#define ZT_ECHOCANCEL		_IOW  (ZT_CODE, 33, int)	/* Enable or disable echo
								   cancellation on a channel The
								   number is zero to disable echo
								   cancellation and non-zero to
								   enable echo cancellation.  If
								   the number is between 32 and
								   256, it will also set the number
								   of taps in the echo canceller */
#define ZT_CHANNO		_IOR  (ZT_CODE, 34, int)	/* Return a channel's channel
								   number (useful for the
								   /dev/zap/pseudo type interfaces */
#define ZT_DIALING		_IOR  (ZT_CODE, 35, int)	/* Return a flag indicating whether
								   channel is currently dialing */

/* Numbers 60 to 90 are reserved for private use of low level hardware drivers */

#define ZT_HDLCRAWMODE		_IOW  (ZT_CODE, 36, int)	/* Set a clear channel into HDLC
								   w/out FCS checking/calculation
								   mode */
#define ZT_HDLCFCSMODE		_IOW  (ZT_CODE, 37, int)	/* Set a clear channel into HDLC w/
								   FCS mode */
#define ZT_SPECIFY		_IOW  (ZT_CODE, 38, int)	/* Specify a channel on
								   /dev/zap/chan -- must be done
								   before any other ioctl's and is
								   only valid on /dev/zap/chan */
#define ZT_SETLAW		_IOW  (ZT_CODE, 39, int)	/* Temporarily set the law on a
								   channel to ZT_LAW_DEFAULT,
								   ZT_LAW_ALAW, or ZT_LAW_MULAW. Is
								   reset on close.  */
#define ZT_SETLINEAR		_IOW  (ZT_CODE, 40, int)	/* Temporarily set the channel to
								   operate in linear mode when
								   non-zero or default law if 0 */
#define ZT_HDLCPPP		_IOW  (ZT_CODE, 41, int)	/* Set a clear channel into HDLC w/
								   PPP interface mode */
#define ZT_SETCADENCE		_IOW  (ZT_CODE, 42, struct zt_ring_cadence)	/* Set the ring
										   cadence for FXS
										   interfaces */
#define ZT_SETTXBITS		_IOW  (ZT_CODE, 43, int)	/* Set the bits going out for CAS
								   interface */
#define ZT_CHANDIAG		_IOR  (ZT_CODE, 44, int)	/* Display Channel Diagnostic
								   Information on Console */
#define ZT_GETRXBITS		_IOR  (ZT_CODE, 45, int)	/* Obtain received signalling */
#define ZT_SFCONFIG		_IOW  (ZT_CODE, 46, struct zt_sfconfig)	/* Set Channel's SF Tone
									   Configuration */
#define ZT_TIMERCONFIG		_IOW  (ZT_CODE, 47, int)	/* Set timer expiration (in
								   samples) */
#define ZT_TIMERACK		_IOW  (ZT_CODE, 48, int)	/* Acknowledge timer expiration
								   (number to acknowledge, or -1
								   for all) */
#define ZT_GETCONFMUTE		_IOR  (ZT_CODE, 49, int)	/* Get Conference to mute mode */
#define ZT_ECHOTRAIN		_IOW  (ZT_CODE, 50, int)	/* Request echo training in some
								   number of ms (with muting in the
								   mean time) */
#define ZT_ONHOOKTRANSFER	_IOW  (ZT_CODE, 51, int)	/* Set on hook transfer for n
								   number of ms -- implemnted by
								   low level driver */
#define ZT_TIMERPING		_IOW  (ZT_CODE, 42, int)	/* Should be 52, but works */	/* Queue
												   Ping */
#define ZT_TIMERPONG		_IOW  (ZT_CODE, 53, int)	/* Acknowledge ping */
#define ZT_SIGFREEZE		_IOW  (ZT_CODE, 54, int)	/* Set/get signalling freeze */
#define ZT_GETSIGFREEZE		_IOR  (ZT_CODE, 55, int)	/* Set/get signalling freeze */
#define ZT_INDIRECT		_IOWR (ZT_CODE, 56, struct zt_indirect_data)	/* Do a channel
										   IOCTL from the
										   /dev/zap/ctl
										   interface */

/*
 *  60-80 are reserved for private drivers
 *  80-85 are reserved for dynamic span stuff
 */

#define ZT_DYNAMIC_CREATE	_IOWR (ZT_CODE, 80, struct zt_dynamic_span)	/* Create a dynamic
										   span */
#define ZT_DYNAMIC_DESTROY	_IOW (ZT_CODE, 81, struct zt_dynamic_span)	/* Destroy a
										   dynamic span */
#define ZT_TONEDETECT		_IOW (ZT_CODE, 91, int)	/* Enable tone detection -- implemented by
							   low level driver */
#define ZT_SETPOLARITY		_IOW (ZT_CODE, 92, int)	/* Set polarity -- implemented by
							   individual driver.  0 = forward, 1 =
							   reverse */
#define ZT_STARTUP		_IOW (ZT_CODE, 99, int)	/* Startup or Shutdown a span */
#define ZT_SHUTDOWN		_IOW (ZT_CODE, 100, int)	/* Startup or Shutdown a span */

#define ZT_TONE_ZONE_MAX	128
#define ZT_TONE_ZONE_DEFAULT 	-1	/* To restore default */

#define ZT_TONE_STOP		-1
#define ZT_TONE_DIALTONE	 0
#define ZT_TONE_BUSY		 1
#define ZT_TONE_RINGTONE	 2
#define ZT_TONE_CONGESTION	 3
#define ZT_TONE_CALLWAIT	 4
#define ZT_TONE_DIALRECALL	 5
#define ZT_TONE_RECORDTONE	 6
#define ZT_TONE_INFO		 7
#define ZT_TONE_CUST1		 8
#define ZT_TONE_CUST2		 9
#define ZT_TONE_STUTTER		10
#define ZT_TONE_MAX		16

#define ZT_MAX_CADENCE		16

#define ZT_TONEDETECT_ON	(1 << 0)	/* Detect tones */
#define ZT_TONEDETECT_MUTE	(1 << 1)	/* Mute audio in received channel */

struct zt_ring_cadence {
	int ringcadence[ZT_MAX_CADENCE];
};

struct zt_tone_def_header {
	int count;			/* How many samples follow */
	int zone;			/* Which zone we are loading */
	int ringcadence[ZT_MAX_CADENCE];	/* Ring cadence in ms (0=on, 1=off, ends with 0
						   value) */
	char name[40];			/* Informational name of zone */
	/* Immediately follow the ZT_tone_def_header by ZT_tone_def's */
};

struct zt_tone_def {			/* Structure for zone programming */
	int tone;			/* See ZT_TONE_* */
	int next;			/* What the next position in the cadence is (They're
					   numbered by the order the appear here) */
	int samples;			/* How many samples to play for this cadence */
	/* Now come the constants we need to make tones */
	int shift;			/* How much to scale down the volume (2 is nice) */

	/*
	   Calculate the next 6 factors using the following equations: l = <level in dbm>, f1 =
	   <freq1>, f2 = <freq2> gain = pow(10.0, (l - 3.14) / 20.0) * 65536.0 / 2.0;

	   // Frequency factor 1 fac_1 = 2.0 * cos(2.0 * M_PI * (f1/8000.0)) * 32768.0; // Last
	   previous two samples init_v2_1 = sin(-4.0 * M_PI * (f1/8000.0)) * gain; init_v3_1 =
	   sin(-2.0 * M_PI * (f1/8000.0)) * gain;

	   // Frequency factor 2 fac_2 = 2.0 * cos(2.0 * M_PI * (f2/8000.0)) * 32768.0; // Last
	   previous two samples init_v2_2 = sin(-4.0 * M_PI * (f2/8000.0)) * gain; init_v3_2 =
	   sin(-2.0 * M_PI * (f2/8000.0)) * gain; */
	int fac1;
	int init_v2_1;
	int init_v3_1;
	int fac2;
	int init_v2_2;
	int init_v3_2;
	int modulate;

};

#define ZT_MAX_BLOCKSIZE	8192	/* Define the maximum block size */
#define ZT_DEFAULT_MTU_MRU	2048	/* Define the default network block size */

#define ZT_FLUSH_READ		 1	/* Flush and stop the read (input) process */
#define ZT_FLUSH_WRITE		 2	/* Flush and stop the write (output) process */
#define ZT_FLUSH_BOTH		(ZT_FLUSH_READ | ZT_FLUSH_WRITE)	/* Flush and stop both
									   (input and output)
									   processes */
#define ZT_FLUSH_EVENT		 4	/* Flush the event queue */
#define ZT_FLUSH_ALL		(ZT_FLUSH_READ | ZT_FLUSH_WRITE | ZT_FLUSH_EVENT)	/* Flush
											   everything
											 */

#define ZT_ONHOOK		 0	/* Value for ZT_HOOK, set to ON hook */
#define ZT_OFFHOOK		 1	/* Value for ZT_HOOK, set to OFF hook */
#define ZT_WINK			 2	/* Value for ZT_HOOK, wink (off hook momentarily) */
#define ZT_FLASH		 3	/* Value for ZT_HOOK, flash (on hook momentarily) */
#define ZT_START		 4	/* Value for ZT_HOOK, start line */
#define ZT_RING			 5	/* Value for ZT_HOOK, ring line (same as start line) */
#define ZT_RINGOFF		 6	/* Value for ZT_HOOK, turn ringer off */

#define ZT_EVENT_NONE		 0	/* Ret. Value for GET/WAIT Event, no event */
#define ZT_EVENT_ONHOOK		 1	/* Ret. Value for GET/WAIT Event, Went Onhook */
#define ZT_EVENT_RINGOFFHOOK	 2	/* Ret. Value for GET/WAIT Event, Went Offhook or got Ring */
#define ZT_EVENT_WINKFLASH	 3	/* Ret. Value for GET/WAIT Event, Got Wink or Flash */
#define ZT_EVENT_ALARM		 4	/* Ret. Value for GET/WAIT Event, Got Alarm */
#define ZT_EVENT_NOALARM	 5	/* Ret. Value for GET/WAIT Event, Got No Alarm (after
					   alarm) */
#define ZT_EVENT_ABORT		 6	/* Ret. Value for GET/WAIT Event, HDLC Abort frame */
#define ZT_EVENT_OVERRUN	 7	/* Ret. Value for GET/WAIT Event, HDLC Frame overrun */
#define ZT_EVENT_BADFCS		 8	/* Ret. Value for GET/WAIT Event, Bad FCS */
#define ZT_EVENT_DIALCOMPLETE	 9	/* Ret. Value for dial complete */
#define ZT_EVENT_RINGERON	10	/* Ret Value for ringer going on */
#define ZT_EVENT_RINGEROFF	11	/* Ret Value for ringer going off */
#define ZT_EVENT_HOOKCOMPLETE	12	/* Ret Value for hook change complete */
#define ZT_EVENT_BITSCHANGED	13	/* Ret Value for bits changing on a CAS / User channel */
#define ZT_EVENT_PULSE_START	14	/* Ret value for the beginning of a pulse coming on its way
					 */
#define ZT_EVENT_TIMER_EXPIRED	15	/* Timer event -- timer expired */
#define ZT_EVENT_TIMER_PING	16	/* Timer event -- ping ready */
#define ZT_EVENT_POLARITY	17	/* Polarity reversal event */
#define ZT_EVENT_RINGBEGIN	18	/* Ring Begin event */

#define ZT_EVENT_PULSEDIGIT	(1 << 16)	/* This is OR'd with the digit received */
#define ZT_EVENT_DTMFDOWN	(1 << 17)	/* Ditto for DTMF key down event */
#define ZT_EVENT_DTMFUP		(1 << 18)	/* Ditto for DTMF key up event */

#define ZT_IOMUX_READ		1	/* Flag Value for IOMUX, read avail */
#define ZT_IOMUX_WRITE		2	/* Flag Value for IOMUX, write avail */
#define ZT_IOMUX_WRITEEMPTY	4	/* Flag Value for IOMUX, write done */
#define ZT_IOMUX_SIGEVENT	8	/* Flag Value for IOMUX, signalling event avail */

/* Flag Value for IOMUX, Do Not Wait if nothing to report */
#define ZT_IOMUX_NOWAIT		0x100

/* Alarm Condition bits */
#define ZT_ALARM_NONE		0	/* No alarms */
#define ZT_ALARM_RECOVER	1	/* Recovering from alarm */
#define ZT_ALARM_LOOPBACK	2	/* In loopback */
#define ZT_ALARM_YELLOW		4	/* Yellow Alarm */
#define ZT_ALARM_RED		8	/* Red Alarm */
#define ZT_ALARM_BLUE		16	/* Blue Alarm */
#define ZT_ALARM_NOTOPEN	32
/* Maintenance modes */
#define ZT_MAINT_NONE		0	/* Normal Mode */
#define ZT_MAINT_LOCALLOOP	1	/* Local Loopback */
#define ZT_MAINT_REMOTELOOP	2	/* Remote Loopback */
#define ZT_MAINT_LOOPUP		3	/* send loopup code */
#define ZT_MAINT_LOOPDOWN	4	/* send loopdown code */
#define ZT_MAINT_LOOPSTOP	5	/* stop sending loop codes */

/* Conference modes */
#define ZT_CONF_MODE_MASK	0xff	/* mask for modes */
#define ZT_CONF_NORMAL		0	/* normal mode */
#define ZT_CONF_MONITOR		1	/* monitor mode (rx of other chan) */
#define ZT_CONF_MONITORTX	2	/* monitor mode (tx of other chan) */
#define ZT_CONF_MONITORBOTH	3	/* monitor mode (rx & tx of other chan) */
#define ZT_CONF_CONF		4	/* conference mode */
#define ZT_CONF_CONFANN		5	/* conference announce mode */
#define ZT_CONF_CONFMON		6	/* conference monitor mode */
#define ZT_CONF_CONFANNMON	7	/* conference announce/monitor mode */
#define ZT_CONF_REALANDPSEUDO	8	/* real and pseudo port both on conf */
#define ZT_CONF_DIGITALMON	9	/* Do not decode or interpret */
#define ZT_CONF_FLAG_MASK	0xff00	/* mask for flags */
#define ZT_CONF_LISTENER	0x100	/* is a listener on the conference */
#define ZT_CONF_TALKER		0x200	/* is a talker on the conference */
#define ZT_CONF_PSEUDO_LISTENER	0x400	/* pseudo is a listener on the conference */
#define ZT_CONF_PSEUDO_TALKER	0x800	/* pseudo is a talker on the conference */

#define ZT_DEFAULT_WINKTIME	 150	/* 150 ms default wink time */
#define ZT_DEFAULT_FLASHTIME	 750	/* 750 ms default flash time */

#define ZT_DEFAULT_PREWINKTIME	  50	/* 50 ms before wink */
#define ZT_DEFAULT_PREFLASHTIME	  50	/* 50 ms before flash */
#define ZT_DEFAULT_STARTTIME	1500	/* 1500 ms of start */
#define ZT_DEFAULT_RINGTIME	2000	/* 2000 ms of ring on (start, FXO) */
#if 0
#define ZT_DEFAULT_RXWINKTIME 250	/* 250ms longest rx wink */
#endif
#define ZT_DEFAULT_RXWINKTIME		 300	/* 300ms longest rx wink (to work with the Atlas) */
#define ZT_DEFAULT_RXFLASHTIME		1250	/* 1250ms longest rx flash */
#define ZT_DEFAULT_DEBOUNCETIME		 600	/* 600ms of FXS GS signalling debounce */
#define ZT_DEFAULT_PULSEMAKETIME	  50	/* 50 ms of line closed when dial pulsing */
#define ZT_DEFAULT_PULSEBREAKTIME	  50	/* 50 ms of line open when dial pulsing */
#define ZT_DEFAULT_PULSEAFTERTIME	 750	/* 750ms between dial pulse digits */

#define ZT_MINPULSETIME		(15 * 8)	/* 15 ms minimum */
#define ZT_MAXPULSETIME		(200 * 8)	/* 200 ms maximum */
#define ZT_PULSETIMEOUT		((ZT_MAXPULSETIME / 8) + 50)

#define ZT_RINGTRAILER		(50 * 8)	/* Don't consider a ring "over" until it's been
						   gone at least this much time */

#define ZT_LOOPCODE_TIME	10000	/* send loop codes for 10 secs */
#define ZT_ALARMSETTLE_TIME	 5000	/* allow alarms to settle for 5 secs */
#define ZT_AFTERSTART_TIME	  500	/* 500ms after start */

#define ZT_RINGOFFTIME		 4000	/* Turn off ringer for 4000 ms */
#define ZT_KEWLTIME		  500	/* 500ms for kewl pulse */
#define ZT_AFTERKEWLTIME	  300	/* 300ms after kewl pulse */

#define ZT_MAX_PRETRAINING	 1000	/* 1000ms max pretraining time */

#define ZT_MAX_SPANS		  128	/* Max, 128 spans */
#define ZT_MAX_CHANNELS		 1024	/* Max, 1024 channels */
#define ZT_MAX_CONF		 1024	/* Max, 1024 conferences */

#ifdef	FXSFLASH
#define ZT_FXSFLASHMINTIME	  450	/* min 450ms */
#define ZT_FXSFLASHMAXTIME	  550	/* max 550ms */
#endif				/* FXSFLASH */

#define ZT_MAX_EVENTSIZE	   64	/* 64 events max in buffer */

struct zt_span;
struct zt_chan;

struct zt_tone_state {
	int v1_1;
	int v2_1;
	int v3_1;
	int v1_2;
	int v2_2;
	int v3_2;
	int modulate;
};

#ifdef CONFIG_ZAPATA_NET
struct zt_hdlc {
#ifdef LINUX26
	struct net_device *netdev;
#else					/* LINUX26 */
	hdlc_device netdev;
#endif					/* LINUX26 */
	struct zt_chan *chan;
};
#endif				/* CONFIG_ZAPATA_NET */

/* Conference queue stucture */
struct confq {
	u_char buffer[ZT_CHUNKSIZE * ZT_CB_SIZE];
	u_char *buf[ZT_CB_SIZE];
	int inbuf;
	int outbuf;
};

typedef struct {
	long x1;
	long x2;
	long y1;
	long y2;
	long e1;
	long e2;
	int samps;
	int lastdetect;
} sf_detect_state_t;

struct zt_chan {
#ifdef CONFIG_ZAPATA_NET
	/* Must be first */
	struct zt_hdlc *hdlcnetdev;
#endif					/* CONFIG_ZAPATA_NET */
#ifdef CONFIG_ZAPATA_PPP
	struct ppp_channel *ppp;
	struct tasklet_struct ppp_calls;
	int do_ppp_wakeup;
	int do_ppp_error;
	struct sk_buff_head ppp_rq;
#endif					/* CONFIG_ZAPATA_PPP */
	spinlock_t lock;
	char name[40];			/* Name */
	/* Specified by zaptel */
	int channo;			/* Zaptel Channel number */
	int chanpos;
	int flags;
	long rxp1;
	long rxp2;
	long rxp3;
	int txtone;
	int tx_v2;
	int tx_v3;
	int v1_1;
	int v2_1;
	int v3_1;
	int toneflags;
	sf_detect_state_t rd;

	struct zt_chan *master;		/* Our Master channel (could be us) */
	/* Next slave (if appropriate) */
	int nextslave;

	u_char *writechunk;		/* Actual place to write to */
	u_char swritechunk[ZT_MAX_CHUNKSIZE];	/* Buffer to be written */
	u_char *readchunk;		/* Actual place to read from */
	u_char sreadchunk[ZT_MAX_CHUNKSIZE];	/* Preallocated static area */

	/* Pointer to tx and rx gain tables */
	u_char *rxgain;
	u_char *txgain;

	/* Whether or not we have allocated gains or are using the default */
	int gainalloc;

	/* Specified by driver, readable by zaptel */
	void *pvt;			/* Private channel data */
	struct file *file;		/* File structure */

	struct zt_span *span;		/* Span we're a member of */
	int sig;			/* Signalling */
	int sigcap;			/* Capability for signalling */

	/* Used only by zaptel -- NO DRIVER SERVICEABLE PARTS BELOW */
	/* Buffer declarations */
	u_char *readbuf[ZT_MAX_NUM_BUFS];	/* read buffer */
	int inreadbuf;
	int outreadbuf;
	wait_queue_head_t readbufq;	/* read wait queue */

	u_char *writebuf[ZT_MAX_NUM_BUFS];	/* write buffers */
	int inwritebuf;
	int outwritebuf;
	wait_queue_head_t writebufq;	/* write wait queue */

	int blocksize;			/* Block size */

	int eventinidx;			/* out index in event buf (circular) */
	int eventoutidx;		/* in index in event buf (circular) */
	unsigned int eventbuf[ZT_MAX_EVENTSIZE];	/* event circ. buffer */
	wait_queue_head_t eventbufq;	/* event wait queue */

	wait_queue_head_t txstateq;	/* waiting on the tx state to change */

	int readn[ZT_MAX_NUM_BUFS];	/* # of bytes ready in read buf */
	int readidx[ZT_MAX_NUM_BUFS];	/* current read pointer */
	int writen[ZT_MAX_NUM_BUFS];	/* # of bytes ready in write buf */
	int writeidx[ZT_MAX_NUM_BUFS];	/* current write pointer */

	int numbufs;			/* How many buffers in channel */
	int txbufpolicy;		/* Buffer policy */
	int rxbufpolicy;		/* Buffer policy */
	int txdisable;			/* Disable transmitter */
	int rxdisable;			/* Disable receiver */

	/* Tone zone stuff */
	struct zt_zone *curzone;	/* Zone for selecting tones */
	int tonezone;			/* Tone zone for this channel */
	struct zt_tone *curtone;	/* Current tone we're playing (if any) */
	int tonep;			/* Current position in tone */
	struct zt_tone_state ts;	/* Tone state */

	/* Pulse dial stuff */
	int pdialcount;			/* pulse dial count */

	/* Ring cadence */
	int ringcadence[ZT_MAX_CADENCE];
	int firstcadencepos;		/* Where to restart ring cadence */

	/* Digit string dialing stuff */
	int digitmode;			/* What kind of tones are we sending? */
	char txdialbuf[ZT_MAX_DTMF_BUF];
	int dialing;
	int afterdialingtimer;
	int cadencepos;			/* Where in the cadence we are */

	/* I/O Mask */
	int iomask;			/* I/O Mux signal mask */
	wait_queue_head_t sel;		/* thingy for select stuff */

	/* HDLC state machines */
	struct fasthdlc_state txhdlc;
	struct fasthdlc_state rxhdlc;
	int infcs;

	/* Conferencing stuff */
	int confna;			/* conference number (alias) */
	int _confn;			/* Actual conference number */
	int confmode;			/* conference mode */
	int confmute;			/* conference mute mode */

	/* Incoming and outgoing conference chunk queues for communicating between zaptel master
	   time and other boards */
	struct confq confin;
	struct confq confout;

	short getlin[ZT_MAX_CHUNKSIZE];	/* Last transmitted samples */
	unsigned char getraw[ZT_MAX_CHUNKSIZE];	/* Last received raw data */
	short getlin_lastchunk[ZT_MAX_CHUNKSIZE];	/* Last transmitted samples from last chunk
							 */
	short putlin[ZT_MAX_CHUNKSIZE];	/* Last received samples */
	unsigned char putraw[ZT_MAX_CHUNKSIZE];	/* Last received raw data */
	short conflast[ZT_MAX_CHUNKSIZE];	/* Last conference sample -- base part of channel */
	short conflast1[ZT_MAX_CHUNKSIZE];	/* Last conference sample -- pseudo part of channel
						 */
	short conflast2[ZT_MAX_CHUNKSIZE];	/* Previous last conference sample -- pseudo part
						   of channel */

	/* Is echo cancellation enabled or disabled */
	int echocancel;
	echo_can_state_t *ec;
	echo_can_disable_detector_state_t txecdis;
	echo_can_disable_detector_state_t rxecdis;

	int echostate;			/* State of echo canceller */
	int echolastupdate;		/* Last echo can update pos */
	int echotimer;			/* Timer for echo update */

	/* RBS timings */
	int prewinktime;		/* pre-wink time (ms) */
	int preflashtime;		/* pre-flash time (ms) */
	int winktime;			/* wink time (ms) */
	int flashtime;			/* flash time (ms) */
	int starttime;			/* start time (ms) */
	int rxwinktime;			/* rx wink time (ms) */
	int rxflashtime;		/* rx flash time (ms) */
	int debouncetime;		/* FXS GS sig debounce time (ms) */
	int pulsebreaktime;		/* pulse line open time (ms) */
	int pulsemaketime;		/* pulse line closed time (ms) */
	int pulseaftertime;		/* pulse time between digits (ms) */

	/* RING debounce timer */
	int ringdebtimer;

	/* RING trailing detector to make sure a RING is really over */
	int ringtrailer;

	/* PULSE digit receiver stuff */
	int pulsecount;
	int pulsetimer;

	/* RBS timers */
	int itimerset;			/* what the itimer was set to last */
	int itimer;
	int otimer;

	/* RBS state */
	int gotgs;
	int txstate;
	int rxsig;
	int txsig;
	int rxsigstate;

	/* non-RBS rx state */
	int rxhooksig;
	int txhooksig;
	int kewlonhook;

	/* Idle signalling if CAS signalling */
	int idlebits;

	int deflaw;			/* 1 = mulaw, 2=alaw, 0=undefined */
	short *xlaw;
#ifdef CONFIG_CALC_XLAW
	unsigned char (*lineartoxlaw) (short a);
#else					/* CONFIG_CALC_XLAW */
	unsigned char *lin2x;
#endif					/* CONFIG_CALC_XLAW */

#ifdef CONFIG_DEVFS_FS
	devfs_handle_t fhandle;		/* File handle in devfs for the channel */
	devfs_handle_t fhandle_symlink;
#endif					/* CONFIG_DEVFS_FS */
};

/* defines for transmit signalling */
typedef enum {
	ZT_TXSIG_ONHOOK,		/* On hook */
	ZT_TXSIG_OFFHOOK,		/* Off hook */
	ZT_TXSIG_START,			/* Start / Ring */
	ZT_TXSIG_KEWL			/* Drop battery if possible */
} zt_txsig_t;

typedef enum {
	ZT_RXSIG_ONHOOK,
	ZT_RXSIG_OFFHOOK,
	ZT_RXSIG_START,
	ZT_RXSIG_RING,
	ZT_RXSIG_INITIAL
} zt_rxsig_t;

/* Span flags */
#define ZT_FLAG_REGISTERED		(1 <<  0)
#define ZT_FLAG_RUNNING			(1 <<  1)
#define ZT_FLAG_RBS			(1 << 12)	/* Span uses RBS signalling */

/* Channel flags */
#define ZT_FLAG_DTMFDECODE		(1 <<  2)	/* Channel supports native DTMF decode */
#define ZT_FLAG_MFDECODE		(1 <<  3)	/* Channel supports native MFr2 decode */
#define ZT_FLAG_ECHOCANCEL		(1 <<  4)	/* Channel supports native echo
							   cancellation */
#define ZT_FLAG_HDLC			(1 <<  5)	/* Perform HDLC */
#define ZT_FLAG_NETDEV			(1 <<  6)	/* Send to network */
#define ZT_FLAG_PSEUDO			(1 <<  7)	/* Pseudo channel */
#define ZT_FLAG_CLEAR			(1 <<  8)	/* Clear channel */
#define ZT_FLAG_AUDIO			(1 <<  9)	/* Audio mode channel */

#define ZT_FLAG_OPEN			(1 << 10)	/* Channel is open */
#define ZT_FLAG_FCS			(1 << 11)	/* Calculate FCS */
/* Reserve 12 for uniqueness with span flags */
#define ZT_FLAG_LINEAR			(1 << 13)	/* Talk to user space in linear */
#define ZT_FLAG_PPP			(1 << 14)	/* PPP is available */
#define ZT_FLAG_T1PPP			(1 << 15)
#define ZT_FLAG_SIGFREEZE		(1 << 16)	/* Freeze signalling */

struct zt_span {
	spinlock_t lock;
	void *pvt;			/* Private stuff */
	char name[40];			/* Span name */
	char desc[80];			/* Span description */
	int deflaw;			/* Default law (ZT_MULAW or ZT_ALAW) */
	int alarms;			/* Pending alarms on span */
	int flags;
	int irq;			/* IRQ for this span's hardware */
	int lbo;			/* Span Line-Buildout */
	int lineconfig;			/* Span line configuration */
	int linecompat;			/* Span line compatibility */
	int channels;			/* Number of channels in span */
	int txlevel;			/* Tx level */
	int rxlevel;			/* Rx level */
	int syncsrc;			/* current sync src (gets copied here) */
	unsigned int bpvcount;		/* BPV counter */
	unsigned int crc4count;		/* CRC4 error counter */
	unsigned int ebitcount;		/* current E-bit error count */
	unsigned int fascount;		/* current FAS error count */

	int maintstat;			/* Maintenance state */
	wait_queue_head_t maintq;	/* Maintenance queue */
	int mainttimer;			/* Maintenance timer */

	int irqmisses;			/* Interrupt misses */

	struct zt_chan *chans;		/* Member channel structures */

	/* ==== Span Callback Operations ==== */
	int (*setchunksize) (struct zt_span * span, int chunksize);	/* Req: Set the requested
									   chunk size.  This is the
									   unit in which you must
									   report results for
									   conferencing, etc */
	int (*spanconfig) (struct zt_span * span, struct zt_lineconfig * lc);	/* Opt: Configure
										   the span (if
										   appropriate) */
	int (*startup) (struct zt_span * span);	/* Opt: Start the span */
	int (*shutdown) (struct zt_span * span);	/* Opt: Shutdown the span */
	int (*maint) (struct zt_span * span, int mode);	/* Opt: Enable maintenance modes */

	/* ==== Channel Callback Operations ==== */
	int (*chanconfig) (struct zt_chan * chan, int sigtype);	/* Opt: Set signalling type (if
								   appropriate) */
	int (*open) (struct zt_chan * chan);	/* Opt: Prepare a channel for I/O */
	int (*close) (struct zt_chan * chan);	/* Opt: Close channel for I/O */
	int (*ioctl) (struct zt_chan * chan, unsigned int cmd, unsigned long data);	/* Opt:
											   IOCTL */
	int (*echocan) (struct zt_chan * chan, int ecval);	/* Opt: Native echo cancellation */

	/* Okay, now we get to the signalling.  You have several options: */

	/* Option 1: If you're a T1 like interface, you can just provide a rbsbits function and
	   we'll assert robbed bits for you.  Be sure to set the ZT_FLAG_RBS in this case.  */

	int (*rbsbits) (struct zt_chan * chan, int bits);	/* Opt: If the span uses A/B bits,
								   set them here */

	/* Option 2: If you don't know about sig bits, but do have their equivalents (i.e. you can
	   disconnect battery, detect off hook, generate ring, etc directly) then you can just
	   specify a sethook function, and we'll call you with appropriate hook states to set.
	   Still set the ZT_FLAG_RBS in this case as well */
	int (*hooksig) (struct zt_chan * chan, zt_txsig_t hookstate);

	/* Option 3: If you can't use sig bits, you can write a function which handles the
	   individual hook states */
	int (*sethook) (struct zt_chan * chan, int hookstate);

	/* Opt: Dacs the contents of chan2 into chan1 if possible */
	int (*dacs) (struct zt_chan * chan1, struct zt_chan * chan2);

	/* Used by zaptel only -- no user servicable parts inside */
	int spanno;			/* Span number for zaptel */
	int offset;			/* Offset within a given card */
	int lastalarms;			/* Previous alarms */

#ifdef CONFIG_DEVFS_FS
	devfs_handle_t dhandle;		/* Directory name */
#endif					/* CONFIG_DEVFS_FS */
	/* If the watchdog detects no received data, it will call the watchdog routine */
	int (*watchdog) (struct zt_span * span, int cause);
#ifdef CONFIG_ZAPTEL_WATCHDOG
	int watchcounter;
	int watchstate;
#endif					/* CONFIG_ZAPTEL_WATCHDOG */
};

#define ZT_WATCHDOG_NOINTS		(1 << 0)
#define ZT_WATCHDOG_INIT		1000

#define ZT_WATCHSTATE_UNKNOWN		0
#define ZT_WATCHSTATE_OK			1
#define ZT_WATCHSTATE_RECOVERING	2
#define ZT_WATCHSTATE_FAILED		3

struct zt_dynamic_driver {
	char name[20];			/* Driver name (e.g. Eth) */
	char desc[80];			/* Driver description */
	void *(*create) (struct zt_span * span, char *address);	/* Create a new transmission pipe */
	void (*destroy) (void *tpipe);	/* Destroy a created transmission pipe */
	int (*transmit) (void *tpipe, unsigned char *msg, int msglen);	/* Transmit a given message
									 */
	struct zt_dynamic_driver *next;
};

/* Receive a dynamic span message */
extern void zt_dynamic_receive(struct zt_span *span, unsigned char *msg, int msglen);

/* Register a dynamic driver */
extern int zt_dynamic_register(struct zt_dynamic_driver *driver);

/* Unregister a dynamic driver */
extern void zt_dynamic_unregister(struct zt_dynamic_driver *driver);

/* Receive on a span.  The zaptel interface will handle all the calculations for all member
   channels of the span, pulling the data from the readchunk buffer */
extern int zt_receive(struct zt_span *span);

/* Prepare writechunk buffers on all channels for this span */
extern int zt_transmit(struct zt_span *span);

/* Register a span.  Returns 0 on success, -1 on failure.  Pref-master is non-zero if we should
   have preference in being the master device */
extern int zt_register(struct zt_span *span, int prefmaster);

/* Unregister a span */
extern int zt_unregister(struct zt_span *span);

/* Gives a name to an LBO */
extern char *zt_lboname(int lbo);

/* Tell Zaptel about changes in received rbs bits */
extern void zt_rbsbits(struct zt_chan *chan, int bits);

/* Tell Zaptel abou changes in received signalling */
extern void zt_hooksig(struct zt_chan *chan, zt_rxsig_t rxsig);

/* Queue an event on a channel */
extern void zt_qevent_nolock(struct zt_chan *chan, int event);

/* Queue an event on a channel, locking it first */
extern void zt_qevent_lock(struct zt_chan *chan, int event);

/* Notify a change possible change in alarm status */
extern void zt_alarm_notify(struct zt_span *span);

/* Initialize a tone state */
extern void zt_init_tone_state(struct zt_tone_state *ts, struct zt_tone *zt);

/* Get a given DTMF or MF tone struct, suitable for zt_tone_nextsample.  Set 'mf' to 0 for DTMF or
   1 for MFv1 */
extern struct zt_tone *zt_dtmf_tone(char digit, int mf);

/* Echo cancel a receive and transmit chunk for a given channel.  This should be called by the
   low-level driver as close to the interface as possible.  ECHO CANCELLATION IS NO LONGER
   AUTOMATICALLY DONE AT THE ZAPTEL LEVEL. zt_ec_chunk will not echo cancel if it should not be
   doing so.  rxchunk is modified in-place */
extern void zt_ec_chunk(struct zt_chan *chan, unsigned char *rxchunk, const unsigned char *txchunk);
extern void zt_ec_span(struct zt_span *span);

/* Don't use these directly -- they're not guaranteed to be there. */
extern short __zt_mulaw[256];
extern short __zt_alaw[256];

#ifdef CONFIG_CALC_XLAW
extern u_char __zt_lineartoulaw(short a);
extern u_char __zt_lineartoalaw(short a);
#else				/* CONFIG_CALC_XLAW */
extern u_char __zt_lin2mu[16384];
extern u_char __zt_lin2a[16384];
#endif				/* CONFIG_CALC_XLAW */

/* Used by dynamic zaptel -- don't use directly */
extern void zt_set_dynamic_ioctl(int (*func) (unsigned int cmd, unsigned long data));

/* Used privately by zaptel.  Avoid touching directly */
struct zt_tone {
	int fac1;
	int init_v2_1;
	int init_v3_1;

	int fac2;
	int init_v2_2;
	int init_v3_2;

	int tonesamples;		/* How long to play this tone before going to the next (in
					   samples) */
	struct zt_tone *next;		/* Next tone in this sequence */

	int modulate;
};

static inline short
zt_tone_nextsample(struct zt_tone_state *ts, struct zt_tone *zt)
{
	/* follow the curves, return the sum */

	int p;

	ts->v1_1 = ts->v2_1;
	ts->v2_1 = ts->v3_1;
	ts->v3_1 = (zt->fac1 * ts->v2_1 >> 15) - ts->v1_1;

	ts->v1_2 = ts->v2_2;
	ts->v2_2 = ts->v3_2;
	ts->v3_2 = (zt->fac2 * ts->v2_2 >> 15) - ts->v1_2;

	/* Return top 16 bits */
	if (!ts->modulate)
		return ts->v3_1 + ts->v3_2;
	/* we are modulating */
	p = ts->v3_2 - 32768;
	if (p < 0)
		p = -p;
	p = ((p * 9) / 10) + 1;
	return (ts->v3_1 * p) >> 15;

}

static inline short
zt_txtone_nextsample(struct zt_chan *ss)
{
	/* follow the curves, return the sum */

	ss->v1_1 = ss->v2_1;
	ss->v2_1 = ss->v3_1;
	ss->v3_1 = (ss->txtone * ss->v2_1 >> 15) - ss->v1_1;
	return ss->v3_1;
}

/* These are the right functions to use.  */

#define ZT_MULAW(a)	(__zt_mulaw[(a)])
#define ZT_ALAW(a)	(__zt_alaw[(a)])
#define ZT_XLAW(a,c)	(c->xlaw[(a)])

#ifdef CONFIG_CALC_XLAW
#define ZT_LIN2MU(a)	(__zt_lineartoulaw((a)))
#define ZT_LIN2A(a)	(__zt_lineartoalaw((a)))

#define ZT_LIN2X(a,c)	((c)->lineartoxlaw((a)))

#else				/* CONFIG_CALC_XLAW */
/* Use tables */
#define ZT_LIN2MU(a)	(__zt_lin2mu[((unsigned short)(a)) >> 2])
#define ZT_LIN2A(a)	(__zt_lin2a[((unsigned short)(a)) >> 2])

/* Manipulate as appropriate for x-law */
#define ZT_LIN2X(a,c)	((c)->lin2x[((unsigned short)(a)) >> 2])

#endif				/* CONFIG_CALC_XLAW */

/* The following is for the PCI RADIO interface only. This is specified in this file because
   external processes need to interact with the device. Some devices have private functions used
   for test/diagnostic only, but this is not the case here. */

struct zt_radio_stat {
	unsigned short ctcode_rx;	/* code of currently received CTCSS or DCS, 0 for none */
	unsigned short ctclass;		/* class of currently received CTCSS or DCS code */
	unsigned short ctcode_tx;	/* code of currently encoded CTCSS or DCS, 0 for none */
	unsigned char radstat;		/* status bits of radio */
};

#define RAD_SERIAL_BUFLEN 128

struct zt_radio_param {
	unsigned short radpar;		/* param identifier */
	unsigned short index;		/* tone number */
	int data;			/* param */
	int data2;			/* param 2 */
	unsigned char buf[RAD_SERIAL_BUFLEN];
};

#define ZT_RADIO_GETSTAT	_IOR (ZT_CODE, 57, struct zt_radio_stat)	/* Get current
										   status IOCTL */
#define ZT_RADIO_SETPARAM	_IOW (ZT_CODE, 58, struct zt_radio_param)	/* Set a channel
										   parameter IOCTL */
#define ZT_RADIO_GETPARAM	_IOR (ZT_CODE, 59, struct zt_radio_param)	/* Get a channel
										   parameter IOCTL */

/* Defines for Radio Status (zt_radio_stat.radstat) bits */

#define ZT_RADSTAT_RX		 1	/* currently "receiving " */
#define ZT_RADSTAT_TX		 2	/* currently "transmitting" */
#define ZT_RADSTAT_RXCT		 4	/* currently receiving continuous tone with current
					   settings */
#define ZT_RADSTAT_RXCOR	 8	/* currently receiving COR (irrelevant of COR ignore) */
#define ZT_RADSTAT_IGNCOR	16	/* currently ignoring COR */
#define ZT_RADSTAT_IGNCT	32	/* currently ignoring CTCSS/DCS decode */
#define ZT_RADSTAT_NOENCODE	64	/* currently blocking CTCSS/DCS encode */

/* Defines for Radio Parameters (zt_radio_param.radpar) */

#define ZT_RADPAR_INVERTCOR		 1	/* invert the COR signal (0/1) */
#define ZT_RADPAR_IGNORECOR		 2	/* ignore the COR signal (0/1) */
#define ZT_RADPAR_IGNORECT		 3	/* ignore the CTCSS/DCS decode (0/1) */
#define ZT_RADPAR_NOENCODE		 4	/* block the CTCSS/DCS encode (0/1) */
#define ZT_RADPAR_CORTHRESH		 5	/* COR trigger threshold (0-7) */

#define ZT_RADPAR_EXTRXTONE		 6	/* 0 means use internal decoder, 1 means UIOA logic
						   true is CT decode, 2 means UIOA logic false is
						   CT decode */
#define ZT_RADPAR_NUMTONES		 7	/* returns maximum tone index (curently 15) */
#define ZT_RADPAR_INITTONE		 8	/* init all tone indexes to 0 (no tones) */
#define ZT_RADPAR_RXTONE		 9	/* CTCSS tone, (1-32) or DCS tone (1-777), or 0
						   meaning no tone, set index also (1-15) */
#define ZT_RADPAR_RXTONECLASS		10	/* Tone class (0-65535), set index also (1-15) */
#define ZT_RADPAR_TXTONE		11	/* CTCSS tone (1-32) or DCS tone (1-777) or 0 to
						   indicate no tone, to transmit for this tone
						   index (0-32, 0 disables transmit CTCSS), set
						   index also (0-15) */
#define ZT_RADPAR_DEBOUNCETIME		12	/* receive indication debounce time, milliseconds
						   (1-999) */
#define ZT_RADPAR_BURSTTIME		13	/* end of transmit with no CT tone in milliseconds
						   (0-999) */

#define ZT_RADPAR_UIODATA		14	/* read/write UIOA and UIOB data. Bit 0 is UIOA,
						   bit 1 is UIOB */
#define ZT_RADPAR_UIOMODE		15	/* 0 means UIOA and UIOB are both outputs, 1 means
						   UIOA is input, UIOB is output, 2 means UIOB is
						   input and UIOA is output, 3 means both UIOA and
						   UIOB are inputs. Note mode for UIOA is
						   overridden when in EXTRXTONE mode. */

#define ZT_RADPAR_REMMODE		16	/* Remote control data mode */
#define ZT_RADPAR_REM_NONE		 0	/* no remote control data mode */
#define ZT_RADPAR_REM_RBI1		 1	/* Doug Hall RBI-1 data mode */
#define ZT_RADPAR_REM_SERIAL		 2	/* Serial Data, 9600 BPS */
#define ZT_RADPAR_REM_SERIAL_ASCII	 3	/* Serial Ascii Data, 9600 BPS */

#define ZT_RADPAR_REMCOMMAND	17	/* Remote conrtol write data block & do cmd */

#endif				/* __SS7_ZAPATA_H__ */
