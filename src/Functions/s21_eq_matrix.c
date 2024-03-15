#include "../s21_matrix.h"
#define EPS 10000000

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = FAILURE;
  int stop = 0;
  if (A && B) {
    if (A->columns == B->columns && A->rows == B->rows) {
      for (int i = 0; !stop && i < A->rows; i++) {
        for (int j = 0; !stop && j < A->columns; j++) {
          int sign = 1;
          if (A->matrix[i][j] < 0) {
            sign = -1;
          }
          long double a = floor(A->matrix[i][j] * EPS * sign);
          long double b = floor(B->matrix[i][j] * EPS * sign);
          if (a != b) {
            stop++;
          }
        }
      }
      if (!stop) {
        res = SUCCESS;
      }
    }
  }
  return res;
}