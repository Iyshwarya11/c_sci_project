#include <stdio.h>
#include "regression.h"

void regression_menu() {
    int n;
    double x[100], y[100], sumX = 0, sumY = 0, sumXY = 0, sumXX = 0, m, c;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    printf("Enter X values:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &x[i]);
    printf("Enter Y values:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &y[i]);

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }

    m = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    c = (sumY - m * sumX) / n;

    printf("Regression Line: Y = %.2lfX + %.2lf\n", m, c);
}
