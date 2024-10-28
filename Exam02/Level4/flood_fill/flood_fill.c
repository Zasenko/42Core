typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;    

void  fill(char **tab, t_point size, char color, int row, int col)
{
  if (row < 0 || row >= size.y || col < 0 || row >= size.x)
    return;

  if (tab[row][col] == color)
  {
    tab[row][col] = 'F';
    fill(tab, size, color, row + 1, col);
    fill(tab, size, color, row - 1, col);
    fill(tab, size, color, row, col + 1);
    fill(tab, size, color, row, col - 1);
  }
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
  if (!tab || !*tab)
    return;

  int row = begin.y;
  int col = begin.x;
  char color = tab[row][col];

  fill(tab, size, color, row, col);
}


// #include <stdlib.h>
// #include <stdio.h>

// char** make_area(char** zone, t_point size)
// {
//   char** new;

//   new = malloc(sizeof(char*) * size.y);
//   for (int i = 0; i < size.y; ++i)
//   {
//     new[i] = malloc(size.x + 1);
//     for (int j = 0; j < size.x; ++j)
//       new[i][j] = zone[i][j];
//     new[i][size.x] = '\0';
//   }

//   return new;
// }

// int main(void)
// {
//   t_point size = {8, 5};
//   char *zone[] = {
//     "11111111",
//     "10001001",
//     "10010001",
//     "10110001",
//     "11100001",
//   };

//   char**  area = make_area(zone, size);
//   for (int i = 0; i < size.y; ++i)
//     printf("%s\n", area[i]);
//   printf("\n");

//   t_point begin = {7, 4};
//   flood_fill(area, size, begin);
//   for (int i = 0; i < size.y; ++i)
//     printf("%s\n", area[i]);
//   return (0);
// }