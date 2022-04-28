# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 14:22:01 by junykim           #+#    #+#              #
#    Updated: 2022/04/28 20:59:49 by junykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME		= fdf
CC 			= gcc
CFLAG		= -Werror -Wextra -Wall
INC			= ./include
SRC_DIR		= src/
OBJ_DIR		= obj/
SRC_FILES	= draw how_to_draw \
			  make_looks_like_3d \
			  read_file \
			  utility \
			  main \
			  get_next_line_bonus \
			  get_next_line_utils_bonus
SRCS		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEL 		= rm -f
LIBFT 		= libft
MLX			= mlx_mms
MAKE_OBJ_DIR= create_dir 

#Rules

#https://stackoverflow.com/questions/1950926/create-directories-using-make-file
	
all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(MAKE_OBJ_DIR)
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INC)
	@echo "*.c =====>>>>>>>> *.o \t $<"

$(MAKE_OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@make -C $(MLX)
	@cp $(MLX)/libmlx.dylib .
	$(CC) $(CFLAG) $(OBJS) libft.a -Lmlx_mms -lmlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore -o $@
	@echo "================fdf compile finished=================="

clean :
	$(DEL) -r $(OBJ_DIR)
	$(DEL) libft.a libmlx.dylib
	@make clean -C $(LIBFT)
	@echo "====================fdf obj files has been deleted===================="

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	$(DEL) $(MLX)/libmlx.dylib
	@echo "==============fdf link files has been deleted================"

re : fclean all

.PHONY : all clean fclean re
