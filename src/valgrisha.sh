g++ -Wall -Werror -Wextra -std=c++17 -lstdc++ --coverage tests/*.cc -lgtest -g -o test
valgrind --tool=memcheck --leak-check=yes ./test