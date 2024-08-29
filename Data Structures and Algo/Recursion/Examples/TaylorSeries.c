#include <stdio.h>

// Taylor Series Expantion of Exp(x) = 1 + x/1! + x^2/2! + x^3/3! + ...
double exponential(double num, int order)
{
    static float pow = 1, fact = 1;
    if (order == 0)
        return 1;

    else
    {
        double rec = exponential(num, order - 1);
        pow *= num;
        fact *= order;

        return rec + pow / fact;
    }
}

int main()
{
    printf("%lf", exponential(3, 10));
    return 0;
}