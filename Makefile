# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: learodri <learodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:55:22 by learodri          #+#    #+#              #
#    Updated: 2022/10/05 20:31:29 by learodri         ###   ########.fr        #
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
SOURCES = program.c \
		errors.c \
		searchcmd.c