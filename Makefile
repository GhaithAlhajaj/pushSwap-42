NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
SRC_FILES = push_swap.c push.c reverse_rotate.c rotate.c swap.c a_to_b.c b_to_a.c sort_small_a.c sort_small_b.c utility.c push_argv.c valid.c utils_argv.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INC_DIR = push_swap.h/inc
LIBFT_DIR = libft
LIBFT = libft.a
LIB = -L$(LIBFT_DIR) -lft

all: $(OBJ_DIR) $(LIBFT_DIR)/$(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

