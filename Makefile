SRC	 = ft_strlen.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr_int.c \
		ft_putnbr_uint.c \
		ft_putnbr_base.c 
		
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
RM = rm -f
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(OBJ) $(NAME)

re : fclean all
