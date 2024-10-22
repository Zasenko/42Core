#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    void *num;
    struct s_stack *next;
} t_stack;

int return_error(void);
size_t ft_strlen(const char *s);
void free_str(char **str);
char *ft_strjoin_sep(char const *s1, char const *s2, char const sep);
char *args_to_str(char **argv);
char **ft_split(char const *s, char c);

#endif