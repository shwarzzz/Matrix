#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = s21_matrix_correct_check(A);
  if (!res) {
    if (A->rows == A->columns) {
      double det = s21_find_determin(A, A->rows);
      if (det != 0) {
        if (A->rows == 1) {
          s21_create_matrix(A->columns, A->rows, result);
          result->matrix[0][0] = 1 / det;
        } else {
          matrix_t algdop = {0};
          res = s21_calc_complements(A, &algdop);
          matrix_t talgdop = {0};
          s21_transpose(&algdop, &talgdop);
          det = 1 / det;
          res = s21_mult_number(&talgdop, det, result);
          s21_remove_matrix(&algdop);
          s21_remove_matrix(&talgdop);
        }
      } else {
        res = CALCULATION_ERROR;
      }
    } else {
      res = CALCULATION_ERROR;
    }
  }
  return res;
}