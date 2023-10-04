#include <stdio.h>
#include <stdlib.h>

int _abs(int x)
{
  if (x < 0)
    x = -x;
  return x;
}

int getmark(int row, int column, int size)
{
  int mid = (size + 1) / 2, dest = _abs(row - mid) + _abs(column - mid), ans;

  if (dest < mid)
  {
    ans = 1;
  }
  else
  {
    ans = 0;
  }
  return ans;
}

void draw(int rows, int columns, int size)
{
  int h = (size - 1) * rows + 1, w = (size - 1) * columns + 1, ismark, origi, origj;

  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      origi = (i - 1) % (size - 1) + 1;
      origj = (j - 1) % (size - 1) + 1;
      ismark = getmark(origi, origj, size);

      if (ismark)
      {
        putchar('*');
      }
      else
      {
        putchar(' ');
      }
    }
    putchar('\n');
  }
}

int main(int argc, char *argv[])
{
  int rows, columns;
  if (argc != 4)
    return -1;
  draw(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  return 0;
}