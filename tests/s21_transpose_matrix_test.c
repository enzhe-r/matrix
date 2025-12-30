#include "test_s21_matrix.h"

START_TEST(transpose_1) {
  matrix_t result = {};
  ck_assert_int_eq((s21_transpose(NULL, &result)), INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t B, result, expected = {};
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 3, &expected);

  B.matrix[0][0] = 1.0, B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 0.0, B.matrix[1][1] = 1.0;
  B.matrix[2][0] = 2.0, B.matrix[2][1] = 2.0;

  expected.matrix[0][0] = 1, expected.matrix[0][1] = 0,
  expected.matrix[0][2] = 2;
  expected.matrix[1][0] = 2, expected.matrix[1][1] = 1,
  expected.matrix[1][2] = 2;

  ck_assert_int_eq(s21_transpose(&B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t B, result, expected = {};
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 3, &expected);

  B.matrix[0][0] = 1.0, B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0, B.matrix[1][1] = 1.0;
  B.matrix[2][0] = 1.0, B.matrix[2][1] = 1.0;

  expected.matrix[0][0] = 1, expected.matrix[0][1] = 0,
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 1,
  expected.matrix[1][2] = 1;

  ck_assert_int_eq(s21_transpose(&B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A, result, expected = {};
  int size = 4;
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[1][3] = 2;

  A.matrix[2][0] = 1;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 3;

  A.matrix[3][0] = 2;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 4;
  A.matrix[3][3] = 3;

  s21_create_matrix(size, size, &expected);

  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 4;
  expected.matrix[0][2] = 1;
  expected.matrix[0][3] = 2;

  expected.matrix[1][0] = 2;
  expected.matrix[1][1] = 3;
  expected.matrix[1][2] = 4;
  expected.matrix[1][3] = 1;

  expected.matrix[2][0] = 3;
  expected.matrix[2][1] = 1;
  expected.matrix[2][2] = 2;
  expected.matrix[2][3] = 4;

  expected.matrix[3][0] = 4;
  expected.matrix[3][1] = 2;
  expected.matrix[3][2] = 3;
  expected.matrix[3][3] = 3;

  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("test_transpose");
  TCase *tc = tcase_create("transpose_matrix_tcases");
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);

  suite_add_tcase(s, tc);
  return s;
}
