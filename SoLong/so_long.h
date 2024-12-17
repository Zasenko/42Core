/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:02:50 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 14:33:08 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_textures
{
	void	*p;
	void	*e_c;
	void	*e_o;
	void	*w;
	void	*c;
	void	*g;
}	t_textures;

typedef struct s_map_check
{
	int	coins_count;
	int	exit_count;
}				t_map_check;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_check	map_check;
	t_point		size;
	t_point		start;
	int			coins_count;
	int			moves;
	int			is_finish;
	t_textures	t;
	int			img_size;
	int			is_p_on_e;
}				t_game;

size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	put_char(char c);
void	put_str(char *s);
void	print_error(char *text);
void	print_moves(int num);
int		set_new_game(t_game *game);
int		make_map(char *file_name, t_game *game);
int		make_textures(t_game *game);
int		move(t_game *game, int move);
int		on_keypress(int key, t_game *game);
int		set_window(t_game *game);
int		make_img(t_game *game);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		check_str_map(char *map, t_game *game);
int		check_map(char *str_map, t_game *game);
int		check_move(t_game *game, int x, int y);
int		check_path(t_game *game, char **map);
void	free_str(char **s);
void	free_str_arr(char **arr);
void	free_game(t_game *game);
void	finish_game(t_game *game);
int		close_window(t_game *game);

#endif
