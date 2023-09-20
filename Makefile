NAME			= libftprintf.a

SRCS			=	\
					mandatory/ft_chars.c \
					mandatory/ft_nbrs.c \
					mandatory/ft_printf.c \
					mandatory/ft_strlen.c \
					mandatory/ft_putchar_fd.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I include
MAKEFLAGS 		+= --no-print-directory

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus