.PHONY: s21_matrix.a
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror


ifeq ($(shell uname), Linux)
 CHECKFLAGS=-lcheck -lm -lpthread -lrt -lsubunit
else
 CHECKFLAGS=-lcheck -lm -lpthread
endif

all: s21_matrix.a

s21_matrix.a:
	$(MAKE) clean
	$(CC) $(CFLAGS) -c *.c
	ar rc s21_matrix.a *.o 

test: s21_matrix.a 
	$(CC) $(CFLAGS) tests/*.c $(CHECKFLAGS) s21_matrix.a -o s21_test_runner 
	./s21_test_runner 

gcov_report:
	$(CC) $(FLAGS) --coverage tests/*.c *.c  -o gcov_report $(CHECKFLAGS)
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info --no-external -c -d .
	genhtml -o rpn_report gcov_report.info
	open ./rpn_report/index.html

style: 
	cppcheck *.h *.c
	clang-format -style=Google -n *.c *.h

clang:
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i tests/*.c tests/*.h

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes ./s21_test_runner

clean:
	rm -rf *.o *.a report *.gcno *.gcda *.info *.txt gcov_report test rpn_report s21_test_runner 

