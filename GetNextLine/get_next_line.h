#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_strcat(char *s1, char *s2, int n);
void	ft_strcpy(char *dest, char *src);
void	ft_strlcpy(char *dest, char *src, int n);
int	ft_len_till_new_line(char *str);
int	ft_is_new_line_in_buf(char *str);


char	*get_next_line(int fd);

#endif