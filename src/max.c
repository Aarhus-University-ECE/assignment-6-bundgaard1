#include <assert.h>
#include <stdio.h>

int max(int* numbers, int size) {
  assert(size > 0);  // precondition
  int maxValue = numbers[0];
  for (int i = 1; i < size; i++) {
    // If the current value is greater than maxValue
    if (maxValue < numbers[i]) {
      // Update maxvalue
      maxValue = numbers[i];
    }
  }
  return maxValue;
}
