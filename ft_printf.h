/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:03:24 by zoesente          #+#    #+#             */
/*   Updated: 2023/03/25 16:02:21 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printstr(char *str);
int	ft_printnbr(int nb);
int	ft_printhex_unsigned(unsigned int nb, const char format);
int	ft_printptr(unsigned long int ptr);
int	ft_printf(const char *str, ...);
#endif
