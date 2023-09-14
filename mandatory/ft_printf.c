/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:40:30 by msarment          #+#    #+#             */
/*   Updated: 2023/09/14 15:06:06 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // cc -I ../includes  ft_printf.c  

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
			index += checkflags(args, str[cont]);
		}
		else
		{
			ft_putchar_fd(str[cont], 1);
			index++;
		}
		cont++;
	}
	return(index);
}

int	checkflags(va_list args, char flag)
{
	int	cont;

	cont = 0;
	if (flag == 'c')
		cont += ft_putchar(va_arg(args, int));
	if (flag == 's')
		cont += ft_putstr(va_arg(args, char *));
	if (flag == 'p')
		cont += ft_putptr(va_arg(args, unsigned long));
	if (flag == 'd' || flag == 'i')
		cont += ft_base_putnbr(va_arg(args, int), DECIMAL_BASE);
	if (flag == 'u')
		cont += ft_base_putnbr(va_arg(args, unsigned int), DECIMAL_BASE);
	if (flag == 'x')
		cont += ft_base_putnbr(va_arg(args, unsigned int), HEXADECIMAL_BASE_LOW);
	if (flag == 'X')
		cont += ft_base_putnbr(va_arg(args, unsigned int), HEXADECIMAL_BASE_UP);
	if (flag == '%')
		cont += ft_putchar('%');
	return (cont);
}

int main(void)
{
	
}