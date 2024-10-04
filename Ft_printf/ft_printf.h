/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:54:39 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/02 13:30:56 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_put_base_num(size_t num, char *base, size_t base_len, int *len);
void	ft_print_num_flag(const char *str, va_list factor, int *len);
void	ft_print_poiner(va_list factor, int *len);
void	ft_print_text_flag(const char *str, va_list factor, int *len);
void	ft_print_flag(const char *s, va_list factor, int *len);
int		ft_chech_flag(char c);
int		ft_print_variadic(const char *str, va_list factor);
int		ft_printf(const char *str, ...);

#endif