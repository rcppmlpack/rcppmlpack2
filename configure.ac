# -*- mode: autoconf; autoconf-indentation: 4; -*-
#
# rcppmlpack configure.in by Dirk Eddelbuettel <edd@debian.org>

# require at least autoconf 2.61
AC_PREREQ(2.61)

AC_INIT([rcppmlpack], [2.1.0-1], [edd@debian.org])


# We are using C++
AC_LANG(C++)
AC_REQUIRE_CPP
AC_PROG_CC
AC_PROG_CXX

# Add-on macro for C++11 check
m4_include([m4/ax_cxx_compile_stdcxx.m4])
AX_CXX_COMPILE_STDCXX([11], [noext], [])

## check for pkg-config
AC_DEFUN([AC_PROG_PKGCONFIG], [AC_CHECK_PROG(PKGCONFIG,pkg-config,yes)])
AC_PROG_PKGCONFIG

# The following line _should_ work but bombs on Ubuntu 16.04
# PKG_CHECK_MODULES([MLPACK], [mlpack = 2.1.0])

# So do it manually
if test x"${PKGCONFIG}" == x"yes" && pkg-config --atleast-version=2.1.0 mlpack; then
   MLPACK_CFLAGS=`pkg-config --cflags mlpack`
   MLPACK_LIBS=`pkg-config --libs mlpack`
else
   # Add-on macro for library check in case pkg-config test fails
   m4_include([m4/ax_check_library.m4])

   AC_LANG_PUSH([C++])
   AC_CHECK_HEADER([mlpack/core.hpp], [], [AC_MSG_ERROR([Cannot find MLPACK headers.])])
   AX_CHECK_LIBRARY([MLPACK], [mlpack/core.hpp], [mlpack], [MLPACK_LIBS="-lmlpack"],
                              [AC_MSG_ERROR([Unable to find libmlpack])])
   AC_LANG_POP                                                    

fi

AC_SUBST(MLPACK_CFLAGS)
AC_SUBST(MLPACK_LIBS)
AC_OUTPUT(src/Makevars)


echo "
RcppMLPACK $PACKAGE_VERSION
==================

compiler:	${CXX}
cflags:         ${MLPACK_CFLAGS}
libs:           ${MLPACK_LIBS}
pkgconfig:      ${PKGCONFIG}
"

