#include <stdio.h>
#include <math.h>
#include "calculus.h"

// Example function: f(x) = x^2
double f(double x) {
    return x * x;
}

double derivative(double x) {
    double h = 1e-5;
    return (f(x + h) - f(x - h)) / (2 * h);  // Central difference
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    return sum * h;
}

void calculus_menu() {
    int choice;
    double x, a, b;
    int n;

    do {
        printf("\n--- Calculus Operations ---\n");
        printf("1. Numerical Derivative\n");
        printf("2. Numerical Integration (Trapezoidal Rule)\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("f(x) = x^2\n");
                printf("Enter value of x: ");
                scanf("%lf", &x);
                printf("Approximate derivative f'(%0.4lf) ≈ %.5lf\n", x, derivative(x));
                break;

            case 2:
                printf("f(x) = x^2\n");
                printf("Enter limits a and b: ");
                scanf("%lf %lf", &a, &b);
                printf("Enter number of intervals (n): ");
                scanf("%d", &n);
                printf("Approximate integral ≈ %.5lf\n", trapezoidal(a, b, n));
                break;

            case 0:
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
}
