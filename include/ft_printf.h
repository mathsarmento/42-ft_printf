/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:40:38 by msarment          #+#    #+#             */
/*   Updated: 2023/09/20 18:24:44 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DECIMAL_BASE "0123456789"
# define HEXA_BASE_LOW "0123456789abcdef"
# define HEXADECIMAL_BASE_UP "0123456789ABCDEF"
# define INT_MIN -2147483648

int	ft_printf(const char *str, ...);
int	checkflags(va_list args, char flag);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_base_putnbr(long int nbr, char *base);
int	ft_putptr(unsigned long ptr);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);



#endif