NAME = inter
CC = gcc
SRC = inter.c
OBJ = $(SRC:.c=.o)
RM = `rm -f`

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean : 
	$(RM) $(OBJ)
	$(RM) $(NAME)

all : $(NAME)

re : clean all