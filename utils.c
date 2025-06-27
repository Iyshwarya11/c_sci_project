#include <stdio.h>
#include <time.h>
#include "utils.h"

clock_t start_time, end_time;
int ENABLE_LOG = 0;  // Set to 1 to enable debug logs

void start_timer() {
    start_time = clock();
}

void stop_timer() {
    end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("⏱ Execution Time: %.5f seconds\n", time_taken);
}

void print_title(const char* title) {
    printf("\n==== %s ====\n", title);
}

void log_debug(const char* message) {
    if (ENABLE_LOG)
        printf("[DEBUG] %s\n", message);
}
