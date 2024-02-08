CC:=g++ -std=c++98
CFLAGS:= -Wall -Werror -Wextra -g3
RM:=rm -rf

NAME:=megaphone

SRC_PATH:=./

SRC_FILES:=megaphone.cpp

SRC_FILES:= $(addprefix $(SRC_PATH)/,$(SRC_FILES))
SRC_OBJECTS:= $(patsubst %.c,%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(SRC_OBJECTS)
	@$(CC) $^ $(CFLAGS) -o $@

clean:
	@$(RM) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re%