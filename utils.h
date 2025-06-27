#ifndef UTILS_H
#define UTILS_H

#include <time.h>

void start_timer();
void stop_timer();
void print_title(const char* title);
void log_debug(const char* message); // Optional
extern int ENABLE_LOG;

#endif
