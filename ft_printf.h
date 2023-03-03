/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:03:24 by zoesente          #+#    #+#             */
/*   Updated: 2023/01/31 23:21:34 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printchar(char c); 
int ft_numberlength(int nb);
int ft_printnbr(int nb); 
int	ft_printstr(char *str);
int ft_printformat( const char format, va_list args); 
int ft_printf(const char *str, ...); 
void ft_putnbr_base(int nb, int length_base, char* base); 

#endif

