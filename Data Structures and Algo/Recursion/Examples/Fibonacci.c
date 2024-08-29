#include <stdio.h>

int fibo(int n)
{
    if (n <= 1)
        return 1;

    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    for (int i = 0; i < 10; i++)
        printf("%d\n", fibo(i));
    return 0;
}

/*
Notes: We can use a data structure like an array or hashmap or anything
    like that to store the elements and trim the recursion tree
    by getting the values from that when if instead of evaluating.
    This way we will only fill it once and use later.
*/