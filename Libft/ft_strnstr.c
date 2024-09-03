#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i + f < len)
	{
		f = 0;
		while (big[i + f] != '\0' && big[i + f] == little[f])
		{
			f++;
			if (little[f] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}

#include <string.h>
#include <assert.h>

void test_strnstr()
{
    char haystack[] = "Hello, World!";
    char needle1[] = "World";
    char needle2[] = "Hello";
    char needle3[] = "";
    char needle4[] = "!";
    char needle5[] = "Nonexistent";

    // Test 1: Обычное вхождение подстроки в середине строки
    char *result = ft_strnstr(haystack, needle1, 13);
    assert(result == &haystack[7]); // 'World' начинается с 7 позиции

    // Test 2: Вхождение подстроки в начале строки
    result = ft_strnstr(haystack, needle2, 5);
    assert(result == &haystack[0]); // 'Hello' начинается с 0 позиции

    // Test 3: Пустая подстрока всегда должна возвращать начало haystack
    result = ft_strnstr(haystack, needle3, 13);
    assert(result == haystack);

    // Test 4: Поиск символа, который находится в конце строки
    result = ft_strnstr(haystack, needle4, 13);
    assert(result == &haystack[12]); // '!' находится на 12 позиции

    // Test 5: Поиск подстроки, которой нет в haystack
    result = ft_strnstr(haystack, needle5, 13);
    assert(result == NULL);

    // Test 6: Проверка, когда len меньше длины подстроки
    result = ft_strnstr(haystack, needle1, 5);
    assert(result == NULL); // 'World' не может быть найдено в первых 5 символах

    // Test 7: Проверка на частичное совпадение, но не полное
    result = ft_strnstr(haystack, "Hell", 4);
    assert(result == &haystack[0]); // 'Hell' найдено в первых 4 символах

    // Test 8: Проверка на NULL haystack
    result = ft_strnstr(NULL, needle1, 5);
    assert(result == NULL); // NULL в haystack должен вернуть NULL

    // Test 9: Проверка на NULL needle
    result = ft_strnstr(haystack, NULL, 5);
    assert(result == NULL); // NULL в needle должен вернуть NULL

    printf("Все тесты пройдены успешно.\n");
}

int main()
{
    test_strnstr();
    return 0;
}