#include <stdio.h>

// recursive nested function calls
int fun(int n)
{
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));
}

int main()
{
    printf("%d", fun(85));
    return 0;
}