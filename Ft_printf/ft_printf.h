/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:54:39 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:52 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd, int *len);
void	ft_putnbr_fd(int n, int fd, int *len);
void	ft_putstr_fd(char *s, int fd, int *len);
int		ft_printf(const char *str, ...);

#endif