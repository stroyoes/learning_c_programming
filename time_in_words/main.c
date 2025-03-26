#include "time_in_words.h"

// Helper function to remove trailing newline
void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to run test cases
void runTestCases(TimeTestCase test_cases[], int num_tests) {
  char result[50];
  for (int i = 0; i < num_tests; i++) {
    timeInWords(test_cases[i].hours, test_cases[i].minutes, result, sizeof(result));

    // Trim newline before comparison
    trimNewline(result);
      
    // Print each test result for better debugging
    printf("Test %d: %d:%d -> Expected: \"%s\", Got: \"%s\"\n", i + 1, test_cases[i].hours, test_cases[i].minutes, test_cases[i].expected, result);
      
    assert(strcmp(result, test_cases[i].expected) == 0 && "Test failed! ❌");

    printf("✅ Test %d passed!\n", i + 1);

        
  }

    printf("All tests passed! 🎉\n");
}

int main() {
    // Define test cases
    TimeTestCase test_cases[] = {
        {5, 0, "five o' clock"},
        {5, 15, "quarter past five"},
        {5, 45, "quarter to six"},
        {5, 40, "twenty minutes to six"},
        {5, 1, "one minute past five"},
        {5, 28, "twenty eight minutes past five"}, //  TODO: Add more test cases 🤗 ... 
    };

    // Calculate number of test cases
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // Run test cases
    runTestCases(test_cases, num_tests);

    return 0;
}

