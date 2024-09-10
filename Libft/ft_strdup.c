/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:49:31 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/05 15:13:39 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t		l;
	size_t		i;

	l = ft_strlen(s);
	i = 0;
	new = (char *)malloc((l + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < l)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

#include <string.h>

int	main(void)
{
	char	source[] = "Hello";
	char	*target;
	char	*target2;

	target = strdup(source);
	printf("%s\n", target);
	free(target);
	target2 = strdup(source);
	printf("%s\n", target2);
	free(target2);
}
