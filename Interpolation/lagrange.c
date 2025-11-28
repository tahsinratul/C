// Lagrange iteration
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, n;
    float sum = 0.0, a, x[10], y[10], prod = 1.0;
    printf("enter the number of data \n");
    scanf("%d", &n);
    printf("enter the values of data (independent)\n");
    for (i = 0; i < n; ++i)
        scanf("%f", &x[i]);
    printf("enter the value of data (dependent)\n");
    for (i = 0; i < n; ++i)
        scanf("%f", &y[i]);
    printf("enter the value where we want to interpolate\n");
    scanf("%f11.3", &a);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i != j)
                prod = prod * ((a - x[j]) / (x[i] - x[j]));
        }
        sum = sum + prod * y[i];
    }
    printf("the interpolated value at %f is %f \n", a, sum);
}