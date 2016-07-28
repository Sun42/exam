NAME = count_islands
CC = gcc
SRC = count_islands.c
OBJ = $(SRC:.c=.o)
RM = `rm -f`

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean : $(RM) $(OBJ)
	$(RM) $(NAME)

all : $(NAME)

re : clean all