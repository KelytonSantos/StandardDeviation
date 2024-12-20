// Programa para calculo de desvio padrão
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>

double standard_deviation(int cases, double *exp);
double average(int cases, double *exp);

int main()
{
    int cases = 0;

    printf("Digite a quantidade de experimentos: ");
    scanf("%d", &cases);

    double *experiments = (double *)malloc(cases * sizeof(double));

    if (experiments == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < cases; i++)
    {
        printf("Digite a medicao do experimento %d: ", i + 1);
        scanf("%lf", &experiments[i]);
    }

    double stdDeviation = standard_deviation(cases, experiments);

    printf("\n\n\n        Media: %.*g\n", DBL_DIG, average(cases, experiments));
    printf("        Desvio padrao: %.*g\n\n\n", DBL_DIG, stdDeviation);

    free(experiments);
    return 0;
}

double standard_deviation(int cases, double *exp)
{
    double avg = average(cases, exp);
    double sum = 0.00;

    for (int i = 0; i < cases; i++)
    {
        sum += pow(exp[i] - avg, 2);
    }

    double stdDeviation = sqrt(sum / (cases - 1));

    return stdDeviation;
}

double average(int cases, double *exp)
{
    double avg = 0.00, sum = 0.00;

    for (int i = 0; i < cases; i++)
    {
        sum += exp[i];
    }

    return avg = sum / cases;
}