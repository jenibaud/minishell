NAME = minishell

INCLUDES = inc/
LIBFTPATH = $(INCLUDES)libft/
LIBFTA = $(LIBFTPATH)libft.a

CLIBS = -lreadline
CFLAGS = -I$(INCLUDES) -Wall -Werror -Wextra -g
CC = cc

SRC_DIR = src/
SRC_NAME =	minihell.c\
			built-ins/pwd.c\
			built-ins/exit.c\
			built-ins/echo.c\
			built-ins/cd.c\
			built-ins/env.c\
			built-ins/cd_utils.c\
			built-ins/export.c\
			built-ins/unset.c\
			built-ins/export_utils.c

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)


$(NAME): $(OBJ)
	@make --no-print-directory -C $(LIBFTPATH)
	@$(CC) $(CFLAGS) $(CLIBS) -o $(NAME) $(OBJ) $(LIBFTA)
	@echo "\033[1;32m Executable" $(NAME) "created"

clean:
	@cd $(LIBFTPATH) && make clean --no-print-directory
	@rm -rf $(OBJ_DIR) $(LIBFTA)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@cd $(LIBFTPATH) && make fclean --no-print-directory
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all

.PHONY: re all fclean clean bonus