#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = FAILURE;
  if (!s21_incorrect_matrix(A) && !s21_incorrect_matrix(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      status = SUCCESS;
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          if (labs(A->matrix[i][j] - B->matrix[i][j] > 1e-7)) status = FAILURE;
    }
  }
  return (status);
}
