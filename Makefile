NAME = pipex

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

LFT_SRC = ./includes/lft
SRC = ./source
UTILS_SRC = ./source/utils
GNL_SRC = ./includes/gnl/

PS_FILES = $(wildcard $(SRC)/*.c) $(wildcard $(UTILS_SRC)/*.c) $(wildcard $(LFT_SRC)/*.c)
OBJS = ${PS_FILES:.c=.o}

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o ${NAME}

clean : 
	@$(RM) ${OBJS}

fclean : clean
	$(RM) ./$(NAME)

re : fclean all