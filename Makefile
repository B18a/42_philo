# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:31:09 by ajehle            #+#    #+#              #
#    Updated: 2024/03/27 10:14:33 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= gcc -g
REMOVE		= rm -rf
SRC_DIR		= src
OBJ_DIR		= ./obj
INC_DIR		= include
#CFLAGS		= -Wall -Werror -Wextra
THREADFLAG  = -pthread 

# looking for files in subdirectories
vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/philo.c \
				$(SRC_DIR)/libft.c \
				$(SRC_DIR)/handle_input.c \
				$(SRC_DIR)/ft_free.c \
				$(SRC_DIR)/handler.c \
				$(SRC_DIR)/dinner.c \
				$(SRC_DIR)/set_and_get.c \
				$(SRC_DIR)/time.c \
				$(SRC_DIR)/dinner_actions.c \
				$(SRC_DIR)/ft_print_status.c \
				$(SRC_DIR)/butler.c \


# INTERNAL OBJECT
OBJECTS				= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

all : $(NAME)

# INTERNAL RULE
$(NAME) : $(LIBS_NAME) $(OBJECTS) $(B_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

# DIRECTORY
$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(THREADFLAG) -c $< -o $@

clean :
	$(REMOVE) $(OBJECTS)

fclean : clean
	$(REMOVE) $(NAME)

re : clean all

.PHONY : all clean fclean re
