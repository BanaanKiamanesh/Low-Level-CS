#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    int *coeffs;
    int degree;
};

struct Polynomial Create(int A[], int N)
{
    struct Polynomial poly;
    poly.degree = N - 1;
    poly.coeffs = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        poly.coeffs[i] = A[i];

    return poly;
}

void Display(struct Polynomial poly)
{
    for (int i = 0; i <= poly.degree; i++)
        if (poly.coeffs[i] != 0)
        {
            printf("%dx^%d", poly.coeffs[i], poly.degree - i);
            if (i < poly.degree && poly.coeffs[i + 1] != 0)
                printf(" + ");
        }

    printf("\n");
}

int Eval(struct Polynomial poly, int x)
{
    int result = 0;
    for (int i = 0; i <= poly.degree; i++)
        result += poly.coeffs[i] * pow(x, poly.degree - i);

    return result;
}

struct Polynomial Add(struct Polynomial p1, struct Polynomial p2)
{
    int maxDegree = (p1.degree > p2.degree) ? p1.degree : p2.degree;
    int minDegree = (p1.degree < p2.degree) ? p1.degree : p2.degree;

    struct Polynomial result;
    result.degree = maxDegree;
    result.coeffs = (int *)malloc((maxDegree + 1) * sizeof(int));

    for (int i = 0; i <= maxDegree; i++)
        result.coeffs[i] = 0;

    for (int i = 0; i <= minDegree; i++)
        result.coeffs[maxDegree - i] = p1.coeffs[p1.degree - i] + p2.coeffs[p2.degree - i];

    if (p1.degree > p2.degree)
        for (int i = minDegree + 1; i <= maxDegree; i++)
            result.coeffs[maxDegree - i] = p1.coeffs[p1.degree - i];

    else if (p2.degree > p1.degree)
        for (int i = minDegree + 1; i <= maxDegree; i++)
            result.coeffs[maxDegree - i] = p2.coeffs[p2.degree - i];

    return result;
}

int main()
{
    int A[] = {1, 2, 2};
    int N = sizeof(A) / sizeof(A[0]);

    int B[] = {1, 3, 4, 5};
    int M = sizeof(B) / sizeof(B[0]);

    struct Polynomial poly1 = Create(A, N);
    struct Polynomial poly2 = Create(B, M);

    printf("Polynomial 1: ");
    Display(poly1);

    printf("Polynomial 2: ");
    Display(poly2);

    struct Polynomial sumPoly = Add(poly1, poly2);
    printf("Sum of polynomials: ");
    Display(sumPoly);

    int x = 1;
    int result = Eval(sumPoly, x);
    printf("Sum evaluated at x = %d: %d\n", x, result);

    free(poly1.coeffs);
    free(poly2.coeffs);
    free(sumPoly.coeffs);

    return 0;
}
