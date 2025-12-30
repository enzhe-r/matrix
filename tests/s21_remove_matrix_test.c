#include "test_s21_matrix.h"

START_TEST(s21_remove_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_02) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

// START_TEST(s21_remove_matrix_1) {
//   matrix_t A = {};
//   s21_remove_matrix(&A);
//   ck_assert_int_eq(1, 1);
// }
// END_TEST

// START_TEST(s21_remove_matrix_2) {
//   matrix_t A = {};
//   s21_create_matrix(3, 3, &A);
//   s21_remove_matrix(&A);
//   ck_assert_ptr_null(A.matrix);
// }
// END_TEST

// START_TEST(s21_remove_matrix_3) {
//   s21_remove_matrix(NULL);
//   ck_assert_int_eq(1, 1);
// }
// END_TEST

Suite *test_remove_matrix(void) {
  Suite *s = suite_create("test_remove_matrix");
  TCase *tcase = tcase_create("remove_tcases");

  tcase_add_test(tcase, s21_remove_matrix_01);
  tcase_add_test(tcase, s21_remove_matrix_02);
  tcase_add_test(tcase, s21_remove_matrix_03);
  tcase_add_test(tcase, s21_remove_matrix_04);
  tcase_add_test(tcase, s21_remove_matrix_05);

  suite_add_tcase(s, tcase);
  return s;
}
