NAME = so_long

UTILS_PATH = ./utils/
UTILS = check_valid_map.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_init.c \

GNL_PATH = ./get_next_line/
GNL =	get_next_line.c \
		get_next_line_utils.c

CC = gcc -g3 #-fsanitize=address 
RM = rm -rf

SRC = so_long.c $(addprefix $(UTILS_PATH), $(UTILS)) $(addprefix $(GNL_PATH), $(GNL))

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c so_long.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re