/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:40:38 by msarment          #+#    #+#             */
/*   Updated: 2023/09/14 14:20:54 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_BASE_LOW "0123456789abcdef"
# define HEXADECIMAL_BASE_UP "0123456789ABCDEF"
# define INT_MIN -2147483648

int	ft_printf(const char *str, ...);
int	checkflags(va_list args, char flag);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_base_putnbr(long int nbr, char *base);
int	ft_putptr(unsigned long ptr);


#endif