#include <stdio.h>

int power(int base, int pow)
{
    if (pow == 1)
        return base;
    else
        return base * power(base, pow - 1);
}

int main()
{
    printf("%d", power(3, 4));
    return 0;
}