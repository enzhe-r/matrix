#include "test_s21_matrix.h"

START_TEST(s21_mult_number_1) {
  matrix_t A = {};
  ck_assert_int_eq(s21_mult_matrix(&A, 0, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A, result, expected = {};

  double number = 5;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &expected);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t A, result, expected = {};
  double number = 2;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0, A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0, A.matrix[1][1] = 1.0;
  A.matrix[2][0] = 2.0, A.matrix[2][1] = 4.0;
  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 2, expected.matrix[0][1] = 4;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 2;
  expected.matrix[2][0] = 4, expected.matrix[2][1] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t A, result, expected = {};
  double number = 0;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0, A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0, A.matrix[1][1] = 1.0;
  A.matrix[2][0] = 2.0, A.matrix[2][1] = 4.0;
  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 0, expected.matrix[0][1] = 0;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 0;
  expected.matrix[2][0] = 0, expected.matrix[2][1] = 0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t A, result, expected = {};
  double number = 0;
  s21_create_matrix(3, 2, &A);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 3.0;
  A.matrix[2][0] = 9.0;
  A.matrix[2][1] = -2.0;
  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 0, expected.matrix[0][1] = 0;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 0;
  expected.matrix[2][0] = 0, expected.matrix[2][1] = 0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_6) {
  matrix_t A, result, expected = {0};
  s21_create_matrix(3, 3, &A);
  double number = -1.0;
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 1.0;
  A.matrix[0][2] = -1.0;
  A.matrix[1][0] = 38.0;
  A.matrix[1][1] = -41.0;
  A.matrix[1][2] = 34.0;
  A.matrix[2][0] = -27.0;
  A.matrix[2][1] = 29.0;
  A.matrix[2][2] = 24.0;

  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1.0, expected.matrix[0][1] = -1.0,
  expected.matrix[0][2] = 1.0;
  expected.matrix[1][0] = -38.0, expected.matrix[1][1] = 41.0,
  expected.matrix[1][2] = -34.0;
  expected.matrix[2][0] = 27.0, expected.matrix[2][1] = -29.0,
  expected.matrix[2][2] = -24.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_7) {
  matrix_t A = {};
  s21_create_matrix(-2, 0, &A);
  ck_assert_int_eq(s21_mult_matrix(&A, 0, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("test_mult_number");
  TCase *tcase = tcase_create("mult_numb_tcases");

  tcase_add_test(tcase, s21_mult_number_1);
  tcase_add_test(tcase, s21_mult_number_2);
  tcase_add_test(tcase, s21_mult_number_3);
  tcase_add_test(tcase, s21_mult_number_4);
  tcase_add_test(tcase, s21_mult_number_5);
  tcase_add_test(tcase, s21_mult_number_6);
  tcase_add_test(tcase, s21_mult_number_7);

  suite_add_tcase(s, tcase);
  return s;
}
