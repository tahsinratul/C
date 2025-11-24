// Simpson 3/8
#include <stdio.h>
#include <math.h>
int main()
{
    float f(float x);
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
        if (i % 3 == 0)
            sum_even = sum_even + f(a + i * h);
        else
            sum_odd = sum_odd + f(a + i * h);
        result = (3 * h / 8) * (f(a) + f(b) + 3 * sum_odd + 2 * sum_even);
    }
    printf("the result is %f", result);
}
float f(float x)
{
    return 1 / (1 + x);
}