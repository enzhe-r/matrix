#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;
  if (rows <= 0 || columns <= 0)
    status = INCORRECT_MATRIX;
  else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; i++)
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }
  return status;
}
