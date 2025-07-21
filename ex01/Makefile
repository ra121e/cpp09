# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 17:48:04 by athonda           #+#    #+#              #
#    Updated: 2025/07/21 21:17:49 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	RPN

SRC_F	=	main.cpp
SRC_DIR	=	.
SRC		=	$(SRC_F:%.cpp=$(SRC_DIR)/%.cpp)

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_F))

INC_DIR	=	.
DEP		=	$(wildcard $(patsubst %.cpp, $(INC_DIR)/%.hpp, $(SRC_F)))

IFLAGS	=	-I$(INC_DIR)
CFLAGS	=	-g -Wall -Wextra -Werror -std=c++98
CC		=	c++

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

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

norm:
	clear
	nm -u $(NAME)
	grep -n -e "printf" -e "alloc" -e "free" $(SRC) $(DEP) || true