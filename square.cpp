#include <stdio.h>
#include <math.h>

enum RootsNumber {
    ZERO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INFINITY_SOLUTIONS,
};

enum RootsNumber solve_square(double, double, double, double*, double*);
void output_solutions(double, double, enum RootsNumber);
void input_coef(double *a, double *b, double *c);
enum RootsNumber lin_eq(double b,double c, double *x1);
bool is_zero(double num);
void clear_buffer();


int main()
{
    printf("enter a,b,c \n");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    input_coef(&a, &b, &c);

    RootsNumber nroots = solve_square(a, b, c, &x1, &x2);

    output_solutions(x1, x2, nroots);
}

bool is_zero(double num)
{
    if (fabs(num) < 1e-8)
    {
        return true;
    }
    return false;
}

enum RootsNumber solve_square(double a, double b, double c, double *x1, double *x2)
{
    double d = b*b-4*a*c;
    if (!is_zero(a))
    {
        if (d < 0)
        {
            return ZERO_SOLUTIONS;
        }
        else if(is_zero(d))
        {
            *x1 = -b/(2*a);
            return ONE_SOLUTION;
        }
        else
        {
            *x1= (-b + sqrt(d))/(2*a);
            *x2= (-b - sqrt(d))/(2*a);
            return TWO_SOLUTIONS;
        }
    }
    else
    {
        return lin_eq(a, b, x1);
    }
}

void output_solutions(double x1, double x2, enum RootsNumber nroots) {
    switch (nroots)
    {
        case ZERO_SOLUTIONS: printf ("No roots\n");
                break;

        case ONE_SOLUTION: printf ("amount of roots %d  x = %lg  \n", nroots, x1);
                break;

        case TWO_SOLUTIONS: printf ("amount of roots %d  x1 = %lg x2 = %lg \n", nroots, x1, x2);
                break;

        case INFINITY_SOLUTIONS: printf("inf amount of solutions ");

        default: printf ("the code sucks!");
        }

}

void input_coef(double *a, double *b, double *c)
{
    while (scanf ("%lf %lf %lf", a, b, c) != 3)
    {
        printf("incorrect input \n");
        printf("try again\n");
        clear_buffer();// clear_buffer
    }
}

enum RootsNumber lin_eq(double b,double c, double *x1)
{
    if (is_zero(b))
    {
        if (is_zero(c))
        {
            return INFINITY_SOLUTIONS;
        }
        else
        {
            return ZERO_SOLUTIONS;
        }
    }
    else
    {
        *x1 = -c/b;
        return ONE_SOLUTION;
    }
}

void clear_buffer()
{
    while (getchar() != '\n') {}
}
