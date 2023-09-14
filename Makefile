NAME			= printf.a

SRCS			=	\
					mandatory/ft_chars.c \
					mandatory/ft_nbrs.c \
					mandatory/ft_printf.c \
					libft/libft.a


OBJS			= $(SRCS:.c=.o)

INCLUDE_PATH	= ./mandatory

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all: libft $(OBJS) $(NAME)

libft:
				make -C libft --no-print-directory

$(NAME):
				ar rcs $(NAME) $(OBJS)

clean: cleanlib
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

cleanlib:
				make clean -C libft

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus