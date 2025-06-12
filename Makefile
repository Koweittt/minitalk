# ---- Configurations ---- #
CLIENT_EXEC     = client
SERVER_EXEC     = server
CC              = cc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -f

# ---- Sources ---- #
SRCS_CLI        = src/client.c
SRCS_SER        = src/server.c Printf/ft_printf.c Printf/ft_printf_utils.c \
		  Printf/ft_printf_utils2.c \

OBJS_CLI        = $(SRCS_CLI:.c=.o)
OBJS_SER        = $(SRCS_SER:.c=.o)

# ---- Colors ---- #
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
RED             = \033[0;31m
RESET           = \033[0m

# ---- Rules ---- #
all: $(CLIENT_EXEC) $(SERVER_EXEC)

$(CLIENT_EXEC): $(OBJS_CLI)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)✓ $(CLIENT_EXEC) compiled successfully!$(RESET)"

$(SERVER_EXEC): $(OBJS_SER)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)✓ $(SERVER_EXEC) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)• Compiling: $(notdir $<)$(RESET)"

clean:
	@$(RM) $(OBJS_CLI) $(OBJS_SER)
	@echo "$(RED)• Object files removed$(RESET)"

fclean: clean
	@$(RM) $(CLIENT_EXEC) $(SERVER_EXEC)
	@echo "$(RED)• Executables removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
