/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:49:19 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/06 13:42:45 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*sub_s;
    unsigned int s_len;
    unsigned int new_len;
    
    if (!s)
        return (NULL);
    s_len = (unsigned int)ft_strlen(s);
    if (start > s_len - 1)
        return (NULL);
    if (s_len - start > (unsigned int)len)
        new_len = (unsigned int)len;
    else
        new_len = s_len - start;
    sub_s = (char *)malloc((new_len + 1) * sizeof(char));
    if (sub_s == NULL)
        return (NULL);
    ft_strlcpy(sub_s, &s[start], new_len + 1);
    return (sub_s);
}
/*
int main()
{
    char s[] = "Hello, Dimitry!";
    char	*sub;
    sub = ft_substr(s, 0, 4);
    if (sub)
    {
        printf("%s\n", sub);
        free(sub);
    }
    sub = ft_substr(s, 7, 4);
    if (sub)
    {
        printf("%s\n", sub);
        free(sub);
    }
    sub = ft_substr(s, 13, 4);
    if (sub)
    {
        printf("%s\n", sub);
        free(sub);
    }
    sub = ft_substr(s, 17, 4);
    if (sub)
    {
        printf("%s\n", sub);
        free(sub);
    }
}*/