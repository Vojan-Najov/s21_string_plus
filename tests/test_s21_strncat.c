#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(zero_size) {
  char dest[5] = "";
  char dest21[5] = "";
  char *src = "";
  char *src21 = "";
  size_t n = 0;

  ck_assert_ptr_eq(s21_strncat(dest21, src21, n), dest21);
  ck_assert_ptr_eq(strncat(dest, src, n), dest);
}
END_TEST

START_TEST(n_greater_src_length) {
  char dest[1024];
  char dest21[1024];
  char src[512];
  char src21[512];
  size_t n = 700;

  for (int c = 'a', i = 0; i < 511; ++c, ++i) {
    src[i] = src21[i] = (char)c;
    c = c > 'z' ? 'a' : c;
  }
  src[511] = src21[511] = '\0';
  for (int c = 'a', i = 0; i < 255; ++c, ++i) {
    dest[i] = dest21[i] = (char)c;
    c = c > 'z' ? 'a' : c;
  }
  dest[255] = dest21[255] = '\0';

  ck_assert_ptr_eq(s21_strncat(dest21, src21, n), dest21);
  strncat(dest, src, n);
  ck_assert(strcmp(dest, dest21) == 0);
}
END_TEST

START_TEST(n_less_src_length) {
  char dest[1024];
  char dest21[1024];
  char src[512];
  char src21[512];
  size_t n = 256;

  for (int c = 'a', i = 0; i < 511; ++c, ++i) {
    src[i] = src21[i] = (char)c;
    c = c > 'z' ? 'a' : c;
  }
  src[511] = src21[511] = '\0';
  for (int c = 'a', i = 0; i < 1024; ++c, ++i) {
    dest[i] = dest21[i] = (char)c;
    c = c > 'z' ? 'a' : c;
  }
  dest[255] = dest21[255] = '\0';

  ck_assert_ptr_eq(s21_strncat(dest21, src21, n), dest21);
  strncat(dest, src, n);
  ck_assert(strcmp(dest, dest21) == 0);
}
END_TEST

START_TEST(n_eq_src_length) {
  char dest[1024];
  char dest21[1024];
  char src[512];
  char src21[512];
  size_t n = 511;

  for (int c = 'a', i = 0; i < 511; ++c, ++i) {
    src[i] = src21[i] = (char)c;
    c = c > 'z' ? 'a' : c;
  }
  src[511] = src21[511] = '\0';
  for (int c = 'a', i = 0; i < 1024; ++c, ++i) {
    dest[i] = dest21[i] = (char)c;
    c = c > 'z' ? 'a' : c;
  }
  dest[255] = dest21[255] = '\0';

  ck_assert(strlen(src21) == n);
  ck_assert_ptr_eq(s21_strncat(dest21, src21, n), dest21);
  strncat(dest, src, n);
  ck_assert(strcmp(dest, dest21) == 0);
}
END_TEST

Suite *suite_s21_strncat(void) {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("s21_strncat");
  tc = tcase_create("tcase_s21_strncat");
  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero_size);
    tcase_add_test(tc, n_greater_src_length);
    tcase_add_test(tc, n_less_src_length);
    tcase_add_test(tc, n_eq_src_length);
    suite_add_tcase(s, tc);
  }

  return (s);
}
