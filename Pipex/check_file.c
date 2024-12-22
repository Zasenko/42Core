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

int check_file(char *path)
{
   if (!path)
      return (-1);//todo error exit
   if (access(path, F_OK) == 0)
   {
       printf("F_OK\n");
   }
   else
   {
       perror("F_OK NO\n");
       return (-1);
   }
   if (access(path, R_OK) == 0)
   {
       printf("R_OK\n");
   }
   else
   {
       printf("R_OK NO\n");
       return (-1);
   }
   if (access(path, W_OK) == 0)
   {
       printf("W_OK\n");
   }
   else
   {
       printf("W_OK NO\n");
   }
   if (access(path, F_OK) == 0)
   {
       printf("X_OK\n");
       return (-1);
   }
   else
   {
       printf("X_OK NO\n");
       return (-1);
   }
   return 1;
}

 //int access(const char *pathname, int mode);
    // F_OK — file exist
    // R_OK — read
    // W_OK — write
    // X_OK — execution
    
    