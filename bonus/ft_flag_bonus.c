/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:26:31 by msarment          #+#    #+#             */
/*   Updated: 2023/09/26 20:10:45 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hashflag(long int nbr, char next)
{
	int	cont;

	cont = 0;
	if (nbr == 0)
	{
		cont += ft_putchar('0');
		return (cont);
	}
	if (next == 'x')
	{
		cont += ft_putstr("0x");
		cont += ft_base_putnbr(nbr, HEXA_BASE_LOW);
	}
	else if (next == 'X')
	{
		cont += ft_putstr("0X");
		cont += ft_base_putnbr(nbr, HEXADECIMAL_BASE_UP);
	}
	return (cont);
}

int	ft_moreflag(int number)
{
	int	cont;

	cont = 0;
	if (number >= 0)
	{
		cont += ft_putchar('+');
		cont += ft_base_putnbr(number, DECIMAL_BASE);
	}
	else
		cont += ft_base_putnbr(number, DECIMAL_BASE);
	return (cont);
}

int	ft_spaceflag(va_list args, char next)
{
	int	cont;
	int	num;

	cont = 0;
	if (next == 'd' || next == 'i')
	{
		num = va_arg(args, int);
		if (num >= 0)
		{
			cont += ft_putchar(' ');
			cont += ft_base_putnbr(num, DECIMAL_BASE);
		}
		else
			cont += ft_base_putnbr(num, DECIMAL_BASE);
	}
	if (next == 's')
	{
		cont += ft_putstr(va_arg(args, char *));
	}
	return (cont);
}
