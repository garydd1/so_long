NAME := so_long
SRC = $(wildcard *.c)
LIBMLX := ./lib/MLX42
LIBFT = ./libft/libft.a
HEADERS := "-I./inc -I$(LIBMLX)/include"
HEADER = ./inc/so_long.h
OBJS = $(SRC:.c=.o)
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
  
LIBS	:= -ldl -lglfw -L "/Users/dgarizad/.brew/opt/glfw/lib/" -lm $(LIBMLX)/libmlx42.a
	
all: libmlx $(NAME)

libmlx:
	@echo "Compiling MLX42..."
	@$(MAKE) -C $(LIBMLX)
%.o: %.c $(HEADER)
	@echo "Creating objects..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS) $(LIBFT)
	@echo "Creating executable..."
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)
	@echo "Done."

$(LIBFT): 
	@echo "Your beloved libft..."
	@make -C ./libft
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	make fclean -C ./libft

re: clean all

.PHONY: all, clean, fclean, re, libmlx
