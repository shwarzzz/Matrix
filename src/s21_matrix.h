#ifndef S21_MATRIX_H

#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

// sec_func
int s21_matrix_correct_check(matrix_t* src);
int s21_calculation_error_check(matrix_t* a, matrix_t* b);
int s21_before_mult_check(matrix_t* A, matrix_t* B);
double s21_find_determin(matrix_t* A, int n);
double s21_find_minors_determ(matrix_t* A, int i, int j);

#endif