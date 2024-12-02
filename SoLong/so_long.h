/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:02:50 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/27 14:59:39 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
# include <unistd.h>
//#include "libft/libft.h"
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_textures
{
	void *p;
	void *e_c;
	void *e_o;
	void *w;
	void *c;
	void *g;
}	t_textures;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_point	size;
	t_point	start;
	int		coins_count;
	int		exit_count;
	t_textures	textures;
}				t_game;


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

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_str_arr(char **arr);
int		str_arr_count(char **arr);

int		check_path(t_game *game, char **map);

char	*make_map_str(char *str_map, char *line);
int		check_str_map(char *map, t_game *game);
int		check_map(char *str_map, t_game *game);
char	**make_map(char *str_map);

int	ft_read_file(char *file_name, t_game *game);

#endif
