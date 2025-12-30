#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = 0;
  if (s21_incorrect_matrix(A))
    status = INCORRECT_MATRIX;
  else if (!s21_create_matrix(A->rows, A->columns, result))
    for (int i = 0; i < result->rows; i++)
      for (int k = 0; k < result->columns; k++)
        result->matrix[i][k] = A->matrix[i][k] * number;
  return status;
}