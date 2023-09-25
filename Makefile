NAME			= libftprintf.a

SRCS			=	\
					mandatory/ft_chars.c \
					mandatory/ft_nbrs.c \
					mandatory/ft_printf.c \
					mandatory/ft_strlen.c \
					mandatory/ft_putchar_fd.c

OBJS			= $(SRCS:.c=.o)

CC				= @ gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I include
MAKEFLAGS 		+= --no-print-directory

all:			$(NAME)

$(NAME):		$(OBJS)
				@printf "Copilando arquivos... \n"
				@sleep 0.5
				@printf "Transformando em biblioteca... \n"
				@sleep 0.5
				@ar rcs $(NAME) $(OBJS)
				@printf "Done!\n"

clean:
				@printf "Limpando os arquivos...\n"
				@$(RM) $(OBJS) $(BONUS_OBJS)
				@sleep 0.5
				@printf "Done!\n"

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus