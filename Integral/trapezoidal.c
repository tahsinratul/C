// Trapezoidal rules
#include <stdio.h>
#include <math.h>
int main()
{
    float f(float x);
    float result, a, b, sum, h;
    int i, n;
    printf("enter the subdivision n\n");
    scanf("%d", &n);
    printf("enter the lower limit a\n");
    scanf("%f", &a);
    printf("enter the upper limit b\n");
    scanf("%f", &b);
    sum = 0.0;
    h = (b - a) / n;
    for (i = 1; i < n; i++)
    {
        sum = sum + f(a + i * h);
        result = (h / 2) * (f(a) + f(b) + 2 * sum);
    }
    printf("the result is %.4f\n", result);
}
float f(float x)
{
    return (1 / (1 + x));
}