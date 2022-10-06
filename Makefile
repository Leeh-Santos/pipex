# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: learodri <learodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:55:22 by learodri          #+#    #+#              #
#    Updated: 2022/10/06 21:46:02 by learodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= clang
FLAGS	= -Wall -Wextra -Werror

### EXECUTABLE ###
NAME	= pipex
### INCLUDES ###
INCLUDE	= include
LIBFT_PATH	= Libft
SRC_PATH	= program
OBJ_PATH	= obj

### SOURCE FILES ###
SOURCES = pipex.c \
		errors.c \
		searchcmd.c

### OBJECTS ###
SRC     = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ     = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC             = \033[0m
RED             = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
WHITE   = \033[1;37m

### RULES ###

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(YELLOW)libft..$(NOC)"
		@make -sC $(LIBFT_PATH)
		@$(CC) $(FLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
		@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
		@mkdir -p obj
		@$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
		@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

clean:
		@echo "$(RED)clean$(NOC)"
		@make clean -sC $(LIBFT_PATH)
		@rm -rf $(OBJ_PATH)

fclean: clean
		@echo "$(RED)fclean$(NOC)"
		@make fclean -sC $(LIBFT_PATH)
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm push

