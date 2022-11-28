#define _GNU_SOURCE
#include <check.h>
#include <string.h>
#include "s21_string.h"

START_TEST (null)
{
	void *buf = NULL;
	size_t n = 0;
	int c = '\a';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (zero_size_1)
{
	char	buf[] = "";
	size_t	n = 0;
	int		c = '\0';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (zero_size_2)
{
	char	buf[] = "abcd";
	size_t	n = 0;
	int		c = 'd';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (not_found1)
{
	char	buf[] = "abvdefg";
	size_t	n = sizeof(buf) / sizeof(char) - 3;
	int		c = '\0';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (not_found2)
{
	char	buf[] = "abvdefg";
	size_t	n = sizeof(buf) / sizeof(char) - 3;
	int		c = 'g';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (found_1)
{
	char	buf[] = "abvdefg";
	size_t	n = sizeof(buf) / sizeof(char);
	int		c = 'a';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (found_2)
{
	char	buf[] = "abvdevfg";
	size_t	n = sizeof(buf) / sizeof(char);
	int		c = 'v';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

START_TEST (found_3)
{
	char	buf[] = "abvdefg\0\0";
	size_t	n = sizeof(buf) / sizeof(char);
	int		c = '\0';

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
	ck_assert_ptr_nonnull(s21_memrchr(buf, c, n));
}
END_TEST

START_TEST (found_unsigned_char)
{
	char	buf[] = "abvdebfg";
	size_t	n = sizeof(buf) / sizeof(char);
	int		c = 'b' | 0x11100;

	ck_assert_ptr_eq(s21_memrchr(buf, c, n), memrchr(buf, c, n));
}
END_TEST

Suite *suite_s21_memrchr(void)
{
	Suite *s = NULL;
	TCase *tc = NULL;

	s = suite_create("suite_s21_memrchr");
	tc = tcase_create("tcase_s21_memrchr");
	if (s != NULL || tc != NULL) {
		tcase_add_test(tc, null);
		tcase_add_test(tc, zero_size_1);
		tcase_add_test(tc, zero_size_2);
		tcase_add_test(tc, not_found1);
		tcase_add_test(tc, not_found2);
		tcase_add_test(tc, found_1);
		tcase_add_test(tc, found_2);
		tcase_add_test(tc, found_3);
		tcase_add_test(tc, found_unsigned_char);
		suite_add_tcase(s, tc);
	}

	return (s);
}
