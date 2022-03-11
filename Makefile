NAME = so_long

HEADER = so_long.h
HEADER_BONUS = so_long_bonus.h

UTILS_BONUS_PATH = ./utils_bonus/
UTILS_BONUS = 	check_valid_map_bonus.c \
				ft_split_bonus.c \
				ft_strlcpy_bonus.c \
				ft_init_bonus.c \
				read_map_bonus.c \
				count_characters_bonus.c \
				start_game_bonus.c \
				end_prog_bonus.c \
				move_bonus.c \
				ft_putnbr_bonus.c \

UTILS_PATH = ./utils/
UTILS = check_valid_map.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_init.c \
		read_map.c \
		count_characters.c \
		start_game.c \
		end_prog.c \
		move.c \
		ft_putnbr.c \


GNL_PATH = ./get_next_line/
GNL =	get_next_line.c \
		get_next_line_utils.c

CC = gcc -g3 -fsanitize=address
RM = rm -rf

SRC = ./so_long.c $(addprefix $(UTILS_PATH), $(UTILS)) $(addprefix $(GNL_PATH), $(GNL))
SRC_BONUS = ./so_long_bonus.c $(addprefix $(UTILS_BONUS_PATH), $(UTILS_BONUS)) $(addprefix $(GNL_PATH), $(GNL))

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:
	@make UTILS_PATH="$(UTILS_BONUS_PATH)" \
	UTILS="$(UTILS_BONUS)" \
	HEADER="$(HEADER_BONUS)" \
	OBJ="$(OBJ_BONUS)"

%.o: %.c $(HEADER)
	$(CC) -o2 -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus