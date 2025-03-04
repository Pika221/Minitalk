NAME = minitalk
SERVER = server
CLIENT = client
B_SERVER = server_bonus
B_CLIENT = client_bonus
FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -l ftprintf -I $(FT_PRINTF_PATH)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(CLIENT) $(SERVER)

$(SERVER): $(FT_PRINTF) $(SERVER).c
	@$(CC) $(CFLAGS) $(SERVER).c -o $(SERVER) $(FT_PRINTF_LIB_FLAGS)

$(CLIENT): $(FT_PRINTF) $(CLIENT).c
	@$(CC) $(CFLAGS) $(CLIENT).c -o $(CLIENT) $(FT_PRINTF_LIB_FLAGS)

$(B_SERVER): $(FT_PRINTF) $(B_SERVER).c
	@$(CC) $(CFLAGS) $(B_SERVER).c -o $(B_SERVER) $(FT_PRINTF_LIB_FLAGS)

$(B_CLIENT): $(FT_PRINTF) $(B_CLIENT).c
	@$(CC) $(CFLAGS) $(B_CLIENT).c -o $(B_CLIENT) $(FT_PRINTF_LIB_FLAGS)

$(FT_PRINTF):
	@make -s -C $(FT_PRINTF_PATH)

all: $(NAME)

bonus: $(B_SERVER) $(B_CLIENT)

clean:
	@make -s -C $(FT_PRINTF_PATH) fclean

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re bonus