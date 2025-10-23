NAME        = megaphone
SRC         = megaphone.cpp
OBJ         = $(SRC:.cpp=.o)

CPP         = g++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98



all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re