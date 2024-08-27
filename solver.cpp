#include <stdio.h>
#include <math.h>


enum RootsNumber {
    ZERO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INFINITY_SOLUTIONS,
};

struct SquareEqData {
    double a,b,c,x1,x2;
    enum RootsNumber nroots;
};

struct LinEqData {
    double b,c,x1;
    enum RootsNumber nroots;
};


void solve_square(struct SquareEqData *);
void output_solutions(struct SquareEqData *);
void input_coeffs(double *, double *, double *);
void lin_eq(struct LinEqData *);

//_______________________________________________________________________________________________________________

void solve_square(struct SquareEqData* variables)
{
    double a = (*variables).a;
    double b = (*variables).b;
    double c = (*variables).c;

    double d = b*b-4*a*c;
    if (!is_zero(a))
    {
        if (d < 0)
        {
            (*variables).nroots = ZERO_SOLUTIONS;
        }
        else if(is_zero(d))
        {
            (*variables).x1 = -b/(2*a);
            (*variables).nroots = ONE_SOLUTION;
        }
        else
        {
            (*variables).x1= (-b + sqrt(d))/(2*a);
            (*variables).x2= (-b - sqrt(d))/(2*a);
            (*variables).nroots = TWO_SOLUTIONS;
        }
    }
    else
    {
        struct LinEqData linear = {.b = b, .c = c, .x1 = 0, .nroots = ZERO_SOLUTIONS};
        lin_eq(&linear);
        (*variables).x1 = linear.x1;
        (*variables).nroots = linear.nroots;
    }
}

//____________________________________________________________________________________________________________________________________

void output_solutions(struct SquareEqData *variables)
{
    switch ((*variables).nroots)
    {
        case ZERO_SOLUTIONS: printf ("No roots\n");
                break;

        case ONE_SOLUTION: printf ("amount of roots %d  x = %lg  \n", (*variables).nroots, (*variables).x1);
                break;

        case TWO_SOLUTIONS: printf ("amount of roots %d  x1 = %lg x2 = %lg \n", (*variables).nroots, (*variables).x1, (*variables).x2);
                break;

        case INFINITY_SOLUTIONS: printf("inf amount of solutions ");
                break;

        default: printf ("the code sucks!");
        }

}

//____________________________________________________________________________________________________________________________________

void input_coeffs(double* a, double* b, double* c)
{
    int n_doubles = 0;
    bool is_buffer_clean = true;
    while (n_doubles != 3 || is_buffer_clean == true)
    {
        n_doubles = scanf("%lf %lf %lf", a, b, c);
        is_buffer_clean = clear_buffer();
        if (n_doubles != 3 || !is_buffer_clean == false)
        {
            printf("error\nwrong input\ntry again\n");
        }
    }
}

//____________________________________________________________________________________________________________________________________

void lin_eq(struct LinEqData *linear)
{
    double b = (*linear).b;
    double c = (*linear).c;
    if (is_zero(b))
    {
        if (is_zero(c))
        {
            (*linear).nroots = INFINITY_SOLUTIONS;
        }
        else
        {
            (*linear).nroots = ZERO_SOLUTIONS;
        }
    }
    else
    {
        (*linear).x1 = -c/b;
        (*linear).nroots = ONE_SOLUTION;
    }
}
