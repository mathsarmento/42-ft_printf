/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:40:30 by msarment          #+#    #+#             */
/*   Updated: 2023/09/26 19:54:59 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		cont;

	cont = 0;
	index = 0;
	va_start(args, str);
	while (str[cont])
	{
		if (str[cont] == '%')
		{
			cont++;
			index += checkflags(args, str[cont], str[cont + 1]);
			if (str[cont] == ' ' || str[cont] == '+' || str[cont] == '#')
				cont++;
		}
		else
		{
			ft_putchar_fd(str[cont], 1);
			index++;
		}
		cont++;
	}
	return (index);
}

int	checkflags(va_list args, char flag, char next)
{
	int	cont;

	if (flag == 'c')
		cont = ft_putchar(va_arg(args, int));
	if (flag == 's')
		cont = ft_putstr(va_arg(args, char *));
	if (flag == 'p')
		cont = ft_putptr(va_arg(args, unsigned long));
	if (flag == 'd' || flag == 'i')
		cont = ft_base_putnbr(va_arg(args, int), DECIMAL_BASE);
	if (flag == 'u')
		cont = ft_base_putnbr(va_arg(args, unsigned int), DECIMAL_BASE);
	if (flag == 'x')
		cont = ft_base_putnbr(va_arg(args, unsigned int), HEXA_BASE_LOW);
	if (flag == 'X')
		cont = ft_base_putnbr(va_arg(args, unsigned int), HEXADECIMAL_BASE_UP);
	if (flag == '%')
		cont = ft_putchar('%');
	if (flag == '#')
		cont = ft_hashflag(va_arg(args, unsigned int), next);
	if (flag == ' ')
		cont = ft_spaceflag(args, next);
	if (flag == '+')
		cont = ft_moreflag(va_arg(args, int));
	return (cont);
}
