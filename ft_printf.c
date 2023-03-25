/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:05:34 by zoesente          #+#    #+#             */
/*   Updated: 2023/03/25 16:57:16 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_process_format(char fmt, va_list args)
{
	if (fmt == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (fmt == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (fmt == 'p')
		return (ft_printptr(va_arg(args, unsigned long int)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (fmt == 'x' || fmt == 'X' || fmt == 'u')
		return (ft_printhex_unsigned(va_arg(args, int), fmt));
	else if (fmt == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_length;

	print_length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_length += ft_process_format(*str, args);
		}
		else
		{
			print_length += ft_printchar(*str);
		}
		str++;
	}
	va_end(args);
	return (print_length);
}
