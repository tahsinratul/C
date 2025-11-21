// iteration method
#include <stdio.h>
#include <math.h>
int main()
{
    float f(float);
    float p(float);
    float dp(float);
    float x0, x1, x, tol = 0.0001, h;
    int i;
    printf("enter the initial guess x0\n");
    scanf("%f", &x0);
    if (fabs(dp(x0)) >= 1)
        printf(" the initial guess value x0 is not suitable\n");
    else
    {
        h = fabs(x0);
        printf("the ith iterative is\n");
        printf("ite.no\t\t\t x\n");
        for (i = 1; h > tol; i++)
        {
            x1 = p(x0);
            h = fabs(x0 - x1);
            x0 = x1;
            printf("%d\t\t\t%f\n", i, x1);
        }
        printf("the functional value at x1 is f(%f)=%f\n", x1, f(x1));
        printf("the iteration number is =%d\n", i - 1);
    }
}
float f(float x)
{
    return (1 + pow(x, 2) - pow(x, 3));
}
float p(float x)
{
    return (pow(x * x + 1, .3333));
}
float dp(float x)
{
    return ((1 / 3) * 2 * x * (pow(x * x + 1, -.666)));
}