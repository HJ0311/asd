CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ./libft/libft.a
AR = ar rcs
RM = rm -rf
HEADER = ft_printf.h
SRCS = ft_printf_bonus.c ft_parse_options_bonus.c ft_extra_bonus.c ft_print_letter_bonus.c\
ft_setting_num_bonus.c ft_print_num_bonus.c ft_itoa_base_bonus.c
OBJS = $(SRCS:%.c=%.o)

all : bonus

bonus : LAST_BONUS

LAST_BONUS : $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@touch $@
	@echo "printf ✅"

$(LIBFT) : 
	@make all -C libft
	@make bonus -C libft

$(NAME) : $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(AR) $@ $(OBJS)
	@make fclean -C libft

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)

clean :
	@$(RM) $(OBJS)
	@make -C libft clean

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@$(RM) LAST_BONUS

re : clean all

.PHONY : all clean fclean re