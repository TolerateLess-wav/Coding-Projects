/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#include "functions.h"


int main(int argc, char* argv[]) {

    char *fileInput = argv[1];
    char *fileOutput = argv[2];

    int count = argc;

    //Check for correct number of
    //Command line arguments
    assert(argc == count);

    FILE *input = NULL;
    FILE *output = NULL;

    input = fopen(fileInput, "r");
    output = fopen(fileOutput, "w");

    assert(input != NULL);
    assert(output != NULL);

    node_t *head = NULL;

    //Creates LinkedList
    createList(input, &head);

    //Creates instance of list_stats struct
    list_stats_t list_stats;

    list_stats = getListStats(head);

    /* Not needed for Lab 6
    //Initializes an option to choose between
    //Last or first name, with error check in case
    int sortOption = atoi(argv[3]);
    if (sortOption == 1) {
        sortList(&head, compare_by_firstname);
    }

    else if (sortOption == 2) {
        sortList(&head, compare_by_lastname);
    }
    else {
        printf("ERROR: incorrect sort option selected\n");
        return 1;
    }
    
    
    //Prints LinkedList
    //printList(output, head);
    */

    printStats(output, &list_stats);

    //Deallocates the LinkedList
    deleteList(&head);

    fclose(input);
    fclose(output);

    return 0;
}