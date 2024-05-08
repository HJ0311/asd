CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = libft.h
NAME = libft.a
AR = ar rcs
RM = rm -f
SRCS_MANDATORY = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
ft_memchr.c ft_memcmp.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_MANDATORY = $(SRCS_MANDATORY:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)


all : LAST_ALL
bonus : LAST_BONUS

LAST_ALL : $(OBJS_MANDATORY)
	@$(AR) $(NAME) $^
	@touch $@
	@echo "libft ✅"

LAST_BONUS : $(OBJS_BONUS)
	@$(AR) $(NAME) $^
	@touch $@
	@echo "libft bonus ✅"

$(NAME) : $(OBJS) $(HEADER)
	@$(AR) $@ $^

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)

clean :
	@$(RM) $(OBJS_MANDATORY)
	@$(RM) $(OBJS_BONUS)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) LAST_ALL LAST_BONUS

re : fclean all

.PHONY : all clean fclean re bonus