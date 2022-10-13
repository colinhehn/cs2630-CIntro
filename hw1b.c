/*
 * CS:2630
 * Author: Colin Hehn
 * hawkid: chehn
*/

#include "hw1b.h"
#include <stdlib.h>
#include <stdio.h>

/* Malloc space for a Node structure and set its element field to number
 * then return a pointer to the newly created node.
*/
Node *createNode(int number) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->element = number;
    newNode->next = NULL;
    return newNode;
}

/* Free all memory allocated for node */
void destroyNode(Node *node) {
    free(node);
}

/* If list is initally NULL, return node.
 * Otherwise, add node to the end of list by setting the next field of the last 
 *   Node structure in list to node.  Then return a pointer to the list. 
*/
Node *appendList(Node *list, Node *node) {
    if(list == NULL) return node; // In case of an empty list
    else {
        Node* point = list;
        while (point->next != NULL) {
            point = point->next;
        }
        point->next = node;
    }
    return list;
}

/* Build and return a linked list such that each integer in array is
 * stored in the element field of a newly created node of the linked list.
*/
Node *createList(int array[], int cnt) {
    Node* list = NULL;
    for (int i = 0; i < cnt; i++) {
        Node* newNode = createNode(array[i]);
        list = appendList(list, newNode);
    }
    return list;
}

/* Free all memory allocated for the nodes in list */
void destroyList(Node *list) {
    while (list != NULL) {
        Node* temp = list->next;
        destroyNode(list);
        list = temp;
    }
}

/* Return the length of list */
int listLength(Node *list) {
    if (list == NULL) return -1; // In case of an empty list
    int count = 0;
    Node* point = list;
    while (point != NULL) {
        count++; // +1 for each Node
        point = point->next;   
    }
    return count;
} 

/* Return the max of the element values in list */
int maxElement(Node *list) {
    if (list == NULL) return -1; // In case of an empty list
    int max = list->element;
    Node* point = list;
    while (point != NULL) {
        if (point->element > max) max = point->element; // If the current Node's element is greater than the current max, set max to that element
        point = point->next;   
    }
    return max;
}

/* Return the min of the element values in list */
int minElement(Node *list) {
    int min = list->element;
    Node* point = list;
    while (point != NULL) {
        if (point->element < min) min = point->element; // If the current Node's element is less than the current min, set min to that element
        point = point->next;   
    }
    return min;
}

/* Return the sum of the element values in list */
int sumElements(Node *list) {
    int sum = 0;
    Node* point = list;
    while (point != NULL) {
        sum += point->element; // Add the current Node's element to the sum
        point = point->next;   
    }
    return sum;
}

/* Return a list wherein the values of list are in increasing order. */
Node *sortListIncreasingOrder(Node *list) {
    if (list == NULL) return NULL; // In case of an empty list
    /* Implementation of Selection Sort, but on a Linked List! */
       Node* point = list;
       Node* swapPoint;
       int temp;
        while (point != NULL && point->next != NULL) {
            swapPoint = point;
            while (swapPoint != NULL) {
                if (point->element > swapPoint->element) {
                    temp = point->element; // Next 3 lines swap the elements of the two Nodes
                    point->element = swapPoint->element;
                    swapPoint->element = temp;
                }
                swapPoint = swapPoint->next;
            }
            point = point->next;
         }
    return list;
}

/* Return a list wherein the values of list are in decreasing order. */
Node *sortListDecreasingOrder(Node *list) {
    if (list == NULL) return NULL; // In case of an empty list
    /* Implementation of Selection Sort, but on a Linked List! */
       Node* point = list;
       Node* swapPoint;
       int temp;
        while (point != NULL && point->next != NULL) {
            swapPoint = point;
            while (swapPoint != NULL) {
                if (point->element < swapPoint->element) {
                    temp = point->element; // Next 3 lines swap the elements of the two Nodes
                    point->element = swapPoint->element;
                    swapPoint->element = temp;
                }
                swapPoint = swapPoint->next;
            }
            point = point->next;
         }
    return list;
}

/* Return the median value of the elements in list.
 * If the lenght of the list is odd, then the median is the middle
 * element of the sorted list.
 * if the length of the list is even, then the median is the average
 * of the two middle values.
*/
int medianElement(Node *list) {
    if (list == NULL) return -1; // In case of an empty list
    sortListIncreasingOrder(list);
    int cnt = listLength(list);
    if (cnt % 2 == 0) { // If the length of the list is even, return the average of the two middle values
        return (traverseTo(list, (cnt/2) - 1)->element + traverseTo(list, cnt/2)->element) / 2;
    } else { // If the length of the list is odd, return the middle value
        return traverseTo(list, (cnt/2))->element;
    }
}

/* Traverse a pointer to a specific index in the linked list
 * (Helper Function for medianElement)
*/
Node *traverseTo(Node *list, int index) {
    Node* point = list;
    for (int i = 0; i < index; i++) {
        point = point->next;
    }
    return point;
}