#include "test_s21_matrix.h"

START_TEST(test_calc_complements_1) {
  matrix_t A, B, expected = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  expected.matrix[0][0] = -3;
  expected.matrix[0][1] = 6;
  expected.matrix[0][2] = -3;
  expected.matrix[1][0] = -19;
  expected.matrix[1][1] = 11;
  expected.matrix[1][2] = 5;
  expected.matrix[2][0] = 13;
  expected.matrix[2][1] = -8;
  expected.matrix[2][2] = -2;

  s21_calc_complements(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&expected, &B), SUCCESS);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t A, B, expected = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  s21_calc_complements(&A, &B);
  expected.matrix[0][0] = 0.0;
  expected.matrix[0][1] = 10.0;
  expected.matrix[0][2] = -20.0;
  expected.matrix[1][0] = 4.0;
  expected.matrix[1][1] = -14.0;
  expected.matrix[1][2] = 8.0;
  expected.matrix[2][0] = -8.0;
  expected.matrix[2][1] = -2.0;
  expected.matrix[2][2] = 4.0;
  ck_assert_int_eq(s21_eq_matrix(&B, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t A, B = {};
  s21_create_matrix(2, 6, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &B), IMPOSSIBLE_OPERATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_calc_complements_4) {
  int size = 4;
  matrix_t A, B, expected = {};
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
  expected.matrix[0][1] = 21;
  expected.matrix[0][2] = 31;
  expected.matrix[0][3] = -49;

  expected.matrix[1][0] = -17;
  expected.matrix[1][1] = 3;
  expected.matrix[1][2] = 13;
  expected.matrix[1][3] = -7;

  expected.matrix[2][0] = 13;
  expected.matrix[2][1] = -27;
  expected.matrix[2][2] = -17;
  expected.matrix[2][3] = 23;

  expected.matrix[3][0] = -3;
  expected.matrix[3][1] = -3;
  expected.matrix[3][2] = -33;
  expected.matrix[3][3] = 27;

  s21_calc_complements(&A, &B);

  ck_assert_int_eq(s21_eq_matrix(&B, &expected), SUCCESS);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_calc_complements_5) {
  matrix_t A, B, expected = {};
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

  s21_calc_complements(&A, &B);
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = -1.0;
  expected.matrix[0][1] = 36.0;
  expected.matrix[0][2] = -27.0;
  expected.matrix[1][0] = 9.0;
  expected.matrix[1][1] = -33.0;
  expected.matrix[1][2] = 49.0;
  expected.matrix[2][0] = 11.0;
  expected.matrix[2][1] = -8.0;
  expected.matrix[2][2] = 6.0;
  ck_assert_int_eq(s21_eq_matrix(&B, &expected), SUCCESS);

  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("test_calc_complements");
  TCase *tc = tcase_create("calc_complements_tcases");

  tcase_add_test(tc, test_calc_complements_1);
  tcase_add_test(tc, test_calc_complements_2);
  tcase_add_test(tc, test_calc_complements_3);
  tcase_add_test(tc, test_calc_complements_4);
  tcase_add_test(tc, test_calc_complements_5);

  suite_add_tcase(s, tc);
  return s;
}
