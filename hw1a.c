/*
 * CS:2630
 * Author: Colin Hehn
 * hawkid: chehn
*/

/* Return the max integer of the cnt values in array */
int maxNumber(int array[],int cnt) {
    int max = array[0];
    for (int i = 0; i <= cnt-1; i++){
        if (array[i] > max) max = array[i];
    }
    return max;
}

/* Return the min integer of the cnt values in array */
int minNumber(int array[],int cnt) {
    int min = array[0];
    for (int i = 0; i <= cnt-1; i++){
        if (array[i] < min) min = array[i];
    }
    return min;
}

/* Return the sum of the cnt values in array */
int sum(int array[],int cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
        sum += array[i];
    }
    return sum;
}

/* Sort the values of array in place. The length of array is cnt.
 * Upon return, array will contain the original values sorted in
 * increasing order (i.e., smallest number first). */
void sortIncreasingOrder(int array[],int cnt) {
    // Implementation of Selection Sort
    for (int i = 0; i < cnt; i++) {
        for (int j = i; j < cnt; j++) {
            if (array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/* Sort the values of array in place. The length of array is cnt.
 * Upon return, array will contain the original values sorted in
 * decreasing order (i.e., largest number first).
*/
void sortDecreasingOrder(int array[],int cnt) {
    // Implementation of Selection Sort
    for (int i = 0; i < cnt; i++) {
        for (int j = i; j < cnt; j++) {
            if (array[j] > array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/* Return the median value of the cnt integers in array.
 * If the length of the array is odd, then the median is the middle
 * number of the sorted values.
 * if the length of the array is even, then the median is the average
 * of the two middle values.
*/
int medianNumber(int array[],int cnt) {
    sortIncreasingOrder(array, cnt);
    if (cnt % 2 != 0) {
        return array[(cnt / 2) + 1];
    }
    else {
        return (array[cnt / 2] + array[(cnt / 2) + 1]) / 2;
    }
}