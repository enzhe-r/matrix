#include "test_s21_matrix.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A = {};
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A, B, result = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A, B, result, expected = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &expected);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  // int res = 0;
  // double number = -2.0;
  matrix_t A, B, expected, result = {};

  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &expected);
  // s21_create_matrix(3, 3, &result);

  B.matrix[0][0] = 1.0, B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0, B.matrix[1][1] = 1.0;
  B.matrix[2][0] = 1.0, B.matrix[2][1] = 1.0;

  A.matrix[0][0] = 1.0, A.matrix[0][1] = 2.0, A.matrix[0][2] = 1.0;
  A.matrix[1][0] = 0.0, A.matrix[1][1] = 1.0, A.matrix[1][2] = 2.0;

  expected.matrix[0][0] = 1.0, expected.matrix[0][1] = 2.0,
  expected.matrix[0][2] = 1.0;
  expected.matrix[1][0] = 0.0, expected.matrix[1][1] = 1.0,
  expected.matrix[1][2] = 2.0;
  expected.matrix[2][0] = 1.0, expected.matrix[2][1] = 3.0,
  expected.matrix[2][2] = 3.0;

  ck_assert_int_eq(s21_mult_matrix(&B, &A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("test_mult_matrix");
  TCase *tcase = tcase_create("mult_matrix_tcases");

  tcase_add_test(tcase, s21_mult_matrix_1);
  tcase_add_test(tcase, s21_mult_matrix_2);
  tcase_add_test(tcase, s21_mult_matrix_3);
  tcase_add_test(tcase, s21_mult_matrix_4);

  suite_add_tcase(s, tcase);
  return s;
}
