#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (s21_incorrect_matrix(A) || s21_incorrect_matrix(B))
    status = INCORRECT_MATRIX;
  else if (A->rows != B->columns)
    status = IMPOSSIBLE_OPERATION;
  else {
    if (!s21_create_matrix(A->rows, B->columns, result)) {
      if (!s21_incorrect_matrix(result)) {
        for (int i = 0; i < A->rows; i++)
          for (int j = 0; j < B->columns; j++)
            for (int k = 0; k < A->columns; k++)
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return status;
}
