/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:30 by sji               #+#    #+#             */
/*   Updated: 2022/09/07 16:06:46 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		print_hex(unsigned int c, const char format);
int		print_nbr(int c);
int		print_unsigned(unsigned int c);
int		print_str(char *str);
int		print_char(char c);
int		print_ptr(unsigned long long ptr);

#endif