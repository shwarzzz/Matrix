#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = s21_matrix_correct_check(A);
  if (!res) {
    if (A->columns == A->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] =
              pow(-1, i + j) * s21_find_minors_determ(A, i, j);
        }
      }
    } else {
      res = CALCULATION_ERROR;
    }
  }
  return res;
}

double s21_find_minors_determ(matrix_t *A, int i, int j) {
  double det = 0;
  if (A->columns == 1) {
    det = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    int q = 0;
    for (int x = 0; x < A->rows; x++) {
      int t = 0;
      if (x == i) continue;
      for (int y = 0; y < A->columns; y++) {
        if (y != j) {
          tmp.matrix[q][t] = A->matrix[x][y];
          t++;
        }
      }
      q++;
    }
    det = s21_find_determin(&tmp, tmp.columns);
    s21_remove_matrix(&tmp);
  }
  return det;
}
