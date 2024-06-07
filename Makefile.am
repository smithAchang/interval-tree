# This is the top-level Makefile.am for a non-recursive Autotools setup. In
# fact, in non-recursive structures, this is the only Makefile.am that is
# needed.

AUTOMAKE_OPTIONS= foreign

# Always set this so that we can just '#include "foo.h"' from anywhere,
# including the tests directory so that tests also find header files.
AM_CFLAGS = -W -Wall -pipe -std=c11 -I$(top_srcdir)/src



mylib = libitree.a
libitree_a_SOURCES = src/interval.c src/interval_list.c src/itree.c
include_HEADERS = src/utils.h src/interval.h src/interval_list.h src/itree.h
noinst_LIBRARIES= $(mylib)

# Testing setup. Type 'make check' or 'make recheck' to run the tests.
# TESTS defines a list of tests to run. Define their sources in the usual way.
check_PROGRAMS=test_tree
test_tree_SOURCES=tests/test_tree.c
test_tree_LDADD=$(mylib)
