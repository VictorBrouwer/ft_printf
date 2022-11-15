NAME	=	libftprintf.a
SRC		=	ft_printf.c \
			helpers.c \
			hex_helpers.c \
			num_helpers.c

HEADER	=	ft_printf.h
OBJ		=	$(SRC:.c=.o)
CC		=	gcc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	ar -crs $@ $^

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all