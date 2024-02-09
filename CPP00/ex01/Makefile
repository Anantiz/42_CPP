CXX:=g++ -std=c++98
CPPFLAGS:= -Wall -Werror -Wextra -g3
RM:=rm -rf

NAME:=phonebook

SRC_PATH:=./

SRC_FILES:= main.cpp phonebook.cpp contact.cpp

SRC_FILES:= $(addprefix $(SRC_PATH)/,$(SRC_FILES))
SRC_OBJECTS:= $(patsubst %.cpp,%.o,$(SRC_FILES))

all: $(NAME)

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) -o $@

$(NAME): $(SRC_OBJECTS)
	$(CXX) $^ $(CPPFLAGS) -o $@

clean:
	@$(RM) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re