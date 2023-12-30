# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 14:06:37 by pruiz-ca          #+#    #+#              #
#    Updated: 2021/02/21 16:11:46 by pruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	src/ft_printf.c src/flags.c src/utils.c \
				src/conv_str.c src/conv_int.c

OBJS		=	$(SRCS:.c=.o)

HEADER		=	inc/ft_printf.h

CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	lib

all:						$(NAME)

$(NAME):					$(OBJS)
							@make -C $(LIBFT)
							@cp lib/libft.a ./libftprintf.a
							@ar rcs $(NAME) $(OBJS)

$(src)%.o: $(src)%.c		$(HEADER)
							@gcc $(CFLAGS) -include $(HEADER) -o $@ -c $<

clean:
							@rm -f $(OBJS)
							@make clean -C $(LIBFT)


fclean:						clean
							@rm -f $(NAME)
							@make fclean -C $(LIBFT)

re:							fclean all

.PHONY:						all clean fclean re
