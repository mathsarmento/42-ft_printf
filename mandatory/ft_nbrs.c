/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:28:37 by msarment          #+#    #+#             */
/*   Updated: 2023/09/14 14:16:22 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_putnbr(long int nbr, char *base)
{
	int	cont;
	int	lenbase;

	cont = 0;
	lenbase = ft_strlen(base);
	if (nbr == INT_MIN)
	{
		cont += ft_putchar('-');
		cont += ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		cont += ft_putchar('-');
	}
	if (nbr >= lenbase)
		cont += ft_base_putnbr(nbr / lenbase, base);
	cont += ft_putchar(base[nbr % lenbase]);
	return (cont);
}

int	ft_putptr(unsigned long ptr)
{
	int cont;

	cont = 0;
	if (!ptr)
		return(ft_putstr("(nil)"));
	if (ptr >= 16)
		cont += ft_putptr(ptr / 16);
	else
		cont += ft_putstr("0x");
	cont += ft_putchar(HEXADECIMAL_BASE_LOW[ptr % 16]);
	return (cont);
}
