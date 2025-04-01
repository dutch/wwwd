TESTS = %D%/check-wwwd
check_PROGRAMS = %D%/check-wwwd
%C%_check_wwwd_SOURCES = %D%/check-wwwd.c src/arena.c src/arena.h
%C%_check_wwwd_CPPFLAGS = -I$(top_srcdir)/src $(CHECK_CFLAGS)
%C%_check_wwwd_LDADD = $(CHECK_LIBS)
