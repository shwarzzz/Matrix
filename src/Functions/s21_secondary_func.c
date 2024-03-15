#include "../s21_matrix.h"

int s21_matrix_correct_check(matrix_t *src) {
  int res = OK;
  if (src == NULL || src->columns <= 0 || src->rows <= 0) {
    res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_calculation_error_check(matrix_t *a, matrix_t *b) {
  int res = OK;
  if (!s21_matrix_correct_check(a) && !s21_matrix_correct_check(b)) {
    if (a->columns != b->columns || a->rows != b->rows) {
      res = CALCULATION_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_before_mult_check(matrix_t *A, matrix_t *B) {
  int res = OK;
  if (!s21_matrix_correct_check(A) && !s21_matrix_correct_check(B)) {
    if (A->columns != B->rows) {
      res = CALCULATION_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}