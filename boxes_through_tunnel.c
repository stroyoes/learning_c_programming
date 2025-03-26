#include <stdio.h>

int main() {
  int N, tunnel_height;

  printf("Enter the number of boxes: ");
  scanf("%d", &N);

  printf("Enter the tunnel height: ");
  scanf("%d", &tunnel_height);

  for (int i = 0; i < N; i++) {
    int length, width, height;

    printf("Enter the box dimns - length, breadth and height: ");
    scanf("%d %d %d", &length, &width, &height);

    if (height < tunnel_height)
      printf("%d\n", length * width * height);
  }

  return 0;
}


