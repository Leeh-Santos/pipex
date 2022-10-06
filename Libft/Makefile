# Name
NAME = libft.a

# Path
OBJ_PATH = ./obj/

# Binary
SRC_NAME=	ft_split.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnstr.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
CC = clang
CFLAGS = -Wall -Wextra -Werror

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	-@norminette *.c
	-@norminette *.h

.PHONY: all clean fclean re norm