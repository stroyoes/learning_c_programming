#include "time_in_words.h"

const char *numbers[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen",
    "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
    "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight",
    "twenty nine", "half"
};

/**
* Function to print time in words
  */  
void timeInWords(int hours, int minutes, char *result, size_t size) {

  if (minutes == 0) {
    snprintf(result, size, "%s o' clock\n", numbers[hours]); //  NOTE: `snprintf` : instead of printing to 
                                                             //        the console, it writes the 
                                                             //        formatted output to a character array
                                                             //        with a specific buffer size. 
  } else if (minutes == 15 || minutes == 30) {
    snprintf(result, size, "%s past %s\n", numbers[minutes], numbers[hours]);
  } else if (minutes == 45) {
    snprintf(result, size, "quarter to %s\n", numbers[(hours % 12) + 1]); //  NOTE: Ensure hours doesnt go 
                                                                          //        out of bound.  
  } else if (minutes < 30) {
    snprintf(result, size, "%s minute%s past %s\n", numbers[minutes], (minutes == 1) ? "" : "s", numbers[hours]);
  } else {
    snprintf(result, size, "%s minute%s to %s\n", numbers[60 - minutes], ((60 - minutes) == 1) ? "" : "s", numbers[hours + 1]);
  }
}
