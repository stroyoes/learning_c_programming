#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t max = 0;

  for (size_t i = 0; i < scores_len; ++i) {
    if (scores[i] > max) max = scores[i];
  }
  return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
  size_t output_len = 0;

  for (size_t i = 0; i < scores_len; ++i) {
    if (output_len < 3) {
      output[output_len++] = scores[i];
    } else {
      if (scores[i] > output[2]) {
        output[2] = scores[i];
      }
    }

    //  NOTE:  Sorting the size 3 array to desceding order. 
    
    if (output_len == 3) {
      if (output[2] > output[0]) {

        int32_t swapped = output[0];
        output[0] = output[2];
        output[2] = swapped;

      } 
      if (output[2] > output[1]) {

        int32_t swapped = output[1];
        output[1] = output[2];
        output[2] = swapped;

      }
    }

    if (output_len >= 2 && output[1] > output[0]) {

      int32_t swapped = output[0];
      output[0] = output[1];
      output[1] = swapped;
        
    }
  }

  return output_len;
}

