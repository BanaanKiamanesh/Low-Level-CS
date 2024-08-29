#include <stdio.h>

// This is where function evaluation happens after computation is done
// This structure can simply converted to a for/while loop
void fun(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        fun(n - 1);
    }
}

int main()
{
    fun(3);
    return 0;
}