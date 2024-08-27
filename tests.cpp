#include <stdio.h>
#include <math.h>
#include <assert.h>


int run_tests();
void run_test(SquareEqData *, const SquareEqData *); // move this references to pointers

//_______________________________________________________________________________________________________________

int run_tests()
{
    SquareEqData tests[] = {
        {1, 5, 4, -1, -4, TWO_SOLUTIONS},   // ���������� ������
        {0, 0, 0, 0, 0, INFINITY_SOLUTIONS},// ����������� ������ ������
        {0, 0, 7.7, 0, 0, ZERO_SOLUTIONS},  // ��� ������4
        {0, 3.4, 1.7, -0.5, 0, ONE_SOLUTION},// �������� ���������
        {1, -2, 1, 1, 0, ONE_SOLUTION},     // d=0
        {2, 4.12, 4, 0, -0, ZERO_SOLUTIONS},// d<0
        {1, 5, 4, -1, -4, TWO_SOLUTIONS},   // how to change so that if one solutions x2 != 0
        {1, 5, 4, -1, -4, TWO_SOLUTIONS},
        {1, 5, 4, -1, -4, TWO_SOLUTIONS},
        {1, 5, 4, -1, -4, TWO_SOLUTIONS}
    };
    int numtest = sizeof(tests) / sizeof(SquareEqData);
    for (int i = 0; i < numtest ; i++)
    {
        struct SquareEqData current = {tests[i].a, tests[i].b, tests[i].c, 0, 0, ZERO_SOLUTIONS};
        printf("\ntest number %d\n", i + 1);
        run_test(&current, &tests[i]);
    }
    return 0;
}

//_______________________________________________________________________________________________________________

void run_test(SquareEqData* current, const SquareEqData* answer)
{
    assert(current != NULL);
    solve_square(current);

    if( !is_equal((*answer).x1, (*current).x1) || !is_equal((*answer).x2, (*current).x2) || !is_equal((*answer).nroots, (*current).nroots))
    {
        printf("\nerror nroots = %d x1 = %lf, x2 = %lf\n"
                "correct: nrootscor = %d, x1cor = %lf, x2cor = %lf\n",
                (*current).nroots, (*current).x1, (*current).x2,
                (*answer).nroots, (*answer).x1, (*answer).x2);
    }
    else
    {
        printf("approved!\n");
    }     // to function_________________________________________________________________________________________________________________________________
}
