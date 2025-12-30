#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (s21_incorrect_matrix(A))
    status = INCORRECT_MATRIX;
  else if (!s21_create_matrix(A->columns, A->rows, result))
    for (int i = 0; i < A->columns; i++)
      for (int j = 0; j < A->rows; j++) result->matrix[i][j] = A->matrix[j][i];
  return status;
}
