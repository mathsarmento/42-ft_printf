NAME			= printf.a

SRCS			=	\
					./mandatory/src/ft_chars.c \
					./mandatory/src/ft_nbrs.c \
					./mandatory/src/printf.c \
					


OBJS			= $(SRCS:%.c=%.o)

INCLUDE_PATH	= ./mandatory/includes

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I ./mandatory/includes

all: libft $(NAME)

libft:
ifeq ($(wildcard $(LIB_NAME)),)
	@make -C ./libft --no-print-directory
	@cp $(LIB_NAME) $(NAME)
endif

all:			$(NAME)

$(NAME):
				$(CC) $(CFLAGS) $(SRCS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus