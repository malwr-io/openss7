# vim: ft=config sw=4 noet nocin nosi com=b\:#,b\:dnl,b\:***,b\:@%\:@ fo+=tcqlorn
# =============================================================================
# BEGINNING OF SEPARATE COPYRIGHT MATERIAL
# =============================================================================
# 
# @(#) $RCSfile$ $Name$($Revision$) $Date$
#
# -----------------------------------------------------------------------------
#
# Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
# Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>
#
# All Rights Reserved.
#
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU Affero General Public License as published by the Free
# Software Foundation; version 3 of the License.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
# details.
#
# You should have received a copy of the GNU Affero General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>, or write to
# the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# -----------------------------------------------------------------------------
#
# U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
# behalf of the U.S. Government ("Government"), the following provisions apply
# to you.  If the Software is supplied by the Department of Defense ("DoD"), it
# is classified as "Commercial Computer Software" under paragraph 252.227-7014
# of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
# successor regulations) and the Government is acquiring only the license rights
# granted herein (the license rights customarily provided to non-Government
# users).  If the Software is supplied to any unit or agency of the Government
# other than DoD, it is classified as "Restricted Computer Software" and the
# Government's rights in the Software are defined in paragraph 52.227-19 of the
# Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
# the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
# (or any successor regulations).
#
# -----------------------------------------------------------------------------
#
# Commercial licensing and support of this software is available from OpenSS7
# Corporation at a fee.  See http://www.openss7.com/
#
# -----------------------------------------------------------------------------
#
# Last Modified $Date$ by $Author$
#
# =============================================================================

# ===========================================================================
# _AUTOTEST
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST], [dnl
    _AUTOTEST_OPTIONS
    _AUTOTEST_SETUP
    _AUTOTEST_OUTPUT
])# _AUTOTEST
# ===========================================================================

# ===========================================================================
# _AUTOTEST_OPTIONS
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_OPTIONS], [dnl
    AC_MSG_CHECKING([for autotest on installcheck])
    AC_ARG_ENABLE([autotest],
	AS_HELP_STRING([--enable-autotest],
	    [enable pre- and post-install testing.  @<:@default=auto@:>@]),
	[enable_autotest="$enableval"], [dnl
	    if test :"${USE_MAINTAINER_MODE:-no}" != :no
	    then
		enable_autotest='yes'
	    else
		enable_autotest='no'
	    fi])
    AC_MSG_RESULT([${enable_autotest}])
    AM_CONDITIONAL([PERFORM_TESTING], [test :"${enable_autotest:-yes}" = :yes])dnl
])# _AUTOTEST_OPTIONS
# ===========================================================================

# ===========================================================================
# _AUTOTEST_SETUP
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_SETUP], [dnl
    _AUTOTEST_SETUP_AUTOM4TE
    _AUTOTEST_SETUP_AUTOTEST
])# _AUTOTEST_SETUP
# ===========================================================================

# ===========================================================================
# _AUTOTEST_SETUP_AUTOM4TE
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_SETUP_AUTOM4TE], [dnl
    AC_ARG_VAR([AUTOM4TE],
	       [Autom4te command. @<:@default=autom4te@:>@])
    AC_PATH_PROG([AUTOM4TE], [autom4te], [${am_missing_run}autom4te],
		 [$PATH:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin])
])# _AUTOTEST_SETUP_AUTOM4TE
# ===========================================================================

# ===========================================================================
# _AUTOTEST_SETUP_AUTOTEST
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_SETUP_AUTOTEST], [dnl
    AC_ARG_VAR([AUTOTEST],
	       [Autotest macro build command. @<:@default=autotest@:>@])
    AC_PATH_PROG([AUTOTEST], [autotest], [$AUTOM4TE --language=autotest],
		 [$PATH:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin])
])# _AUTOTEST_SETUP_AUTOTEST
# ===========================================================================

# ===========================================================================
# _AUTOTEST_OUTPUT
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_OUTPUT], [dnl
    AC_CONFIG_TESTDIR([tests], [.])
    AC_CONFIG_FILES([tests/Makefile])
    AC_CONFIG_FILES([tests/atlocal])
dnl _AUTOTEST_OUTPUT_CONFIG
])# _AUTOTEST_OUTPUT
# ===========================================================================

