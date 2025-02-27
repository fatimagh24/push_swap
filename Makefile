CC = cc
NAME = push_swap
CFLAGS		= -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = check_stack.c\
		intiate_stack.c\
		free_stack.c\
		push_stack.c\
		sort_stack.c\
		rotate_stack.c\
		reverse_r.c\
		swap_stack.c\
		sort_algo.c\


SRC_MAIN = main.c

OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ_MAIN) $(OBJ) | libft
	@$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBFT)

clean:
	rm -f $(OBJ_MAIN) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, re, clean, fclean, libft