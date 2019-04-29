##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

SRC_DIR	=	src/
INC_DIR	=	include/
TESTS_DIR	=	tests/

TARGET	=	solver

CFLAGS	=	-g -Wall -Wextra -I $(INC_DIR)

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)my_str_to_word_array.c	\
		$(SRC_DIR)error.c	\
		$(SRC_DIR)new_algo.c \

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(TARGET)

# `make` normal
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

# `make clean` clean lib/*.o + projet
clean:
	$(RM) $(OBJ)

# `make clean` clean + binary/library
fclean: clean
	$(RM) $(TARGET)

# `make tests_run` criterion
tests_run:
	make re -C $(TESTS_DIR)

re:	fclean all

.PHONY: all clean fclean re
