/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:28:57 by zoesente          #+#    #+#             */
/*   Updated: 2023/03/25 13:39:41 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(int nb, int length_base, char *base)
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

static int	ft_numberlength(int nb)
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

int	ft_printnbr(int nb)
{
	int	len;

	len = ft_numberlength(nb);
	ft_putnbr_base(nb, 10, "0123456789");
	return (len);
}
