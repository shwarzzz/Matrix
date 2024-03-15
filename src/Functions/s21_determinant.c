#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = s21_matrix_correct_check(A);
  *result = 0;
  if (!res) {
    if (A->columns == A->rows) {
      *result = s21_find_determin(A, A->columns);
    } else {
      res = CALCULATION_ERROR;
    }
  }
  return res;
}

double s21_find_determin(matrix_t *A, int n) {
  double d = 0;
  if (n == 1) {
    d = A->matrix[0][0];
  } else if (n == 2) {
    d = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(n - 1, n - 1, &tmp);
    for (int k = 0; k < n; k++) {
      for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
          if (j != k) {
            tmp.matrix[i - 1][t] = A->matrix[i][j];
            t++;
          }
        }
      }
      d += pow(-1, k) * A->matrix[0][k] * s21_find_determin(&tmp, n - 1);
    }
    s21_remove_matrix(&tmp);
  }
  return d;
}