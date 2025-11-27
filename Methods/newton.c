// newton method x^3-2x-5=0
#include <stdio.h>
#include <math.h>
int main()
{
    float f(float);
    float df(float);
    float x0, x, h, tol = 0.001;
    int i;
    printf("enter the initial guess x0\n");
    scanf("%f", &x0);
    if (df(x0) == 0)
        printf("the initial guess value is not suitable\n");
    else
    {
        h = fabs(x0 - x);
        for (i = 1; h > tol; i++)
        {
            x = x0 - (f(x0) / df(x0));
            h = fabs(x0 - x);
            x0 = x;
            printf("%d\t\t\t%f\n", i, x);
        }
        printf("the functional value at x is f(%.6f)=%.6f\n", x, f(x));
        printf("the iteration number is =%d\n", i);
    }
}
float f(float x)
{
    return (pow(x, 3) - 2 * x - 5);
}
float df(float x)
{
    return (3 * pow(x, 2) - 2);
}