#include <stdlib.h>

void safe_free(char **ptr)
{
    if (*ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL; // Обнуление указателя после освобождения
    }
}

int main()
{
    char *str = (char *)malloc(100 * sizeof(char)); // Выделение памяти
    safe_free(&str);                                // Безопасное освобождение
    // После этого str равен NULL
    return 0;
}
//----------------------------------------

#include <stdlib.h>

void safe_free_2d(char **ptr, int size)
{
    int i = 0;

    if (ptr != NULL)
    {
        while (i < size)
        {
            if (ptr[i] != NULL)
            {
                free(ptr[i]);
                ptr[i] = NULL;
            }
            i++;
        }
        free(ptr); // Освобождение основного массива
    }
}

int main()
{
    int size = 5;
    char **str_array = (char **)malloc(size * sizeof(char *));

    int i = 0;
    while (i < size)
    {
        str_array[i] = (char *)malloc(100 * sizeof(char));
        i++;
    }

    safe_free_2d(str_array, size); // Безопасное освобождение двумерного массива

    // Обнуление указателя в main
    str_array = NULL;

    return 0;
}
//----------------------------------------
#include <stdlib.h>

void safe_free_int(int **ptr)
{
    if (*ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL; // Обнуление указателя
    }
}

int main()
{
    int *num = (int *)malloc(sizeof(int));
    safe_free_int(&num); // Безопасное освобождение
    // num теперь равен NULL
    return 0;
}

//----------------------------------------
#include <stdlib.h>

void safe_free_2d_int(int **ptr, int rows)
{
    int i = 0;

    if (ptr != NULL)
    {
        while (i < rows)
        {
            if (ptr[i] != NULL)
            {
                free(ptr[i]);
                ptr[i] = NULL;
            }
            i++;
        }
        free(ptr); // Освобождение массива указателей
    }
}

int main()
{
    int rows = 3;
    int **num_array = (int **)malloc(rows * sizeof(int *));

    int i = 0;
    while (i < rows)
    {
        num_array[i] = (int *)malloc(4 * sizeof(int));
        i++;
    }

    safe_free_2d_int(num_array, rows); // Безопасное освобождение двумерного массива

    // Обнуление указателя в main
    num_array = NULL;

    return 0;
}
//----------------------------------------

#include <stdlib.h>

typedef struct s_list
{
    int data;
    struct s_list *next;
} t_list;

void safe_free_list(t_list **stack)
{
    t_list *tmp;

    while (*stack != NULL)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }

    *stack = NULL; // Обнуление указателя на начало списка
}

int main()
{
    t_list *stack = (t_list *)malloc(sizeof(t_list));
    stack->next = NULL; // Пример упрощенного списка с одним элементом

    safe_free_list(&stack); // Безопасное освобождение связного списка
    // stack теперь равен NULL

    return 0;
}