/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:27:26 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/15 14:00:05 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		nl_l(char *str, int till_nl);
char	*ft_strcat(char *s1, const char *s2, int n);
char	*ft_strlcpy(char *dest, char *src, int n);
int		ft_is_new_line_in_buf(char *str);
char	*get_next_line(int fd);
char	*ft_srtdub(char *str);
void	ft_free(char **s);
char	*ft_get_line(char **buf);
char	*ft_return_last_line(char **buf);
int		ft_add_from_buf(int fd, char **buf);

#endif