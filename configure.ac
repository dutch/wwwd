AC_INIT([wwwd], [m4_esyscmd([build-aux/git-version-gen .tarball-version])],
[chris@lamberson.online])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_LIBOBJ_DIR([src])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_PROG_CC
PKG_CHECK_MODULES([CHECK], [check], [], [:])
AC_REPLACE_FUNCS([_start _exit])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
