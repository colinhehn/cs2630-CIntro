/*
 * CS:2630
 * Author: Steve Goddard
 * hawkid: sgoddard
*/

#define MAX_ARRAY_SIZE 15

/* Return the max integer of the cnt values in array */
int maxNumber(int array[],int cnt);

/* Return the min integer of the cnt values in array */
int minNumber(int array[],int cnt);

/* Return the sum of the cnt values in array */
int sum(int array[],int cnt);

/* Sort the values of array in place. The length of array is cnt.
 * Upon return, array will contain the original values sorted in
 * increasing order (i.e., smallest number first).
*/
void sortIncreasingOrder(int array[],int cnt);

/* Sort the values of array in place. The length of array is cnt.
 * Upon return, array will contain the original values sorted in
 * decreasing order (i.e., largest number first).
*/
void sortDecreasingOrder(int array[],int cnt);

/* Return the median value of the cnt integers in array.
 * If the lenght of the array is odd, then the median is the middle
 * number of the sorted values.
 * if the length of the array is even, then the median is the average
 * of the two middle values.
*/
int medianNumber(int array[],int cnt);
