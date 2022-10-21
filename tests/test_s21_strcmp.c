#include <check.h>
#include <string.h>
#include "s21_string.h"

START_TEST(empty_strings)
{
	const char *s1 = "";
	const char *s2 = "";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
}
END_TEST

START_TEST(empty_string_1)
{
	const char *s1 = "";
	const char *s2 = "dasjdaddaksjsaddakdasdjsasadka";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
}
END_TEST

START_TEST(empty_string_2)
{
	const char *s1 = "dasjdaddaksjsaddakdasdjsasadka";
	const char *s2 = "";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
}
END_TEST

START_TEST(ret_unsigned)
{
	char s1[] = "\0\0";
	char s2[] = "\0\0";

	s1[0] = 0xff;
	s2[0] = 0x02;
	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
}
END_TEST

START_TEST(cmp_unsigned)
{
	char s1[] = "\0\0";
	char s2[] = "\0\0";

	s1[0] = 0xff; s1[1] = 0xf1;
	s2[0] = 0xff; s2[1] = 0x11;
	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
	ck_assert_int_eq(
		s21_strcmp(s2, s1), strcmp(s2, s1));
}
END_TEST

START_TEST(cmp_0)
{
	char s1[] = "sadlksadlaskdslassasdalkasddklaasdsal";
	char s2[] = "sadlksadlaskdslassasdalkasddklaasdsal";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
	ck_assert_int_eq(
		s21_strcmp(s2, s1), strcmp(s2, s1));
}
END_TEST

START_TEST(cmp_1)
{
	char s1[] = "sadlksadlaskdslassasdalkasddklaasdsal";
	char s2[] = "s_dlksadlaskdslassasdalkasddklaasdsal";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
	ck_assert_int_eq(
		s21_strcmp(s2, s1), strcmp(s2, s1));
}
END_TEST

START_TEST(cmp_2)
{
	char s1[] = "sadlksadlaskdslass_sdalkasd_laasdsal";
	char s2[] = "sadlksadlaskdslassasdalkasddklaasdsal";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
	ck_assert_int_eq(
		s21_strcmp(s2, s1), strcmp(s2, s1));
}
END_TEST

START_TEST(cmp_3)
{
	char s1[] = "sadlksadlaskdslassasdalkasddklaasds__";
	char s2[] = "sadlksadlaskdslassasdalkasddklaasdsal";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
	ck_assert_int_eq(
		s21_strcmp(s2, s1), strcmp(s2, s1));
}
END_TEST

START_TEST(cmp_4)
{
	char s1[] = "sadlksadlaskdslass";
	char s2[] = "sadlksadlaskdslassasdalkasddklaasdsal";

	ck_assert_int_eq(
		s21_strcmp(s1, s2), strcmp(s1, s2));
	ck_assert_int_eq(
		s21_strcmp(s2, s1), strcmp(s2, s1));
}
END_TEST

Suite	*suite_s21_strcmp(void)
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("suite_s21_strcmp");
	tc = tcase_create("tcase_s21_strcmp");

	tcase_add_test(tc, empty_strings);
	tcase_add_test(tc, empty_string_1);
	tcase_add_test(tc, empty_string_2);
	tcase_add_test(tc, ret_unsigned);
	tcase_add_test(tc, cmp_unsigned);
	tcase_add_test(tc, cmp_0);
	tcase_add_test(tc, cmp_1);
	tcase_add_test(tc, cmp_2);
	tcase_add_test(tc, cmp_3);
	tcase_add_test(tc, cmp_4);
	suite_add_tcase(s, tc);

	return s;
}