#include <stdio.h>
#define A 1
#define B 2
#define C 3

void TOH(int n, int a, int b, int c)
{
    static int cnt = 0;
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        printf("%d. Move from %d, to %d\n", cnt, a, c);
        cnt += 1;

        TOH(n - 1, b, a, c);
    }
}

int main()
{
    TOH(4, A, B, C);
    return 0;
}