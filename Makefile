NAME			= libftprintf.a

SRCS			=	\
					mandatory/ft_chars.c \
					mandatory/ft_nbrs.c \
					mandatory/ft_printf.c \
					mandatory/ft_strlen.c \
					mandatory/ft_putchar_fd.c

SRCS_BONUS		=	\
					bonus/ft_chars_bonus.c \
					bonus/ft_nbrs_bonus.c \
					bonus/ft_printf_bonus.c \
					bonus/ft_strlen_bonus.c \
					bonus/ft_putchar_fd_bonus.c \
					bonus/ft_flag_bonus.c

OBJS			= $(SRCS:.c=.o)

OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

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

bonus:			$(OBJS_BONUS)
				@printf "Copilando arquivos... \n"
				@sleep 0.5
				@printf "Transformando em biblioteca... \n"
				@sleep 0.5
				@ar rcs $(NAME) $(OBJS_BONUS)
				@printf "Done!\n"

clean:
				@printf "Limpando os arquivos...\n"
				@$(RM) $(OBJS) $(OBJS_BONUS)
				@sleep 0.5
				@printf "Done!\n"

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus