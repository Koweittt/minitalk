# ===== Configurations ===== #
NAME_CLIENT     = client
NAME_SERVER     = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
CC              = cc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -f

# ---- Sources (Mandatory) ---- #
SRCS_CLIENT     = src/client.c
SRCS_SERVER     = src/server.c
SRCS_PRINTF     = Printf/ft_printf.c Printf/ft_printf_utils.c Printf/ft_printf_utils2.c

# ---- Sources (Bonus) ---- #
SRCS_CLIENT_BONUS = src/client_bonus.c 
SRCS_SERVER_BONUS = src/server_bonus.c

# ---- Objects ---- #
OBJS_CLIENT     = $(SRCS_CLIENT:.c=.o) $(SRCS_PRINTF:.c=.o)
OBJS_SERVER     = $(SRCS_SERVER:.c=.o) $(SRCS_PRINTF:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o) $(SRCS_PRINTF:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o) $(SRCS_PRINTF:.c=.o)

# ---- Colors ---- #
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
RED             = \033[0;31m
RESET           = \033[0m

# ===== Rules ===== #
all: $(NAME_CLIENT) $(NAME_SERVER)

# ---- Mandatory Build ---- #
$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)[✓] $(NAME_CLIENT) compiled!$(RESET)"

$(NAME_SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)[✓] $(NAME_SERVER) compiled!$(RESET)"

# ---- Bonus Build ---- #
bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)[✓] $(NAME_CLIENT_BONUS) compiled!$(RESET)"

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)[✓] $(NAME_SERVER_BONUS) compiled!$(RESET)"

# ---- Compilation Rule for Objects ---- #
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)[•] Compiling: $(notdir $<)$(RESET)"

# ---- Clean Rules ---- #
clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@echo "$(RED)[×] Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@echo "$(RED)[×] Executables removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
