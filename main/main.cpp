#include <stdio.h>
#include "lib_name.h"
#include "queue.h"
#include "stack.h"

void main() {
  printf("\nCreate 2 queues: 1. empty, 2. queue of 10 elements:\n");
  int arr[11] = { 1, 5, 3, 8, 4, 0, 2, 6, 7, 1, 1 };
  StackList q2(arr, 11);
q2.pop();
q2.pop();
q2.push(1);
  q2.print();
  /*QueueOnList q1, q2(arr, 10);

  q1.print();
  q2.print();

  printf("\nPush 11 and -7 to queue 1:\n");
  q1.push(11);
  q1.push(-7);

  q1.print();

  printf("\nPop 3 elements from queue 2:\n");
  for (int i = 0; i < 4; i++) {
    q2.pop();
    q2.print();
  }

  printf("\nPop all elements from queue 1:\n");
  for (int i = 0; i < 3; i++) {
    q1.pop();
    q1.print();
  }*/
}
