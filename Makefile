#Exit
NAME		= 	so_long

#Sources
SRCS		= 	so_long.c \
				sl_functions.c \
				sl_map_checks.c \
				sl_aux.c \
				sl_moves.c \
				sl_draw.c

OBJS		= 	$(SRCS:.c=.o)

#Compilation
# Linking: option -r to ensure that if the library (.a) file already exists, 
# it will be replaced. The command option -c should be used so that if the 
# file doesn’t exist, it will be created.
AR			=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LIBFLAGS	=	-Imlx -lmlx -framework OpenGL -framework AppKit

#Erase
RM			= 	rm -rf

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

#Default target
all:		$(LIBFT) $(NAME)
bonus: 		$(LIBFT) $(NAME_BONUS)

$(LIBFT):
			@make -C libft

$(NAME):	$(OBJS) $(LIBFT_SRC)$(LIBFT)
			$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME) 

clean:
			$(RM) $(NAME) $(OBJS) 

#Cleaning objects and executable 
fclean:		clean
			@make -C libft fclean

#Cleaning all and then compilation
re:			fclean all

#Exectute no matter name is
.PHONY: all clean fclean re