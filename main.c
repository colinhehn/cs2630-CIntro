/*
 * CS:2630
 * Author: Steve Goddard
 * hawkid: sgoddard
*/

#include <stdio.h>
#include "hw1a.h"
#include "hw1b.h"

/* Print the first cnt ints in array[], followed by a newline */
void printArray(int array[], int cnt) {
  int i;
  for (i = 0; i < cnt; i++) {
    printf("%d ", array[i]);
  }
    printf("\n");
}

/* Print the ints stored in the nodes of a linked list, followed 
 * by a newline.  If the list is empty, NULL is printed. Otherwise,
 * prints each int, followed by a newline at the end.
*/
void printList(Node *list) {
  if (list == NULL) {
    printf("NULL"); // indicate empty list
  } else {
    /* loop through the list, printing each element */
    while (list != NULL) {
      printf("%d ",list->element);
      list = list->next;
    }
  }
  printf("\n"); // add a newline to finish off
}

/* Call functions delivered in HW1a 
 * and print the results to stdout.
 * This method has a compiler ifdef directive
 * that includes the code based on flags
 * set in the Makefile. When the flag is
 * not set, the function just returns without
 * doing anything.
*/
void hw1aTestDriver(int array[], int cnt) {
#ifdef HW1A
  printf("\n****** HW1a ******\n");
  printf("Array in order read: ");
  printArray(array,cnt);

  printf("\nMax number in array[] is %d\n", maxNumber(array,cnt));
  printf("Min number in array[] is %d\n", minNumber(array,cnt));
  printf("Sum of numbers in array[] is %d\n", sum(array,cnt));
  printf("Median of numbers in array[] is %d\n", medianNumber(array,cnt));
  
  sortIncreasingOrder(array,cnt);
  printf("\nIncreasing order: ");
  printArray(array,cnt);
  sortDecreasingOrder(array,cnt);
  printf("Decreasing order: ");
  printArray(array,cnt);
#endif 
}

/* Call functions delivered in HW1b 
 * and print the results to stdout.
 * This method has a compiler ifdef directive
 * that includes the code based on flags
 * set in the Makefile. When the flag is
 * not set, the function just returns without
 * doing anything.
*/
void hw1bTestDriver(int array[], int cnt) {
#ifdef HW1B
  int length;
  int result;

  Node *list = createList(array, cnt);
  printf("\n****** HW1b ******\n");
  printf("List created from elements read: ");
  printList(list);

  result = maxElement(list);
  printf("\nMax number in linked list is %d\n", result);
  result = minElement(list);
  printf("Min number in linked list is %d\n", result);
  result = sumElements(list);
  printf("Sum of numbers in linked list is %d\n", result);
  result = medianElement(list);
  printf("Median of numbers in linked list is %d\n", result);
  
  list = sortListIncreasingOrder(list);
  length = listLength(list);
  printf("\nIncreasing order of %d elements: ",length);
  printList(list);
  list = sortListDecreasingOrder(list);
  length = listLength(list);
  printf("Decreasing order of %d elements: ",length);
  printList(list);
  printf("\n");
  destroyList(list);
#endif 
}

int main () {
  int number;
  int numbersRead = 0;
  int numbers[MAX_ARRAY_SIZE];
  int copy[MAX_ARRAY_SIZE];
  
  /* Read in a set of numbers and store them for HW1a and HW1b tests */
  printf("Enter up to %d numbers; terminate input with <ctrl-d>:",
     MAX_ARRAY_SIZE);
  while (scanf("%d", &number) != EOF && numbersRead < MAX_ARRAY_SIZE) {
    numbers[numbersRead] = number; // store the numbers for HW1a
    copy[numbersRead] = number; // create a copy for HW1b
    numbersRead++;
  }

  /* Test HW1a delivered functions */
  hw1aTestDriver(numbers, numbersRead);

  /* Test HW1b delivered functions.
   * Need to use the copy of the initial array
   * because the sorts in HW1a will change the
   * inital ordering, and want the same initial
   * condition for HW1b whether main is built
   * with just HW1b or with HW1a and HW1b options.
  */
  hw1bTestDriver(copy, numbersRead);
}
