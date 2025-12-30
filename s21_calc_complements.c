#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;
  double A_minor_determinant = 0.0;
  if (s21_incorrect_matrix(A))
    status = INCORRECT_MATRIX;
  else if (A->rows != A->columns && status == 0)
    status = IMPOSSIBLE_OPERATION;
  else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int k = 0; k < A->columns; k++) {
        matrix_t A_minor = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &A_minor);

        s21_get_minor_matrix(i, k, A, &A_minor);

        s21_determinant(&A_minor, &A_minor_determinant);

        result->matrix[i][k] = pow(-1, (i + k)) * A_minor_determinant;

        s21_remove_matrix(&A_minor);
      }
    }
  }

  return status;
}
