#include "test_s21_matrix.h"

START_TEST(test_inverse_matrix_1) {
  matrix_t A, result = {0};
  s21_create_matrix(1, 3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  const int size = 2;
  matrix_t A, result = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
  const int size = 3;
  matrix_t A, res, expected = {0};
  s21_create_matrix(size, size, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  s21_inverse_matrix(&A, &res);
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
  matrix_t A, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("case_inverse_matrix");

  tcase_add_test(tc, test_inverse_matrix_1);
  tcase_add_test(tc, test_inverse_matrix_2);
  tcase_add_test(tc, test_inverse_matrix_3);
  tcase_add_test(tc, test_inverse_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
