#!/usr/bin/m4 -P
AC_PREREQ([2.69])
AC_INIT([libitree], [0.0.1], [killm9m1@yahoo.it])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Safety check - list a source file that wouldn't be in other directories.
AC_CONFIG_SRCDIR([src/interval.c])


# Remember externally set CFLAGS
# EXTERNAL_CFLAGS="$CFLAGS"

# Checks for programs. These may set default variables, such as CFLAGS
AM_PROG_AR
AC_PROG_CC


# Use the C language and compiler for the following checks
AC_LANG([C])


# Checks C11
AC_COMPILE_IFELSE(
					[AC_LANG_PROGRAM([[#include <stdio.h>]], [for(int i=0;i<10;++i) printf("Test C11\n");]])],
					[AC_MSG_RESULT([c11 supportted])],
					[AC_MSG_RESULT([c11 not supportted])])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([assert.h])
AC_CHECK_HEADERS([stddef.h])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([math.h])
AC_CHECK_HEADERS([float.h])
AC_CHECK_HEADERS([stdbool.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Add debug support
dnl AC_ARG_ENABLE(debug,
dnl   AS_HELP_STRING(
dnl     [--enable-debug],
dnl     [enable debugging, default: no]),
dnl     [case "${enableval}" in
dnl       yes) debug=true ;;
dnl       no)  debug=false ;;
dnl       *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
dnl     esac],
dnl     [debug=false])
dnl AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")
dnl AM_COND_IF(DEBUG,
dnl     AC_DEFINE(DEBUG, 1, [Define to 0 if this is a release build]),
dnl     AC_DEFINE(DEBUG, 0, [Define to 1 or higher if this is a debug build]))


# Checks for library functions.

# These are the files to be generated.
AC_CONFIG_FILES([Makefile])

# Last line: actually generate all required output files.
AC_OUTPUT

dnl AC_MSG_RESULT([
dnl Configure Information:
dnl   Preprocessor      :
dnl     CPPFLAGS        : $CPPFLAGS

dnl   C Compiler        : $CC
dnl     DEFS            :   $DEFS
dnl     CFLAGS          :   $CFLAGS
    
dnl   C++ Compiler      : $CXX
dnl     CXXFLAGS        :   $CXXFLAGS

dnl   Linker            : $LD
dnl     LDFLAGS         :   $LDFLAGS
dnl     LIBS            :   $LIBS

dnl   Python            : $PYTHON
dnl     PY_PREFIX       :   $PY_PREFIX
dnl     PYTHON_LIBS     :   $PYTHON_LIBS
dnl     PYTHON_CFLAGS   :   $PYTHON_CFLAGS
dnl  ])

AC_MSG_RESULT([
Configure Information:
  Preprocessor      :
    CPPFLAGS        : $CPPFLAGS

  C Compiler        : $CC
    DEFS            : $DEFS
    CFLAGS          : $CFLAGS
    
  Linker            : $LD
    LDFLAGS         : $LDFLAGS
    LIBS            : $LIBS
 ])
