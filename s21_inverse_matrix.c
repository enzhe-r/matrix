#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = 0;
  double A_determinant = 0.0;
  if (s21_incorrect_matrix(A))
    status = INCORRECT_MATRIX;
  else if (A->rows == A->columns) {
    s21_determinant(A, &A_determinant);
    if (A_determinant == 0)
      status = IMPOSSIBLE_OPERATION;
    else {
      matrix_t A_calc_complements = {0};
      if (!s21_calc_complements(A, &A_calc_complements)) {
        matrix_t A_transpose = {0};
        if (!s21_transpose(&A_calc_complements, &A_transpose))
          s21_mult_number(&A_transpose, 1 / A_determinant, result);
        s21_remove_matrix(&A_transpose);
      }
      s21_remove_matrix(&A_calc_complements);
    }
  } else
    status = IMPOSSIBLE_OPERATION;
  return status;
}
