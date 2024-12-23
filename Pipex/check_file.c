/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:33:50 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/19 15:34:13 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_check_file(char *path)
{
   if (!path)
      return (0);//todo error exit
   printf("-for %s\n", path);
   printf("F_OK\n");
   if (access(path, F_OK) == 0)
   {
      printf("OK\n");
   }
   else
   {
      printf("NO\n");
      return (0);
   }
   printf("R_OK\n");
   if (access(path, R_OK) == 0)
   {
       printf("OK\n");
   }
   else
   {
       printf("NO\n");
       return (0);
   }
   printf("W_OK\n");
   if (access(path, W_OK) == 0)
   {
       printf("OK\n");
   }
   else
   {
       printf("NO\n");
   }

   printf("X_OK\n");
   if (access(path, X_OK) == 0)
   {
       printf("OK\n");
   }
   else
   {
       printf("NO\n");
       return (0);
   }
   return 1;
}

 //int access(const char *pathname, int mode);
    // F_OK — file exist
    // R_OK — read
    // W_OK — write
    // X_OK — execution
    
    