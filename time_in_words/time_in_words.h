#ifndef TIME_IN_WORDS_H
#define TIME_IN_WORDS_H

#include <stdio.h>
#include <string.h>
#include <assert.h>

//  NOTE: The test case struct 
typedef struct {
    int hours;
    int minutes;
    const char *expected;
} TimeTestCase;

//  NOTE: Declare the array 
extern const char *numbers[];

void timeInWords(int hours, int minutes, char *result, size_t size);
void runTestCases(TimeTestCase test_cases[], int num_tests);
void trimNewline(char *str);

#endif

