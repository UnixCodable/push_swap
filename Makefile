# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 13:25:21 by lbordana          #+#    #+#              #
#    Updated: 2026/01/20 14:48:23 by lbordana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
FILES = push_swap.c lst_utils.c benchmark.c push.c swap.c rotate.c\
		reverse_rotate.c simple.c medium.c complex.c adaptive.c utils_medium.c\
		utils_complex.c utils_shared.c
FILES_BONUS = lst_utils.c benchmark.c push.c swap.c rotate.c\
		reverse_rotate.c get_next_line.c get_next_line_utils.c checker.c
LIBFT = libft/libft.a
OBJDIR = objects/
OBJDIR_BONUS = objects_bonus/
OFILES = $(FILES:%.c=$(OBJDIR)%.o)
OBONUS_FILES = $(FILES_BONUS:%.c=$(OBJDIR_BONUS)%.o)
PINK_BCK = \e[7;1;35m
GREEN_BCK = \e[7;1;32m
RED_BCK = \e[7;1;91m
NORMAL = \e[0m
GREEN = \e[1;32m
TOTAL = 14
INDEX = 1


all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBFT)
	printf "\n\n"

$(OBJDIR)%.o: algorithm/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\n$(PINK_BCK)Building $@"

$(OBJDIR)%.o: moves/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\n$(PINK_BCK)Building $@"

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\n$(PINK_BCK)Building $@"

$(LIBFT):
	@make -C libft > /dev/null

$(OBJDIR):
	mkdir $(OBJDIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJDIR_BONUS) $(OBONUS_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBONUS_FILES) $(LIBFT)

$(OBJDIR_BONUS)%.o: get_next_line/%.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\n$(PINK_BCK)Building $@"

$(OBJDIR_BONUS)%.o: moves/%.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\n$(PINK_BCK)Building $@"

$(OBJDIR_BONUS)%.o: %.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\n$(PINK_BCK)Building $@"

$(OBJDIR_BONUS):
	mkdir $(OBJDIR_BONUS)

clean:
	rm -rf objects/
	rm -rf objects_bonus/
	@make clean -C libft > /dev/null
	printf "\n$(RED_BCK)Deleted objects files.$(NORMAL)\n\n"


shuf_low_500: $(NAME)
	-./push_swap --low-disorder $$(shuf -i 0-1000 -n 500)

shuf_low_100: $(NAME)
	-./push_swap --low-disorder $$(shuf -i 0-1000 -n 100)

shuf_med_500: $(NAME)
	-./push_swap --med-disorder $$(shuf -i 0-1000 -n 500)

shuf_med_100: $(NAME)
	-./push_swap --med-disorder $$(shuf -i 0-1000 -n 100)

git_clean:
	git rm -rf objects/
	git rm -rf objects_bonus/
	git rm -rf push_swap
	git rm -rf checker
	git rm -rf libft/mandatory_objects/
	git rm -rf libft/libft.a

fclean:
	rm -rf objects/
	rm -rf objects_bonus/
	rm -rf checker
	rm -rf push_swap
	@make fclean -C libft > /dev/null
	printf "\n$(RED_BCK)Deleted objects files and archive.$(NORMAL)\n\n"

re: fclean all

.PHONY: all clean fclean re
