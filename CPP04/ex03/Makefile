CXX:=g++ -std=c++98
CPPFLAGS:= -Wall -Werror -Wextra -Wshadow -g3 -fsanitize=address
RM:=rm -rf

NAME = ex03

SRC_FILES = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp

SRC_OBJECTS := $(patsubst %.cpp, %.o, $(SRC_FILES))

all: $(NAME)

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) -o $@

$(NAME): $(SRC_OBJECTS)
	$(CXX) $(CPPFLAGS) -o $@ $^

clean:
	@$(RM) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re