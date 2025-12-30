#include "test_s21_matrix.h"

int main(void) {
  int failed = 0;

  Suite *test_s21_matrix[] = {
      test_create_matrix(), test_remove_matrix(),  test_eq_matrix(),
      test_sum_matrix(),    test_sub_matrix(),     test_mult_number(),
      test_mult_matrix(),   test_transpose(),      test_calc_complements(),
      test_determinant(),   test_inverse_matrix(), NULL};

  for (int i = 0; test_s21_matrix[i] != NULL; i++) {
    SRunner *suite_runner = srunner_create(test_s21_matrix[i]);

    srunner_set_fork_status(suite_runner, CK_NOFORK);
    srunner_run_all(suite_runner, CK_NORMAL);

    failed += srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
  }

  return 0;
}
