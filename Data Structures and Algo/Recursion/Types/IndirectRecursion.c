#include <stdio.h>

// Functions calling eachother recursively

// Function Proto
void funA(int);
void funB(int);

void funA(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        funA(n / 2);
    }
}

int main()
{
    funA(20);
    return 0;
}