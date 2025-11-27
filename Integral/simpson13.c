// Simpson 1/3
#include <stdio.h>
#include <math.h>
int main()
{
    float f(float);
    float a, b, h, result;
    float sum_even = 0.0, sum_odd = 0.0;
    int i, n;
    printf("enter the number of subdivision\n");
    scanf("%d", &n);
    printf("enter the lower limit a\n");
    scanf("%f", &a);
    printf("enter the upper limit b\n");
    scanf("%f", &b);
    h = (b - a) / n;
    for (i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum_even = sum_even + f(a + i * h);
        else
            sum_odd = sum_odd + f(a + i * h);
        result = (h / 3) * (f(a) + f(b) + 2 * sum_even + 4 * sum_odd);
    }
    printf("the integral value with respect to simpson1/3 rule is %5f\n", result);
}
float f(float x)
{
    return 1 / (1 + x);
}