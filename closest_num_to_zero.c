/**
 * Find Closest Number to Zero
 * 
 * Given an integer array nums of size n, return the number with the value closest to 0 in nums.
 * If there are multiple answers return number with the largest value. 
 */

#include <stdio.h>
#include <stdlib.h> 

int findClosestNumber(int* nums, int num_size) {
  int closest = nums[0]; // Assume first element as the closest one 

  for (int i = 1; i < num_size; i++) {

    // Compare absoulte value of the elements and handle tie cases 
    if (abs(nums[i]) < abs(closest) || (abs(nums[i]) == abs(closest) && nums[i] > closest)) {
      closest = nums[i];
      
    } 
  }

  return closest;
}

void printArr(int* arr, int size_of_arr) {
  printf("[");
  for (int i = 0; i < size_of_arr; i++) {
    printf("%d", arr[i]);

    if (i < (size_of_arr - 1)) {
      printf(", ");
    }
  }
  printf("]");
}

// Testing the function 
int main() {
  int nums1[] = {-4, -2, 1, 4, 8};
  int size1 = sizeof(nums1) / sizeof(nums1[0]);

  printf("Test case 1:\n Array: ");

  printArr(nums1, size1);
  printf("\n Closest to 0: %d\n", findClosestNumber(nums1, size1));

  int nums2[] = {2, -1, 1};
  int size2 = sizeof(nums2) / sizeof(nums2[0]);

  printf("Test case 2:\n Array: ");

  printArr(nums2, size2);
  printf("\n Closest to 0: %d\n", findClosestNumber(nums2, size2));

  return 0;
}
