/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:31:20 by zoesente          #+#    #+#             */
/*   Updated: 2023/03/25 16:10:04 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlength(unsigned long nb, unsigned long int length_base)
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

static void	ft_puthex_base(unsigned long int nb, unsigned int len_b, char *base)
{
	if (nb >= len_b)
	{
		ft_puthex_base(nb / len_b, len_b, base);
		ft_puthex_base(nb % len_b, len_b, base);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
	}
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
