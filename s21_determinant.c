#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = 0;
  *result = 0.0;

  if (s21_incorrect_matrix(A))
    status = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    status = IMPOSSIBLE_OPERATION;
  else if (A->rows == 1)
    *result = A->matrix[0][0];
  else if (A->rows == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else
    *result = s21_big_determinant_handling(A);

  return status;
}
