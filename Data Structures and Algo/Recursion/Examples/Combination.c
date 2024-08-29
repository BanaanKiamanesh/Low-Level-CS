#include <stdio.h>

// Actual Combination nCr = n! / [r! * (n-r)!]
// Recursive Combination based on Pascal's Triangle
int C(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return C(n - 1, r) + C(n - 1, r - 1);
}

int main()
{
    printf("%d\n", C(14, 2));
    return 0;
}