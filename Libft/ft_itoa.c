/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:58:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/09 15:50:31 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void put_i_to_s(char *s, int n, int *i)
{
    if (n >= 10)
    {
        put_i_to_s(s, n / 10, i);
        s[*i] = (n % 10) + '0'; 
        *i += 1;
    }
    else
    {
        s[*i] = n + '0'; 
        *i += 1;
    }
}

char *ft_itoa(int n)
{
    char s[12];
    int i;
    char *str;
    
    i = 0;
    if (n < 0)
    {
        s[i] = '-';   
        i++;     
        if (n == -2147483648)
        {
            s[i] = '2';   
            i++; 
            n += 2000000000;
        }
        n *= -1;
    }
    put_i_to_s(s, n, &i);
    str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (s[i])
    {
            str[i] = s[i];
            i++;
    }
    str[i] = '\0';
    return (str);
}

int main()
{
    char *s;
    s = ft_itoa(-2147483648);
    if (s)
    {
        printf("%s\n", s);
        free(s);
    }
}