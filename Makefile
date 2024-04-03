# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:10:19 by aloubier          #+#    #+#              #
#    Updated: 2023/10/02 16:16:15 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = LinearRegression

SRC_DIR = ./

INC_DIR = ./

OBJ_DIR = build/

SRC_FILES = main.cpp \
			LinearRegression.cpp \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.cpp=.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = c++ 

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p '$(OBJ_DIR)'
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
