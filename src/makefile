CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
CLANG = clang-format --style=Google
CLANG_FILES = **/*.tpp **/*.h tests/*.cc 

test: clean
	$(CC) $(CFLAGS) --coverage tests/*.cc -lgtest -g -o test
	./test

gcov_report: test
	lcov --ignore-errors mismatch -t test -o rep.info -c -d .
	lcov --remove rep.info '/usr/local/include/c++/13/*' -o rep.info
	genhtml -o report rep.info
	open report/index.html

valgrind: 
	docker build -t cont .
	docker run --name stock cont

style_check:
	$(CLANG) -n $(CLANG_FILES)
	
clang:
	$(CLANG) -i $(CLANG_FILES)

clean:
	rm -rf test *.o *.a *.gcda *.gcno rep.info report *.dSYM *.out
	
clear:
	docker rm stock
	docker rmi cont