#include "test_s21_matrix.h"

START_TEST(test_determinant_1) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) A.matrix[i][j] = j;
  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_2) {
  const int size = 4;
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < size; j++) A.matrix[i][j] = j + i;
  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_3) {
  const int size = 3;
  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 5;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, -211);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_4) {
  const int size = 2;
  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = -10;
  A.matrix[0][1] = -13;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 4;

  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, 51);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_5) {
  const int size = 1;
  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 777;
  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, 777);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_6) {
  matrix_t A;
  double res;
  s21_create_matrix(2, 6, &A);
  ck_assert_int_eq(s21_determinant(&A, &res), IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_7) {
  matrix_t A;
  double res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -10;
  A.matrix[0][1] = -13;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_8) {
  matrix_t A;
  double res;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 9.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, 97);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_9) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 6.0;
  m.matrix[0][1] = -2.0;
  m.matrix[0][2] = -1.0;
  m.matrix[0][3] = 5.0;
  m.matrix[0][4] = -9.0;

  m.matrix[1][0] = -7.0;
  m.matrix[1][1] = 1.0;
  m.matrix[1][2] = 2.0;
  m.matrix[1][3] = 3.0;
  m.matrix[1][4] = 1.0;

  m.matrix[2][0] = 2.0;
  m.matrix[2][1] = 3.0;
  m.matrix[2][2] = 4.0;
  m.matrix[2][3] = 1.0;
  m.matrix[2][4] = 6.0;

  m.matrix[3][0] = 5.0;
  m.matrix[3][1] = 4.0;
  m.matrix[3][2] = 4.0;
  m.matrix[3][3] = 3.0;
  m.matrix[3][4] = 2.0;

  m.matrix[4][0] = 1.0;
  m.matrix[4][1] = 1.0;
  m.matrix[4][2] = 2.0;
  m.matrix[4][3] = 1.0;
  m.matrix[4][4] = 1.0;

  double res = 0;
  s21_determinant(&m, &res);
  ck_assert_double_eq(res, 570);
  s21_remove_matrix(&m);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("determinant_test");
  TCase *tc = tcase_create("determinant_tcases");

  tcase_add_test(tc, test_determinant_1);
  tcase_add_test(tc, test_determinant_2);
  tcase_add_test(tc, test_determinant_3);
  tcase_add_test(tc, test_determinant_4);
  tcase_add_test(tc, test_determinant_5);
  tcase_add_test(tc, test_determinant_6);
  tcase_add_test(tc, test_determinant_7);
  tcase_add_test(tc, test_determinant_8);
  tcase_add_test(tc, test_determinant_9);
  suite_add_tcase(s, tc);
  return s;
}
