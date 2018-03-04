#include <stdio.h>
#include <string.h>

#ifndef _TEST_H
#define _TEST_H

extern int tests_passed;
extern int tests_run;

#define FAIL() printf("FAIL: %s(), line %d\n", __func__, __LINE__)
#define ASSERT(test) do { if (test) { tests_passed++; } else { FAIL(); } tests_run++; } while(0)

#endif /* _TEST_H */