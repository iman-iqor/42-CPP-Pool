NAME = phonebook 
# Use the correct source filename (case-sensitive filesystem)
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)
CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)
%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re