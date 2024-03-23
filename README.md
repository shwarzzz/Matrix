# Matrix Library

В данном проекте была реализована библиотека для обработки числовых матриц на языке программирования Си. Матрицы являются одной из базовых структур данных в программировании.  

## Операции над матрицами

Все операции (кроме сравнения матриц) возвращают результирующий код:  
- 0 - OK
- 1 - Ошибка, некорректная матрица   
- 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)

### Создание матриц (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Очистка матриц (remove_matrix)

```c
void s21_remove_matrix(matrix_t *A);
```

### Сравнение матриц (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
```

Две матрицы A, B совпадают |A = B|, если совпадают их размеры и соответствующие элементы равны, то есть при всех i, j A(i,j) = B(i,j).


### Сложение (sum_matrix) и вычитание матриц (sub_matrix)

```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)

```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Транспонирование матрицы (transpose)

```c
int s21_transpose(matrix_t *A, matrix_t *result);
```

### Минор матрицы и матрица алгебраических дополнений (calc_complements)

```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```

### Определитель матрицы (determinant)

```c
int s21_determinant(matrix_t *A, double *result);
```

### Обратная матрица (inverse_matrix)

```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

## Требования к проекту

- При написании кода необходимо придерживаться Google Style;
- Оформить решение как статическую библиотеку;
- Библиотека должна быть разработана в соответствии с принципами структурного программирования;
- Подготовить полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check;
- Предусмотреть Makefile для сборки библиотеки и тестов.

## Запуск проекта

- Для сборки статической библиотеки необходимо выполнить команду:
```bash
make all
```
- Для запуска тестов выполните следующие команды:
```bash
make test
./test
```
- Для просмотра покрытия кода в терминале выполните команду:
```bash
make gcov_report
```