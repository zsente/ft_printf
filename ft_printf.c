/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:05:34 by zoesente          #+#    #+#             */
/*   Updated: 2023/03/03 18:18:04 by zsente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	return (i);
}

int	ft_numberlength(int nb)
{
	int	i;

	i = 1;
	if (nb == -2147483648)
	{
		return (11);
	}
	else if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_hexlength(unsigned long nb, unsigned long int length_base)
{
	unsigned int	i;

	i = 1;
	while (nb >= length_base)
	{
		nb = nb / length_base;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nb, int length_base, char *base)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
	}
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', 1);
		ft_putnbr_base(nb, length_base, base);
	}
	else if (nb >= length_base)
	{
		ft_putnbr_base(nb / length_base, length_base, base);
		ft_putnbr_base(nb % length_base, length_base, base);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
	}
}

void	ft_puthex_base(unsigned long int nb, unsigned int length_base, char *base)
{
	if (nb >= length_base)
	{
		ft_puthex_base(nb / length_base, length_base, base);
		ft_puthex_base(nb % length_base, length_base, base);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
	}
}

int	ft_printnbr(int nb)
{
	int	len;

	len = ft_numberlength(nb);
	ft_putnbr_base(nb, 10, "0123456789");
	return (len);
}

int	ft_printhex_unsigned(unsigned int nb, const char format)
{
	char	*base;
	int		len;
	int		length_base;

	if (format == 'u')
		base = "0123456789";
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	length_base = ft_strlen(base);
	len = ft_hexlength(nb, length_base);
	ft_puthex_base(nb, length_base, base);
	return (len);
}

int	ft_printptr(unsigned long int ptr)
{
	int	len;

	len = ft_hexlength(ptr, 16);
	ft_putstr_fd("0x", 1);
	ft_puthex_base(ptr, 16, "0123456789abcdef");
	return (len + 2);
}

int	ft_print_args(const char *format, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				len += ft_printchar(va_arg(args, int));
			if (format[i + 1] == 's')
				len += ft_printstr(va_arg(args, char *));
			if (format[i + 1] == 'p')
				len += ft_printptr(va_arg(args, unsigned long int));
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				len += ft_printnbr(va_arg(args, int));
			if (format[i + 1] == 'x' || format[i + 1] == 'X' || format[i + 1] == 'u')
				len += ft_printhex_unsigned(va_arg(args, int), format[i + 1]);
			if (format[i + 1] == '%')
				len += ft_printchar('%');
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_length;

	print_length = 0;
	va_start(args, str);
	print_length += ft_print_args(str, args);
	va_end(args);
	return (print_length);
}
