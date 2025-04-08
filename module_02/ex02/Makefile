NAME = Fixed

TEST = test

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

TEST_SRC = Fixed.cpp test.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re