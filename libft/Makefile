# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 14:44:11 by lbordana          #+#    #+#              #
#    Updated: 2025/12/09 11:51:03 by lbordana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJDIR = mandatory_objects/
BONUSDIR = bonus_objects/
PINK_BCK = \033[7;1;35m
GREEN_BCK = \033[7;1;32m
RED_BCK = \033[7;1;91m
NORMAL = \033[0m
GREEN = \033[1;32m
OFILES = $(CFILES:%.c=$(OBJDIR)%.o)
BONUSFILES = $(BONUS:%.c=$(BONUSDIR)%.o)

all: cleaning $(NAME)

$(NAME): $(OBJDIR) $(OFILES)
	ar rcs $(NAME) $(OFILES)
	printf "\n\n$(GREEN_BCK)Archive compiled.\n\n$(NORMAL)"

bonus: $(BONUSFILES) $(BONUSDIR)
	ar rcs $(NAME) $(BONUSFILES)
	printf "\n\n$(GREEN_BCK)Bonus added to archive.\n\n$(NORMAL)"

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\r$(PINK_BCK)Building objects files..."
	sleep 0.05

$(BONUSDIR)%.o: %.c | $(BONUSDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\r$(PINK_BCK)Building objects files..."
	sleep 0.05

$(OBJDIR):
	mkdir -p $@
	printf "$(PINK_BCK)Mandatory objects folder created.\n\n"

$(BONUSDIR):
	mkdir -p $@
	printf "\n$(PINK_BCK)Bonus objects folder created.\n\n"

cleaning:
	printf "\033[2J\033[H"
	printf "\n$(NORMAL)--------------------------------------------------------------------------------\n"
	printf "\n$(GREEN)TIPS : use $(PINK_BCK)'make test_libft'$(NORMAL)$(GREEN) to automatically launch two tester on the functions\n\n"
	printf "$(NORMAL)--------------------------------------------------------------------------------\n\n"
	sleep 2

clean:
	rm -rf $(OBJDIR) $(BONUSDIR)
	printf "\n$(RED_BCK)Deleted objects files.$(NORMAL)\n\n"

fclean:
	rm -rf $(OBJDIR) $(BONUSDIR) $(NAME)
	printf "\n$(RED_BCK)Deleted objects files and archive.$(NORMAL)\n\n"

test_libft:
	git clone https://github.com/Blaeste/libfterator
	git clone https://github.com/UnixCodable/libftTester
	cd libftTester && make
	cd ..
	libfterator/tester.py ./
	rm -rf libftTester/
	rm -rf libfterator/

re: fclean all

.PHONY: all clean fclean re bonus
