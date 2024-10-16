#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *s1, const char *s2, int n);
char	*ft_strlcpy(char *dest, char *src, int n);
int		ft_len_till_new_line(char *str);
int		ft_is_new_line_in_buf(char *str);
char	*get_next_line(int fd);

#endif