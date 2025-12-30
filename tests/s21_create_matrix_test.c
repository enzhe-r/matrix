#include "test_s21_matrix.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(5, 6, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(300, 300, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(-1, 15, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(555555, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(0, 1212122, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("test_create");
  TCase *tcase = tcase_create("create_tcases");

  tcase_add_test(tcase, s21_create_matrix_1);
  tcase_add_test(tcase, s21_create_matrix_2);
  tcase_add_test(tcase, s21_create_matrix_3);
  tcase_add_test(tcase, s21_create_matrix_4);
  tcase_add_test(tcase, s21_create_matrix_5);
  tcase_add_test(tcase, s21_create_matrix_6);
  tcase_add_test(tcase, s21_create_matrix_7);
  tcase_add_test(tcase, s21_create_matrix_8);

  suite_add_tcase(s, tcase);
  return s;
}
