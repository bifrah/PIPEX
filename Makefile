NAME = pipex
CC = gcc
PARAMS = -Wall -Wextra -Werror

INC_PATH = includes/
OBJ_PATH = obj/
SRC_PATH = srcs/

INC_NAME = pipex.h
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME =	main.c \
			ft_count.c \
			ft_print.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strdup.c \
			ft_strnstr.c \
			util00.c \
			bin.c \
			parser.c \
			exec.c

INC= -I $(INC_PATH)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[pipex] : $(DEF)Compilation..."
	@$(CC) $(PARAMS) $(OBJ) -o $(NAME) $(INC)
	@echo "$(RED)[pipex] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[pipex] :$(DEF) Compiling $@"
	@$(CC) $(PARAMS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[pipex] : $(DEF)Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[pipex] : $(DEF)Full Cleaning               $(GRN)[OK]$(DEF)"

re: fclean all
