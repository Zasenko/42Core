/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:15:18 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:51:46 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*s_new;
	size_t	i;
	size_t	f;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s_new = (char *)malloc((l + 1) * sizeof(char));
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_new[i] = s1[i];
		i++;
	}
	f = 0;
	while (s2[f])
	{
		s_new[i++] = s2[f++];
	}
	s_new[i] = '\0';
	return (s_new);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_strjoin.c ft_strlen.c
int	main(void)
{
	char s1[] = "Hello,";
	char s2[] = " Dimitry!";
	char *new;
	new = ft_strjoin(s1, s2);
	if (new)
	{
		printf("%s\n", new);
		free(new);
	} else {
		printf("ERROR\n");
	}

	char s3[] = "Hello,";
	char s4[10];
	new = ft_strjoin(s3, s4);
	if (new)
	{
		printf("%s\n", new);
		free(new);
	} else {
		printf("ERROR\n");
	}

	new = ft_strjoin("HEY", NULL);
	if (new)
	{
		printf("%s\n", new);
		free(new);
	} else {
		printf("ERROR\n");
	}
}*/