# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 09:05:04 by ajehle            #+#    #+#              #
#    Updated: 2024/07/31 09:45:41 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc -g
REMOVE		= rm -rf
OBJ_DIR		= ./obj
SRC_DIR		= src
INC_DIR		= include
CFLAGS		= -Wall -Werror -Wextra -I $(INC_DIR)
#THREADFLAG  = -fsanitize=thread
#FAST		= -Ofast

# looking for files in subdirectories
vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parsing_input.c \
				$(SRC_DIR)/libft.c \
				$(SRC_DIR)/handler.c \
				$(SRC_DIR)/preping.c \
				$(SRC_DIR)/memory_management.c \
				$(SRC_DIR)/the_dinner.c \
				$(SRC_DIR)/dinner_actions.c \
				$(SRC_DIR)/set_and_get.c \
				$(SRC_DIR)/time.c \
				$(SRC_DIR)/status.c \
				$(SRC_DIR)/routines.c \
				$(SRC_DIR)/routine_utils.c \

# INTERNAL OBJECT
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

all : $(NAME)

# INTERNAL RULE
$(NAME) : $(OBJECTS)
	$(CC) $(FAST) $(CFLAGS) $(OBJECTS) $(THREADFLAG) -o $(NAME)

# DIRECTORY
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(THREADFLAG) -c $< -o $@

clean :
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJ_DIR)

fclean : clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(OBJ_DIR)

re : fclean all

.PHONY : all, clean, fclean, re
