MAKEFLAGS       = --no-print-directory
.DEFAULT_GOAL   = all
THREAD_NUM    	= 4

NAME            = name


INC             = inc
INCLUDES        = $(foreach d, $(INC), -I$d)

CFLAGS          = -I$(INCLUDES) -Wall -Werror -Wextra
CC              = cc

SRC_DIR         = src/
SRC_NAME        = main.c

OBJ_DIR         = obj/
OBJ_NAME        = $(SRC_NAME:.c=.o)
DEPS_NAME       = $(SRC_NAME:.c=.d)
OBJ             = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
DEPS            = $(patsubst %, $(OBJ_DIR)%, $(DEPS_NAME))

all:
    @make -j$(THREAD_NUM) $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
    @mkdir -p $(dir $@)
    @$(CC) $(CFLAGS) $< -c -o $@
    @echo "\033[1;36m Compiled" $(*F)


$(NAME): $(OBJ)
    @$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
    @echo "\033[1;32m Executable" $(NAME) "created"

clean:
    @rm -rf $(OBJ_DIR)
    @echo "\033[1;31m Deleted all object files"

fclean: clean
    @rm -f $(NAME)
    @echo "\033[1;31m Deleted $(NAME)"


re: fclean all

-include $(DEPS)