gcc = gcc -std=c11 -g -Wall -Werror -Wextra 

HEAD = s21_stack.h

c_files = $(shell find . -name "s21*.c")
o_files = $(shell find . -name "s21*.o")

test_c_files = $(shell find . -name "test*.c")
test_o_files = $(shell find . -name "test*.o")

functionsForTest = ./Backend/s21_solver.c ./Backend/s21_parser.c ./Stack/s21_stack.c ./Backend/s21_validation.c

CHECK_FLAGS = -lcheck -pthread -lrt -lsubunit -lm
GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`

ifeq ($(shell uname -s), Mac)
CHECK_FLAGS = -lcheck
endif

all: build

install: uninstall all
	mkdir ./SmartCalc/
	install ./main ./SmartCalc/SmartCalc

uninstall:
	rm -rf ./SmartCalc/

# open Doxyfiles/html/index.html
dvi:
	rm -rf Doxyfiles
	doxygen Doxyfile

dist: clean
	mkdir -p ./Archive/
	cp -r ./Backend/ ./Archive/
	cp -r ./Frontend/ ./Archive/
	cp -r ./Stack/ ./Archive/
	cp -r ./Tests/ ./Archive/
	cp -r s21_main.c ./Archive/
	cp -r SmartCalc.h ./Archive/
	cp Makefile ./Archive/
	tar -czvf SmartCalc.tar.gz ./Archive/
	rm -rf Archive/

test: clean functionsTest gcov_report
	./test

# xdg-open ./report/index.html
gcov_report: functionsTest 
	gcc --coverage $(test_c_files) $(functionsForTest) -o s21_test $(CHECK_FLAGS) 
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info

functionsTest:
	$(gcc) $(test_c_files) $(functionsForTest) -o test $(CHECK_FLAGS)

valgrind: test
	valgrind --tool=memcheck --leak-check=yes ./s21_test

clang-repair:
	clang-format -i -style=Google *.c
	clang-format -i -style=Google Backend/*.c
	clang-format -i -style=Google Frontend/*.c
	clang-format -i -style=Google Stack/*.c

clang-check:
	clang-format -n -style=Google *.c
	clang-format -n -style=Google Backend/*.c
	clang-format -n -style=Google Frontend/*.c
	clang-format -n -style=Google Stack/*.c

clean:
	rm -rf main test s21_test *.info *.gcno *.gcda report
	rm -rf ./Archive/
	rm -rf ./Doxyfiles/
	rm -rf *.tar.gz

build:
	$(gcc) $(c_files) -o main -lm $(GTK_FLAGS)

rebuild: clean build