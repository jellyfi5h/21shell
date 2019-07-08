# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 22:15:16 by aboukhri          #+#    #+#              #
#    Updated: 2019/05/19 13:08:24 by aboukhri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libft.a
SRC=convert_binary.c field_width.c ft_atoi.c ft_bzero.c ft_chrjoin.c ft_chrlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstcat.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_lstrev.c ft_lstsearch.c ft_lstsplit.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_power.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_remalloc.c ft_strcat.c ft_strchr.c ft_strchrindex.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strdupfree.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoinfree.c ft_strlcat.c ft_strlen.c ft_strlower.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrdel.c ft_strrev.c ft_strsplit.c  ft_strstr.c ft_strstrindex.c ft_strsub.c ft_strtrim.c ft_strtrim_quote.c ft_strupper.c ft_tolower.c ft_toupper.c ft_utoa.c ft_dbl_strdup.c ft_dbl_strdel.c ft_strsplit_quote.c err_putchar.c ft_realloc_double.c ft_realloc.c ft_dbl_strlen.c ft_strrchrindex.c ft_put_dblstr.c str_isalnum.c ft_chrlen_quote.c ft_strchr_quote.c

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
