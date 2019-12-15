# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 12:37:39 by mbuch             #+#    #+#              #
#    Updated: 2019/12/14 15:39:21 by mbuch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_retro

SRCS			:= main.cpp \
			Vect2.cpp \
			Elem.cpp \
			List.cpp \
			GameObject.cpp \
			GameEntity.cpp \
			Projectile.cpp \
			Player.cpp \
			Enemy.cpp \
			Engine.cpp

PATH_OBJ	:= ./obj
PATH_SRC	:= ./src

CC			:= clang++

CFLAGS		:= -Wall -Wextra -Werror -pedantic -std=c++98 -O3 -march=native -pipe -flto
OBJS		:= $(addprefix $(PATH_OBJ)/,$(SRCS:.cpp=.o))
DEBUG		:= -g -O0

.PHONY: all

all: $(PATH_OBJ) $(NAME)

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

$(PATH_OBJ)/%.o:$(PATH_SRC)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) -lncurses

clean:
	@rm -f $(OBJS)
	@echo Delete $(words $(OBJS)) object file

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re $(NAME)
