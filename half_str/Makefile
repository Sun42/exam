NAME =half_str
SRC = half_str.c
CC = gcc
OBJ = $(SRC:.c=.o)
CFLAGS += -W -Wall -ansi -pedantic
RM = rm -f

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)
	$(RM) $(NAME) 

re : clean
	$(NAME)