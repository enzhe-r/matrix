#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (s21_incorrect_matrix(A) || s21_incorrect_matrix(B) || result == NULL)
    return status = INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns)
    return status = IMPOSSIBLE_OPERATION;

  if (!s21_create_matrix(A->rows, A->columns, result)) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }
  return status;
}