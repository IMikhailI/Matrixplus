CC=g++
CFLAGS= -Wall -Werror -Wextra -std=c++17
LFLAGS=-lgtest -lm
LIBNAME=s21_matrix_oop.a

SRC=$(wildcard function_matrix/*.cc)
OBJ=$(patsubst %.cc, %.o,$(SRC))

TESTSRC=$(wildcard tests/*.cc)
TESTOBJ=$(patsubst %.cc, %.o,$(TESTSRC))


all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	ar -rcs $(LIBNAME) $(OBJ)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJ) $(TESTOBJ)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@
	./test

gcov_report: CFLAGS += --coverage
gcov_report: test
	lcov -d . --capture --output-file coverage.info
	lcov --remove coverage.info '/usr/*' '*/gtest/*' '*/tests/*' --output-file coverage.info.cleaned
	genhtml coverage.info.cleaned --output-directory coverage_report
	open coverage_report/index.html

clang-n:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -n *.h **/*.cc **/*.h
	@rm ./.clang-format

clang-i:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.h **/*.cc **/*.h
	@rm ./.clang-format
	
valgrind-test: test
	clear
	valgrind --tool=memcheck --leak-check=yes ./test

cppcheck:
	cppcheck cppcheck --enable=all --suppress=missingIncludeSystem ../src

.PHONY: clean

clean:
	rm -f test .clang-format *.a **/*.o 
	rm -f **/*.gcno **/*.gcda **/*.gcov *.info *.gcda *.gcno *.out *.cleaned
	rm -rf coverage_report
	
