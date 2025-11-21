// bisection method X^3-X-1=0
#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, h, m, tol;
    int i;
    float f(float);

    printf("enter the interval [a,b]\n");
    scanf("%f%f", &a, &b);
    if (f(a) * f(b) == 0)
    {
        if (f(a) == 0 && f(b) == 0)
            printf("the real roots are equal %f and %f\n", a, b);
        else if (f(a) == 0)
            printf("the real root is %f\n", a);
        else
            printf("the real root is %f\n", b);
    }
    else if (f(a) * f(b) < 0)
    {
        printf("enter the tolerance\n");
        scanf("%f", &tol);
        h = fabs(a - b);
        printf("the ith iterative is \n");
        printf("ith no\t\t\t x\n");
        for (i = 1; h > tol; ++i)
        {
            m = (a + b) / 2;
            h = fabs(a - b);
            if (f(a) * f(m) > 0)
                a = m;
            else
                b = m;
            printf("%d\t\t\t %f\n", i, m);
        }
        printf("the functional value at the required approximation root is f(%f)=%f\n", m, f(m));
    }
    else
        printf("there may not be any real roots between %f and %f\n", a, b);
}
float f(float x)
{
    return (pow(x, 3) - x - 1);
}
