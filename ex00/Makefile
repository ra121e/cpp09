# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 15:27:00 by athonda           #+#    #+#              #
#    Updated: 2025/11/27 16:31:00 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btc


SRC_F	= 	main.cpp \
			BitcoinExchange.cpp \
			DateOfStartChecker.cpp \
			Date.cpp \
			DateFormatChecker.cpp \
			BaseDataFile.cpp \
			HistoricalDataFileCSV.cpp \
			InputDataFilePip.cpp \
			RateFinder.cpp \
			IMapAPI.cpp

SRC_DIR	=	.
SRC		=	$(SRC_F:%.cpp=$(SRC_DIR)/%.cpp)

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_F))

INC_DIR	=	.
DEP		=	$(wildcard $(patsubst %.cpp,$(INC_DIR)/%.hpp,$(SRC_F)))

CC		=	c++
CFLAGS	=	-g -Wall -Werror -Wextra -std=c++98
IFLAGS	=	-I$(INC_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)
test: $(OBJ_DIR)/RateFinder.o $(OBJ_DIR)/tests/test_ratefinder.o $(OBJ_DIR)/tests/test_runner.o
	@mkdir -p $(OBJ_DIR)/tests
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ_DIR)/RateFinder.o $(OBJ_DIR)/tests/test_ratefinder.o $(OBJ_DIR)/tests/test_runner.o -o $(OBJ_DIR)/tests/test_runner
	./$(OBJ_DIR)/tests/test_runner

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	clear
	nm -u $(NAME)
	grep -n -e "printf" -e "alloc" -e "free" $(SRC) $(DEP) | true
