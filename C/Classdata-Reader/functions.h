/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

//Birthday Struct
typedef struct birthdayStruct {
    char day[50];
    char year[50];
    char month[50];
} Birthday;

//Node_t Struct for Linked List
typedef struct node {
    char firstName[50], lastName[50];
    char major[50], standing[50];
    Birthday bday;
    struct node *next;
} node_t;

//---Added by LAB6---//
typedef struct stats {
    int months[12];
    node_t *oldest;
    node_t *youngest;
} list_stats_t;




/*
Function: Adds a node to the Linked List
Parameters: Takes in two inputs:
    a double pointer node to add to the list
    a double pointer head of linked list
Returns: (no return/void function)
Other functionalities:
    Also allocates (malloc) and asserts a new node
    Also checks if list is empty beforehand
*/
void add(node_t **node, node_t **head);

/*
Function: Reads and stores data from input file using scanset conversion
Parameters: Takes in one input:
    an input file pointer
Returns: a new node pointer to linked list
Other functionalities: 
    Also allocates (malloc) and asserts a new node
    Uses scanset conversion (fscanf)
*/
node_t* readNodeInfo(FILE* input);

/*
Function: Creates an entire Linked List
Parameters: Takes in two inputs:
    an input file pointer
    a double pointer head node of list
Returns: a head node pointer for Linked List
Other functionalities: N/A
*/
node_t* createList(FILE* input, node_t** head);

/*
Function: Prints the entire Linked List
Parameters: Takes in two inputs:
    an output file pointer
    a pointer head node of list
Returns: (no return/void function)
Other functionalities: 
    Uses fprintf for specified formatting
    Checks for duplicate entries in linked list
*/
void printList(FILE* output, node_t* head);

/*
Function: Prints a "border" of 80 stars for Linked List
Parameters: Takes in one input:
    an output file pointer
Returns: (no return/void function)
Other functionalities: N/A
*/
void printBorder(FILE* output);

/*
Function: Deallocates memory from Linked List
Parameters: Takes in one input:
    a double pointer head node of list
Returns: (no return/void function)
Other functionalities: N/A
*/
void deleteList(node_t** head);

//---Added by LAB5---//

//----Function pointer declaration----
typedef int (*compare_func)(node_t*, node_t*);

//----Helper functions----
/*
Function: Swaps two nodes
Parameters: Takes in two inputs:
    two pointers of node_t struct
Returns: (no return/void function)
Other functionalities: N/A
*/
void swapNodes(node_t* a, node_t* b);

/*
Function: Checks if a year is a leap year
Parameters: Takes in one input:
    an integer variable
Returns: a boolean true or false
Other functionalities: N/A
*/
bool isLeapYear(int year);

//----LAB5 Implemented functions----

/*
Function: Checks if a date is valid or not
Parameters: Takes in one input:
    a pointer of type node_t struct
Returns: a boolean true or false
Other functionalities: N/A
*/
bool checkInvalidDate(node_t* node);

/*
Function: Sorts a given Linked List
Parameters: Takes in two inputs:
    a double pointer node_t struct
    one of two function pointers of type ints
Returns: (no return/void function)
Other functionalities:
    Sorts list by either first or last name, depending on
    function pointer that is used.
*/
void sortList(node_t** head, int (*comp)(node_t*, node_t*));

/*
Function: Compares two nodes by their lastname
Parameters: Takes in two inputs:
    two pointers of type node_t struct
Returns: a positive, negative, or 0 value
Other functionalities: N/A
*/
int compare_by_lastname(node_t* a_last, node_t* b_last);

/*
Function: Compares two nodes by their firstname
Parameters: Takes in two inputs:
    two pointers of type node_t struct
Returns: a positive, negative, or 0 value
Other functionalities: N/A
*/
int compare_by_firstname(node_t* a_first, node_t* b_first);

//---Added by LAB6---//

//----Helper Functions

/*
Function: Compares two birthdays
Parameters: Takes in two inputs:
    two different variables of a birthday struct
Returns: an integer value
Other functionalities: N/A
*/
int compareBirthday(Birthday b1, Birthday b2);

//----LAB6 Implemented functions----

/*
Function: Gets and stores a list of information
Parameters: Takes in one input:
    a head node of a linked list 
Returns: a populated list_stats struct
Other functionalities: N/A
*/
list_stats_t getListStats(node_t *head);

/*
Function: Prints out a populated list_stats struct
Parameters: Takes in two inputs:
    an output file pointer
    a head populated of type list_stats struct
Returns: (no returns/void function)
Other functionalities: N/A
*/
void printStats(FILE* output, list_stats_t* head);

#endif