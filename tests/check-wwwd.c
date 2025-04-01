#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "arena.h"

START_TEST(test_mkarena)
{
  arena_t a;

  a = mkarena(1);
  ck_assert_ptr_nonnull(a.beg);
}
END_TEST

START_TEST(test_alloc_jumps_on_fail)
{
  arena_t a;
  void *jmp_buf[5];

  a = mkarena(1);

  if (__builtin_setjmp(jmp_buf))
    return;

  a.jmp_buf = jmp_buf;
  new(&a, char, 2);
  ck_abort();
}
END_TEST

Suite *
wwwd_suite(void)
{
  Suite *s;
  TCase *tc;

  s = suite_create("wwwd");
  tc = tcase_create("Arena");
  tcase_add_test(tc, test_mkarena);
  tcase_add_test(tc, test_alloc_jumps_on_fail);
  suite_add_tcase(s, tc);

  return s;
}

int
main(int argc, char **argv)
{
  int verbose, nfails;
  char ch;
  Suite *s;
  SRunner *r;

  verbose = 0;

  while ((ch = getopt(argc, argv, ":v")) != -1) {
    switch (ch) {
    case 'v':
      verbose = 1;
      break;
    default:
      fprintf(stderr, "usage: %s [-v]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  s = wwwd_suite();
  r = srunner_create(s);

  srunner_run_all(r, verbose ? CK_VERBOSE : CK_ENV);
  nfails = srunner_ntests_failed(r);
  srunner_free(r);

  return (nfails == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
