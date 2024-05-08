CC = cc
CFLAGS = -g -fsanitize=undefined -Wall -Wextra -Werror 
LDFALGS = -lreadline
RM = rm -rf
AR = ar rcs

NAME = minishell
LIBFT = ./ft_printf/libftprintf.a
INC_DIR = ./includes

MAIN_SRCS = $(addprefix sources/, main.c display.c pipe_run.c free.c here_doc.c init_info.c\
cd.c echo.c env.c exit.c export.c process.c pwd.c unset.c builtin_check.c get_cmd.c)

SRC_MANDATORY = $(MAIN_SRCS)
OBJS_MANDATORY = $(SRC_MANDATORY:%.c=%.o)

GREEN = \033[1;32m
RED = \033[1;31m

all : LAST_ALL

LAST_ALL : $(OBJS_MANDATORY) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFALGS) -o $(NAME) $(LIBFT) $^
	@touch $@
	@echo "$(GREEN)minishell ✅"

%.o : %.c $(INC_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT) :
	@make all -C ft_printf

clean :
	@$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@make clean -C ft_printf
	@echo "$(RED)minishell : clean ✅"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) LAST_ALL
	@make fclean -C ft_printf
	@echo "$(RED)minishell : fclean ✅"

re : fclean all

.PHONY : all clean fclean re