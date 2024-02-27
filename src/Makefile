NAME = mini_console_p3

PREREQUISITE_P3 = \
				  Makefile \
				  messages.h \
				  colors.h

SRC = main.cc

OBJ_FOLDER = obj
OBJ = $(SRC:%.cc=$(OBJ_FOLDER)/%.o)

CLR = g++
FLAGS = -std=c++17 -Werror -Wextra -Wall -I./tasks/

GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m
NO_COLOR = \x1b[0m
RESET = \033[0m


all: tasks_lib $(NAME)

$(NAME): tasks/tasks.a $(OBJ_FOLDER) $(OBJ)
	@$(CLR) $(FLAGS) $(OBJ_FOLDER)/*.o -L. \
		tasks/$(NAME).a -o $(NAME)
	@echo "----------------------------------------------------------\n"
	@printf "$(CURSIVE)Assembling $(NAME) ⚙️ ... $(GREEN)DONE! 🥂$(RESET)"
	@echo "\n"

tasks_lib:
	@make -C tasks/
.PHONY: tasks_lib

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)


$(OBJ_FOLDER)/%.o: %.cc $(PREREQUISITE_P3)
	@$(CLR) -c $(FLAGS) $< -o $@


clean:
	@make clean -C tasks/
	@rm -rf obj
.PHONY: clean

fclean: clean
	@make fclean -C tasks/
	@rm -rf *.a a.out .*.swp *.*.gch .DS_Store test_bin a.out.dSYM $(NAME)
	@echo "$(GRAY)$(CURSIVE)---$(NAME) staff is completely cleaned!\n"

.PHONY: fclean

re: fclean all
.PHONY: re

test: all
	@make test -C tasks/
.PHONY: test

leaks: test
	@make leaks -C tasks/
.PHONY: leaks
