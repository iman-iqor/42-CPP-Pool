NAME        = harl
SRC         = main.cpp Harl.cpp
OBJ         = $(SRC:.cpp=.o)

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98



all: $(NAME)
%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re