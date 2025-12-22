# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 13:25:21 by lbordana          #+#    #+#              #
#    Updated: 2025/12/22 14:55:48 by lbordana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = push_swap.c lst_utils.c
LIBFT = libft/libft.a
OBJDIR = objects/
OFILES = $(FILES:%.c=$(OBJDIR)%.o)


all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBFT)


$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@make -C libft > /dev/null

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf objects/
	@make clean -C libft > /dev/null

fclean:
	rm -rf objects/
	rm -rf push_swap
	@make fclean -C libft > /dev/null

re: fclean all
