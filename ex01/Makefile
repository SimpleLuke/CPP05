BIN = bin
NAME = Form
CC = c++
CFLAG = -Wall -Werror -Wextra -std=c++98 -g3
SRC = src/Bureaucrat.cpp \
	  src/Form.cpp \
	  src/main.cpp
OBJ = $(SRC:src/%cpp=$(BIN)/%o)
INCS = ./includes
IFLAGS = -I $(INCS)
UNAME := $(shell uname)
RM = rm -rf

all: $(NAME)

$(BIN)/%.o: src/%.cpp
	$(CC) -c $< $(CFLAG) $(IFLAGS) -o $@

$(NAME): $(BIN) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(BIN):
	mkdir -p $(BIN)

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)

.PHONY: all clean fclean re
