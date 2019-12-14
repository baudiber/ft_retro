# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 12:37:39 by mbuch             #+#    #+#              #
#    Updated: 2019/12/14 11:50:46 by mbuch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_retro

SRCS			= main.cpp \
			Vect2.cpp \
			Elem.cpp \
			List.cpp \
			GameObject.cpp \
			GameEntity.cpp \
			Projectile.cpp \
			Enemy.cpp \
			Engine.cpp

PATH_OBJ	= obj
PATH_SRC	= src

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror
OBJECTS		= $(patsubst %.cpp, $(PATH_OBJ)/%.o, $(SRCS))
DEBUG		= -g -O0

.PHONY: all

all: $(NAME)

$(NAME): $(OBJECTS)
	@(CC) -o $@ $(OBJECTS) -lncurses

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.cpp)
	@mkdir -p $(PATH_OBJ)
	$(CC) -c -o $@ $(CFLAGS) $^ 

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

