#include <stdio.h>
#include "rle.h"

int main() {
  char encoded[MAX_BUFFER_LEN];
  char decoded[MAX_BUFFER_LEN];

  encode("WWWWWWWWWWWBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB", encoded);
  printf("Encoded: %s\n", encoded);

  decode(encoded, decoded); // Decode the encoded string 
  printf("Decoded: %s\n", decoded);

  return 0;
}

