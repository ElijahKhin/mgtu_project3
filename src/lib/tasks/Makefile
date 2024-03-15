NAME = tasks.a

SRC = task1.cc \
	  task2.cc \
	  task3.cc \
	  task4.cc

HEADER = tasks.h errors.h
TEST = tests/test_tasks.cc

OBJ_FOLDER = obj
OBJ = $(SRC:%.cc=$(OBJ_FOLDER)/%.o)

CLR = gcc
FLAGS = -std=c++17 -Werror -Wextra -Wall -I.

GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m
NO_COLOR = \x1b[0m
RESET = \033[0m


all: common_lib $(NAME)
.PHONY: all

$(NAME): ../common/common.a $(OBJ_FOLDER) $(OBJ)
	@ar rc $(NAME) obj/*
	@ranlib $(NAME)
	@printf "$(CURSIVE)Wait...⌛ $(YELLOW)%s$(NO_COLOR) was successfully assembled! %-37s" $(NAME)""
	@echo "\n"

common_lib:
	@make -C ../common/
.PHONY: common_lib

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.cc $(HEADER) Makefile
	@$(CLR) -c $(FLAGS) $< -o $@
	@printf "$(CURSIVE)Compiling source files 🚀... $(YELLOW)%-13s $(NO_COLOR)---> %17.33s ✅\r" $< $@

clean:
	@make clean -C ../common/
	@rm -rf obj
.PHONY: clean

fclean: clean
	@make fclean -C ../common/
	@rm -rf *.o *.a a.out .*.swp *.*.gch .DS_Store test_bin a.out.dSYM $(NAME)
	@echo "$(GRAY)$(CURSIVE)---$(NAME) staff is completely cleaned!\n"
.PHONY: fclean

re: fclean all
.PHONY: re

test: all
	@make test -C ../common/
	@g++ -std=c++17 $(TEST) $(NAME) ../common/common.a -lgtest -lgtest_main -pthread -o test_bin
.PHONY: test

leaks: test
	@make leaks -C ../common/
	@leaks -quiet --atExit -- ./test_bin
.PHONY: leaks

correct_format:
	@clang-format -i $(SRC) $(TEST) $(HEADER)
.PHONY: correct_format

dummy_test: all
	gcc -std=c++17 -c limit_test.cc && g++ -std=c++17 limit_test.o tasks.a ../common/common.a && ./a.out

check_format:
	@clang-format --dry-run --Werror $(SRC) $(TEST) $(HEADER)
.PHONY: check_format
