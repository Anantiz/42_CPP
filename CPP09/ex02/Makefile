CXX:=c++ -std=c++98
CPPFLAGS:= -Wall -Werror -Wextra -g3 -Wshadow
RM:=rm -rf

NAME = PmergeMe

SRC_FILES = main.cpp PmergeMe.cpp

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
