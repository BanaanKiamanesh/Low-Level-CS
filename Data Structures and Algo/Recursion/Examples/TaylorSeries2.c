#include <stdio.h>

// Horners Law Implementation of Exp(x) leads to O(n)
// exp(x) = 1 + x/1 * [1 + x/2 * [1 + x/3 * [...]]]
double exponential2(double num, int order)
{
    static double s;
    if (order == 0)
        return s;
    else
    {
        s = 1 + num * s / order;
        return exponential2(num, order - 1);
    }
}
int main()
{
    printf("%lf", exponential2(1, 10));
    return 0;
}