#include "test_s21_matrix.h"

START_TEST(s21_sub_matrix_1) {
  matrix_t A, B = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A, B, result = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t A, B, result, eq_matrix = {};
  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &B);
  s21_create_matrix(6, 6, &eq_matrix);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t A, B, result, expected = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &expected);

  B.matrix[0][0] = 1.0, B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0, B.matrix[1][1] = 1.0;
  B.matrix[2][0] = 1.0, B.matrix[2][1] = 1.0;

  A.matrix[0][0] = 1.0, A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0, A.matrix[1][1] = 1.0;
  A.matrix[2][0] = 2.0, A.matrix[2][1] = 2.0;

  expected.matrix[0][0] = 0, expected.matrix[0][1] = 2;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 0;
  expected.matrix[2][0] = 1, expected.matrix[2][1] = 1;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("test_sub_matrix");
  TCase *tcase = tcase_create("sub_tcase");

  tcase_add_test(tcase, s21_sub_matrix_1);
  tcase_add_test(tcase, s21_sub_matrix_2);
  tcase_add_test(tcase, s21_sub_matrix_3);
  tcase_add_test(tcase, s21_sub_matrix_4);

  suite_add_tcase(s, tcase);
  return s;
}