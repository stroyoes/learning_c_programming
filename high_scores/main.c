#include <stdio.h>

#include "high_scores.h"

int main(void) {
  int32_t scores[] = {30, 50, 20, 40, 80};
  size_t scores_len = sizeof(scores) / sizeof(scores[0]);

  printf("Latest score: %" PRId32 "\n", latest(scores, scores_len));
  printf("Personal best: %" PRId32 "\n", personal_best(scores, scores_len));
    
  int32_t top_three[3] = {0};
  size_t top_count = personal_top_three(scores, scores_len, top_three);
 
  printf("Top %zu scores: ", top_count);
  
  for (size_t i = 0; i < top_count; ++i) {
    printf("%" PRId32 " ", top_three[i]);
  }

  printf("\n");

}

