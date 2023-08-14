#pragma once

#include <stdio.h>

typedef enum result_t {
    SUCCESS,
    FAILURE
} result_t;

#define assert(x)                 \
    do {                          \
        if (!(x)) return FAILURE; \
    } while (0)

#define assert_streq(x, y) assert(strcmp(x, y) == 0)

#define assert_symeq(x, y)          \
    assert(x.type == TOKEN_SYMBOL); \
    assert_streq((char *) x.data, y)

#define init_tests() int num_fails = 0

#define report_tests() return num_fails

#define record_test(x)                   \
    do {                                 \
        if (x() == SUCCESS) {            \
            printf(#x " --- Success\n"); \
        } else {                         \
            num_fails += 1;              \
            printf(#x " --- Failure\n"); \
        }                                \
    } while (0)