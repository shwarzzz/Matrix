#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = s21_before_mult_check(A, B);
  if (!res) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int k = 0; k < result->rows; k++) {
      for (int i = 0; i < result->columns; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[k][i] += A->matrix[k][j] * B->matrix[j][i];
        }
      }
    }
  }
  return res;
}