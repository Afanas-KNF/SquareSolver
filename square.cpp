#include <stdio.h>
#include <math.h>

#define TESTS // (добавишь это в мейне) сделай через условную компил€цию, чтобы если TESTS было задефайнено, запускались тесты, а иначе запускаетс€ обычна€ прога (когда вводишь коэффициенты и тд)

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
bool is_zero(double num);
void clear_buffer();
int run_tests();
bool is_equal(double first, double second);



//__________________________________________________________________________________________________________________________________

int main()
{
    printf("enter a,b,c \n");

    struct SquareEqData variables = {0, 0, 0, 0, 0, ZERO_SOLUTIONS};

    input_coeffs(&(variables.a), &(variables.b), &(variables.c));

    solve_square(&variables);

    output_solutions(&variables);

    run_tests();

}

//____________________________________________________________________________________________________________________________________

bool is_zero(double num)
{
    if (fabs(num) < 1e-8)      // const EPSILON
    {
        return true;
    }
    return false;
}

//____________________________________________________________________________________________________________________________________

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
    while (scanf ("%lf %lf %lf", a, b, c) != 3)
    {
        printf("incorrect input \n");
        printf("try again\n");
        clear_buffer();
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

//____________________________________________________________________________________________________________________________________

void clear_buffer()
{
    while (getchar() != '\n') {}
}

//____________________________________________________________________________________________________________________________________

bool is_equal(double first, double second)
{
    if (fabs(first - second) < 1e-8)       // const
    {
        return true;
    }
    return false;
}

//____________________________________________________________________________________________________________________________________

int run_tests()
{
//    SquareEqData tests[] = {
//        {1, 5, 4, -1, -4, TWO_SOLUTIONS},
//        {0, 0, 0, 0, 0, INFINITY_SOLUTIONS},
//
//    };
    SquareEqData tests[10] = {};
    tests[0] = {1, 5, 4, -1, -4, TWO_SOLUTIONS};    // нормальный случай
    tests[1] = {0, 0, 0, 0, 0, INFINITY_SOLUTIONS}; // бесконечное колчво корней
    tests[2] = {0, 0, 7.7, 0, 0, ZERO_SOLUTIONS};   // нет корней
    tests[3] = {0, 3.4, 1.7, -2, -2, ONE_SOLUTION}; // линейное уравнение
    tests[4] = {1, -2, 1, 1, 1, ONE_SOLUTION};      // d=0
    tests[5] = {2, 4.12, 4, 0, -0, ZERO_SOLUTIONS}; // d<0
    tests[6] = {1, 5, 4, -1, -4, TWO_SOLUTIONS};    //
    tests[7] = {1, 5, 4, -1, -4, TWO_SOLUTIONS};
    tests[8] = {1, 5, 4, -1, -4, TWO_SOLUTIONS};
    tests[9] = {1, 5, 4, -1, -4, TWO_SOLUTIONS};
    // 10 is magic const, remember what I told you about sizeof
    for (int i = 0; i < 10; i++)
    {
        struct SquareEqData current = {tests[i].a, tests[i].b, tests[i].c, tests[i].x1, tests[i].x2, tests[i].nroots}; // initialize by zero
        solve_square(&current);
        if( !is_equal(tests[i].x1, current.x1) || !is_equal(tests[i].x2, current.x2) || !is_equal(tests[i].nroots, current.nroots))
        {
            printf("\nerror test number %d, nroots = %d x1 = %lf, x2 = %lf\n"
                   "correct: nrootscor = %d, x1cor = %lf, x2cor = %lf\n", i + 1,
                    current.nroots, current.x1, current.x2,
                    tests[i].nroots, tests[i].x1, tests[i].x2);
        }
        else
        {
            printf("\napproved!\n");
        }     // to function
    }
    return 0;
}

//____________________________________________________________________________________________________________________________________
