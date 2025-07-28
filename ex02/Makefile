# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 17:10:29 by athonda           #+#    #+#              #
#    Updated: 2025/07/28 16:40:24 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

SRC_F	=	main.cpp \
			Pmergeme.cpp
SRC_DIR	=	.
SRC		=	$(SRC_F:%.cpp=$(SRC_DIR)/%.cpp)

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_F))

INC_DIR	=	.
DEP		=	$(wildcard $(patsubst %.cpp,$(INC_DIR)/%.hpp, $(SRC_F)))

IFLAGS	=	-I$(INC_DIR)
CFLAGS	=	-g -Wall -Wextra -Werror -std=c++98
CC		=	c++

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
