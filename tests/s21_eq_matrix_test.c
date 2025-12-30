#include "test_s21_matrix.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t A, B = {};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2.22;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4.0005;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2.22;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4.0005;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A, B = {};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  A.matrix[0][0] = 6.000000000234;
  A.matrix[0][1] = 7;
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 7;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A, B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(3, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A, B = {};
  s21_create_matrix(7, 7, &A);
  s21_create_matrix(-7, -7, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t A, B = {};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  A.matrix[0][0] = 1111;
  A.matrix[0][1] = 2;
  B.matrix[0][0] = 11;
  B.matrix[0][1] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t A, B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 1.0, A.matrix[0][1] = -1.0, A.matrix[0][2] = 1.0;
  A.matrix[1][0] = -38.0, A.matrix[1][1] = 41.0, A.matrix[1][2] = -34.0;
  A.matrix[2][0] = 27.0, A.matrix[2][1] = -29.0, A.matrix[2][2] = -24.0;

  B.matrix[0][0] = 1.0, B.matrix[0][1] = -1.0, B.matrix[0][2] = 1.0;
  B.matrix[1][0] = -38.0, B.matrix[1][1] = 41.0, B.matrix[1][2] = -34.0;
  B.matrix[2][0] = 27.0, B.matrix[2][1] = -29.0, B.matrix[2][2] = -24.0;

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("test_eq_matrix");
  TCase *tcase = tcase_create("eq_tcases");

  tcase_add_test(tcase, s21_eq_matrix_1);
  tcase_add_test(tcase, s21_eq_matrix_2);
  tcase_add_test(tcase, s21_eq_matrix_3);
  tcase_add_test(tcase, s21_eq_matrix_4);
  tcase_add_test(tcase, s21_eq_matrix_5);
  tcase_add_test(tcase, s21_eq_matrix_6);
  tcase_add_test(tcase, s21_eq_matrix_7);

  suite_add_tcase(s, tcase);
  return s;
}
