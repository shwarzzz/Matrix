CC = gcc
FLAGS = -Wall -Werror -Wextra
LFLAGS = -lcheck
SRC = Functions/s21*.c
OBJ =*.o

ifeq ($(shell uname), Linux)
  LFLAGS += -pthread -lsubunit -lrt -lm
endif

all: clean test

test: s21_matrix.a
	$(CC) $(FLAGS) -c matrix_test.c
	$(CC) matrix_test.o $(FLAGS) $(LFLAGS) -L. s21_matrix.a -o test

s21_matrix.a:
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs s21_matrix.a $(OBJ)
	ranlib s21_matrix.a
	rm -rf *.o

add_coverage:
	$(eval FLAGS += --coverage)

gcov_report: clean add_coverage test
	-./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clean: 
	rm -rf *.o *.a *.gcno *.gcda test test.info report

rebuild: clean all