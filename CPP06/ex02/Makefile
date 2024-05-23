CXX:=c++ -std=c++98
CPPFLAGS:= -Wall -Werror -Wextra -g3 -Wshadow
RM:=rm -rf

NAME = a.out

SRC_FILES = main.cpp Base.cpp foo.cpp

SRC_OBJECTS := $(patsubst %.cpp, %.o, $(SRC_FILES))

all: test fclean

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) -o $@

$(NAME): $(SRC_OBJECTS)
	$(CXX) $(CPPFLAGS) -o $@ $^

test: $(NAME)
	./$(NAME)

clean:
	@$(RM) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
