# Makefile for minitalk project
NAME = minitalk

# Executables
SERVER = server
CLIENT = client
B_SERVER = server_bonus
B_CLIENT = client_bonus

FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -l ftprintf -I $(FT_PRINTF_PATH)

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(CLIENT) $(SERVER)
# Default target
all: $(NAME)

# Rule to build the server executable
$(SERVER): $(FT_PRINTF) $(SERVER).c
	$(CC) $(CFLAGS) $(SERVER).c -o $(SERVER) $(FT_PRINTF_LIB_FLAGS)

# Rule to build the client executable
$(CLIENT): $(FT_PRINTF) $(CLIENT).c
	$(CC) $(CFLAGS) $(CLIENT).c -o $(CLIENT) $(FT_PRINTF_LIB_FLAGS)

$(FT_PRINTF):
	make -s -C $(FT_PRINTF_PATH)

bonus: $(B_SERVER) $(B_CLIENT)

# Rule to build the server executable
$(B_SERVER): $(FT_PRINTF) $(B_SERVER).c
	$(CC) $(CFLAGS) $(B_SERVER).c -o $(B_SERVER) $(FT_PRINTF_LIB_FLAGS)

# Rule to build the client executable
$(B_CLIENT): $(FT_PRINTF) $(B_CLIENT).c
	$(CC) $(CFLAGS) $(B_CLIENT).c -o $(B_CLIENT) $(FT_PRINTF_LIB_FLAGS)

# Clean up build files
clean:
	rm -f $(FT_PRINTF)

# Clean up everything
fclean: clean
	rm -f $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT) $(FT_PRINTF)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus