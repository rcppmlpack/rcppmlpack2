# -*- mode: autoconf; autoconf-indentation: 4; -*-
#
# rcppmlpack configure.in by Dirk Eddelbuettel <edd@debian.org>

# require at least autoconf 2.61
AC_PREREQ(2.61)

AC_INIT([rcppmlpack], [2.0.2-1], [edd@debian.org])

m4_include([m4/ax_cxx_compile_stdcxx.m4])
m4_include([m4/ax_check_library.m4])

# We are using C++
AC_LANG(C++)
AC_REQUIRE_CPP
AC_PROG_CC
AC_PROG_CXX

AX_CXX_COMPILE_STDCXX([11], [noext], [])

AC_LANG_PUSH([C++])
AC_CHECK_HEADER([mlpack/core.hpp], [], [AC_MSG_ERROR([Cannot find MLPACK headers.])])
AX_CHECK_LIBRARY([MLPACK], [mlpack/core.hpp], [mlpack], [PKG_LIBS="-lmlpack"],
                           [AC_MSG_ERROR([Unable to find libmlpack])])

AC_LANG_POP                                                    

AC_SUBST(PKG_LIBS)
AC_OUTPUT(src/Makevars)


echo "
RcppMLPACK $PACKAGE_VERSION
==================

compiler:               ${CXX}
ldflags:                ${LDFLAGS}
pkg_libs:               ${PKG_LIBS}
"

