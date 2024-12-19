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


 //int access(const char *pathname, int mode);
    // F_OK — file exist
    // R_OK — read
    // W_OK — write
    // X_OK — execution
    
    // if (access(path_file1, F_OK) == 0)
    // {
    //     printf("F_OK\n");
    // }
    // else
    // {
    //     printf("F_OK NO\n");
    // }
    // if (access(path_file1, R_OK) == 0)
    // {
    //     printf("R_OK\n");
    // }
    // else
    // {
    //     printf("R_OK NO\n");
    // }
    // if (access(path_file1, W_OK) == 0)
    // {
    //     printf("W_OK\n");
    // }
    // else
    // {
    //     printf("W_OK NO\n");
    // }
    // if (access(path_file1, F_OK) == 0)
    // {
    //     printf("X_OK\n");
    // }
    // else
    // {
    //     printf("X_OK NO\n");
    // }