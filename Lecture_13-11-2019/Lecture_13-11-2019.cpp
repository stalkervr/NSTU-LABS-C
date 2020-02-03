// Lecture_13-11-2019.cpp : Управляющие конструкции
// Даны два целых числа (положительных) необходимо найти наибольший общий делитель.Т.е максимальное положительное число которое делит и М и Н без остатка.

#include <stdio.h>
#include <locale.h>

int EuclideanAlgorithm(int M, int N);

int main()
{
    int M = 12, N = 64, resault;

    resault = EuclideanAlgorithm(N, M);
    printf("resault => %d", resault);
    return 0;
}

/*Алгори́тм Евкли́да — эффективный алгоритм для нахождения наибольшего общего делителя двух целых чисел(или общей меры двух отрезков). ... Процесс повторяется, пока числа не станут равными.Найденное число и есть наибольший общий делитель исходной пары
*/

int EuclideanAlgorithm(int M, int N)
{
    //int nod = 0;
    while (M != N)
    {
        if (M > N)
        {
            M = M - N;
        }
        else
        {
            N = N - M;
        }
    }
    return M;
}
