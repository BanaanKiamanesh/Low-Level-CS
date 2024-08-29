#include <stdio.h>

// This is where function evaluation happens before computation is done
// This structure is often hard to convert to a for/while loop
void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        printf("%d\n", n);
    }
}

int main()
{
    fun(3);
    return 0;
}