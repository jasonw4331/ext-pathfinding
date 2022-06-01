dnl $Id$
dnl config.m4 for extension pathfinding

PHP_ARG_ENABLE([pathfinding],
  [whether to enable pathfinding support],
  [AS_HELP_STRING([--enable-pathfinding],
    [Enable pathfinding support])],
  [shared])

if test "$PHP_PATHFINDING" != "no"; then
  PHP_REQUIRE_CXX()

  dnl the 6th parameter here is required for C++ shared extensions
  PHP_NEW_EXTENSION(pathfinding, pathfinding.cpp, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -std=c++11 -O2, yes)
  PHP_SUBST(PATHFINDING_SHARED_LIBADD)
  PHP_ADD_INCLUDE($ext_builddir)
  PHP_ADD_INCLUDE($ext_builddir/3D-AStar-ThetaStar)
fi
