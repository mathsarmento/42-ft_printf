/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:42:36 by msarment          #+#    #+#             */
/*   Updated: 2023/08/10 17:52:18 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(int nbr);
static void		fillchar(char *pointer, int nbr, size_t len);

char	*ft_itoa(int n)
{
	char	*intc;

	intc = ft_calloc(nbrlen(n) + 1, sizeof(char));
	if (!intc)
		return (NULL);
	fillchar(intc, n, nbrlen(n));
	return (intc);
}

static size_t	nbrlen(int nbr)
{
	size_t	cont;

	cont = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		cont++;
		nbr = nbr * -1;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		cont++;
		nbr = nbr / 10;
	}
	return (cont);
}

static void	fillchar(char *pointer, int nbr, size_t len)
{
	len--;
	if (nbr == -2147483648)
	{
		pointer[len] = '8';
		len--;
		nbr = -214748364;
	}
	if (nbr == 0)
		pointer[len] = '0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
		pointer[0] = '-';
	}
	while (nbr > 0)
	{
		pointer[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
}
