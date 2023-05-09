##
## EPITECH PROJECT, 2022
## B-CPE-101-LYN-1-1-myprintf-axel.petitjean
## File description:
## Makefile
##

SRC	=	my_putchar.c \
		my_ls.c \
		my_putstr.c \
		my_put_nbr.c \
		main.c \
		lsa.c \
		my_printf.c \
		lsd.c \
		my_strlen.c \
		ls_autre.c \
		my_lsl.c \

NAME = my_ls



all:	$(NAME)

$(NAME):
		gcc -o my_ls $(SRC) -w -g3
clean:
		rm $(NAME)

fclean: clean
		rm -f *.a $(NAME)

re:		fclean all