# ===========================================================================
# _AUTOTEST_OUTPUT_CONFIG
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_OUTPUT_CONFIG], [dnl
    AC_CONFIG_COMMANDS([tests/atlocal], [dnl
cat >tests/atlocal <<ATEOF
@%:@ =============================================================================
@%:@
@%:@ Generated by $[0].  Local procedures for building test suites.
@%:@
@%:@ -----------------------------------------------------------------------------
@%:@
@%:@ Copyright (c) 2001-2007  OpenSS7 Corporation <http://www.openss7.com/>
@%:@ Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>
@%:@
@%:@ All Rights Reserved.
@%:@
@%:@ This program is free software; you can redistribute it and/or modify it under
@%:@ the terms of the GNU General Public License as published by the Free Software
@%:@ Foundation; version 3 of the License.
@%:@
@%:@ This program is distributed in the hope that it will be useful, but WITHOUT
@%:@ ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
@%:@ FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
@%:@ details.
@%:@
@%:@ You should have received a copy of the GNU General Public License along with
@%:@ this program.  If not, see <http://www.gnu.org/licenses/>, or write to the
@%:@ Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
@%:@
@%:@ -----------------------------------------------------------------------------
@%:@
@%:@ U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
@%:@ behalf of the U.S. Government ("Government"), the following provisions apply
@%:@ to you.  If the Software is supplied by the Department of Defense ("DoD"), it
@%:@ is classified as "Commercial Computer Software" under paragraph 252.227-7014
@%:@ of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
@%:@ successor regulations) and the Government is acquiring only the license rights
@%:@ granted herein (the license rights customarily provided to non-Government
@%:@ users).  If the Software is supplied to any unit or agency of the Government
@%:@ other than DoD, it is classified as "Restricted Computer Software" and the
@%:@ Government's rights in the Software are defined in paragraph 52.227-19 of the
@%:@ Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
@%:@ the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
@%:@ (or any successor regulations).
@%:@
@%:@ -----------------------------------------------------------------------------
@%:@
@%:@ Commercial licensing and support of this software is available from OpenSS7
@%:@ Corporation at a fee.  See http://www.openss7.com/
@%:@
@%:@ =============================================================================
at_build=`$ac_top_srcdir/scripts/config.guess`
at_host="$ac_cv_host"
at_target="$ac_cv_target"
DEPMOD="$DEPMOD"
DESTDIR="$DESTDIR"
LSMOD="$LSMOD"
MODPROBE="$MODPROBE"
@%:@ Exit if cross compiling: we cannot run tests.
if test x"$cross_compiling" = xyes ; then exit 0 ; fi
ATEOF
], [dnl
DEPMOD="$DEPMOD"
DESTDIR="$DESTDIR"
LSMOD="$LSMOD"
MODPROBE="$MODPROBE"
ac_build="$ac_cv_build"
ac_host="$ac_cv_host"
ac_target="$ac_cv_target"
])
])# _AUTOTEST_OUTPUT_CONFIG
# ===========================================================================

# ===========================================================================
# _AUTOTEST_
# ---------------------------------------------------------------------------
AC_DEFUN([_AUTOTEST_], [dnl
])# _AUTOTEST_
# ===========================================================================

# =============================================================================
#
# $Log$
# Revision 0.9.2.17  2008-09-21 07:40:45  brian
# - add defaults to environment variables
#
# Revision 0.9.2.16  2008-04-28 09:41:03  brian
# - updated headers for release
#
# Revision 0.9.2.15  2007/10/17 23:38:08  brian
# - correction
#
# Revision 0.9.2.14  2007/10/17 20:00:26  brian
# - slightly different path checks
#
# Revision 0.9.2.13  2007/08/12 19:05:30  brian
# - rearrange and update headers
#
# Revision 0.9.2.12  2007/03/08 04:28:48  brian
# - substituions changed for program checking macros
#
# Revision 0.9.2.11  2006/03/11 09:49:50  brian
# - a bit better checking
#
# =============================================================================
# 
# Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
# Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>
# 
# =============================================================================
# ENDING OF SEPARATE COPYRIGHT MATERIAL
# =============================================================================
# vim: ft=config sw=4 noet nocin nosi com=b\:#,b\:dnl,b\:***,b\:@%\:@ fo+=tcqlorn