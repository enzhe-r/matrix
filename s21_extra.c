#include "s21_matrix.h"

void s21_get_minor_matrix(int A_rows, int A_columns, matrix_t *A,
                          matrix_t *A_minor) {
  int row_to_skip = 0, col_to_skip = 0;
  // s21_create_matrix(A->rows - 1, A->rows - 1, A_minor);
  for (int i = 0; i < A->rows - 1; i++) {
    if (i == A_rows) row_to_skip = 1;
    col_to_skip = 0;
    for (int j = 0; j < A->rows - 1; j++) {
      if (j == A_columns) col_to_skip = 1;
      A_minor->matrix[i][j] = A->matrix[i + row_to_skip][j + col_to_skip];
    }
  }
}

int s21_incorrect_matrix(matrix_t *X) {
  int status = 0;
  if (X == NULL || X->matrix == NULL || X->rows <= 0 || X->columns <= 0)
    status = 1;
  return status;
}

void s21_determinant_triangle(matrix_t *A, double *result) {
  *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
            A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
            A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1] -
            A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1] -
            A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2] -
            A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0];
}

// void s21_print_matrix(matrix_t *result) {
//   for (int i = 0; i < result->rows; i++) {
//     for (int k = 0; k < result->columns; k++) {
//       printf(" %.0f", result->matrix[i][k]);
//     }
//     printf("\n");
//   }
// }

double s21_big_determinant_handling(matrix_t *A) {
  double result = 0.0;
  matrix_t A_minor = {0};
  int i = 0;
  if (A->rows == 3)
    s21_determinant_triangle(A, &result);
  else {
    if (!s21_create_matrix(A->rows - 1, A->columns - 1, &A_minor)) {
      for (i = 0; i < A->columns; i++) {
        s21_get_minor_matrix(0, i, A, &A_minor);
        if (i % 2)
          result += -A->matrix[0][i] * s21_big_determinant_handling(&A_minor);
        else
          result += +A->matrix[0][i] * s21_big_determinant_handling(&A_minor);
      }
      s21_remove_matrix(&A_minor);
    }
  }
  return result;
}
