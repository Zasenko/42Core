/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_folders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:05:13 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/26 17:06:03 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_folders(t_prog *prog, char **env)
{
	char	**folders;
	int		i;

	if (!prog || !env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			folders = ft_split(env[i] + 5, ':');
			if (!folders)
				return (NULL);
			return (folders);
		}
		i++;
	}
	return (NULL);
}
