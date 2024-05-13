CC = gcc
RM = rm -rf
#FLAGS = -Wall -Wextra -Werror
NAME = stoner

SRCS := $(wildcard src/*.c)
OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

build: all clean

.PHONY: all clean fclean re build