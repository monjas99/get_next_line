NAME = gnl
RM = rm -f

CC = gcc
FLAGS = -Wall -Wextra -Werror -o

MY_SRC = main.c get_next_line.c get_next_line_utils.c
MY_OBJ = $(MY_SRC:.c=.o)
INCLUDE = get_next_line.h

$NAME: $(MY_OBJ)
	$(CC) $(FLAGS) $(NAME) $(MY_OBJ)
clean:
	$(RM) $(NAME) $(MY_OBJ)
