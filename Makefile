# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 13:25:21 by lbordana          #+#    #+#              #
#    Updated: 2025/12/25 09:09:01 by lbordanave       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = push_swap.c lst_utils.c benchmark.c testing_unit.c push.c swap.c rotate.c reverse_rotate.c simple.c medium.c complex.c adaptive.c 
LIBFT = libft/libft.a
OBJDIR = objects/
OFILES = $(FILES:%.c=$(OBJDIR)%.o)


all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBFT)

$(OBJDIR)%.o: algorithm/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(OBJDIR)%.o: moves/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

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
