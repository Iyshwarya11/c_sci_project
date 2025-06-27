#include <stdio.h>
#include "matrix_ops.h"
#include "stats_ops.h"
#include "regression.h"
#include "graph_ops.h"
#include "calculus.h"
#include "optimize.h"
#include "utils.h"

int main() {
    int choice;
    do {
        printf("\n=== C-SCI TOOLKIT MENU ===\n");
        printf("1. Matrix Operations\n");
        printf("2. Statistical Analysis\n");
        printf("3. Linear Regression\n");
        printf("4. Graph Traversal\n");
        printf("5. Calculus (Derivatives & Integration)\n");
        printf("6. Root Finding (Newton-Raphson)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: matrix_menu(); break;
            case 2: stats_menu(); break;
            case 3: regression_menu(); break;
            case 4: graph_menu(); break;
            case 5: calculus_menu(); break;
            case 6: optimize_menu(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
    return 0;
}
