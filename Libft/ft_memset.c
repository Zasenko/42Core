/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:54:34 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/04 15:16:14 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *buff;

    buff = (unsigned char *) s;
    while (n > 0)
    {
        *(buff++) = (unsigned char) c;
        n--;
    }
    return (s);
}

#include <string.h>
int main()
{
    char c[] = "Hello!";
    char c2[] = "Hello!";
    
    ft_memset((void *)c, '5', 4);
    memset((void *)c2, '5', 4);

    printf("%s\n", c);
    printf("%s\n", c2);
}