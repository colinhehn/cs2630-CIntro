/*
 * CS:2630
 * Author: Steve Goddard
 * hawkid: sgoddard
*/

/* Structure and type defintion for a node in a singly linked list.
*/
typedef struct node
{	int element;
	struct node *next;
} Node;

/* Malloc space for a Node structure and set its element field to number
 * then return a pointer to the newly created node.
*/
Node *createNode(int number);

/* Free all memory allocated for node */
void destroyNode(Node *node);

/* If list is initally NULL, return node.
 * Otherwise, add node to the end of list by setting the next field of the last 
 *   Node structure in list to node.  Then return a pointer to the list. 
*/
Node *appendList(Node *list, Node *node);

/* Build and return a linked list such that each integer in array is
 * stored in the element field of a newly created node of the linked list.
*/
Node *createList(int array[], int cnt);

/* Free all memory allocated for the nodes in list */
void destroyList(Node *list);

/* Return the length of list */
int listLength(Node *list); 

/* Return the max of the element values in list */
int maxElement(Node *list);

/* Return the min of the element values in list */
int minElement(Node *list);

/* Return the sum of the element values in list */
int sumElements(Node *list);

/* Return a list wherein the values of list are in increasing order. */
Node *sortListIncreasingOrder(Node *list);

/* Return a list wherein the values of list are in decreasing order. */
Node *sortListDecreasingOrder(Node *list);

/* Return the median value of the elements in list.
 * If the lenght of the list is odd, then the median is the middle
 * element of the sorted list.
 * if the length of the list is even, then the median is the average
 * of the two middle values.
*/
int medianElement(Node *list);

/* Traverse a pointer to a specific index in the linked list
 * (Helper Function for medianElement)
*/
Node *traverseTo(Node *list, int index);
