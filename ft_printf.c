/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:17 by zoesente          #+#    #+#             */
/*   Updated: 2023/01/17 19:04:18 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		ft_putchar_fd(c, fd);
	}
}

int ft_printchar(int c)
{
	write(1, &c, 1);
	return(1); 
}

int ft_printformat(va_list params, const char format)
{
	int print_length; 

	print_length = 0; 
	if (format == 'c')
	{
		print_length += ft_printchar(va_arg(params, int)); 
	}
	else if (format == 's')
	{
		print_length += ft_printstr(va_arg(params, char *));
	}
	else if (format == 'p')
	{
		print_length += ft_printnbr(va_arg(q,))
	}
	

	return(print_length); 
}

int ft_printf(const char *, ...)
{
	va_list params; 
	int i; 
	int print_length; 

	i = 0; 
	print_length = 0; 
	va_start(params, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			print_length += ft_printformat(params, str[i + 1]); 
		}
		else 
		{
			print_length += ft_printchar(str[i]); 
		}
		i++; 
	}
	va_end(params); 

}