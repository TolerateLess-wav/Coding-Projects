/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#include "functions.h"

void add(node_t **node, node_t **head) {
    node_t *newNode = (node_t*)malloc(sizeof(node_t));

    assert(newNode != NULL);

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = NULL;
    }
    else {
        (*node)->next = newNode;
        newNode->next = NULL;
    }

    *node = newNode;

}

node_t* readNodeInfo(FILE* input) {
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    //Indented to not go over 80 character limit
    fscanf(input, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", 
        newNode->lastName, newNode->firstName, 
        newNode->bday.month, newNode->bday.day, 
        newNode->bday.year, newNode->major, 
        newNode->standing);

    //Added to check date before adding to list
    if (checkInvalidDate(newNode)) {
        free(newNode);
        return NULL;
    }

    return newNode;
}

node_t* createList(FILE* input, node_t** head) {

    node_t *temp = NULL;

    temp = *head;
    
    while (!feof(input)) {
        node_t *newNode = readNodeInfo(input);

        
        if (newNode != NULL) {
            add(&temp, head);
            *temp = *newNode;
            free(newNode);
        }
        
    }

    return *head;
}

void printList(FILE* output, node_t* head) {

    node_t *temp = head;
    node_t *temp2 = NULL;

    if (temp == NULL) {
        fprintf(stderr, "LIST IS EMPTY\n");
    }
    else {

        printBorder(output);
        fprintf(output, "List Info:\n");

        while (temp != NULL) {
            int check = 0;
            node_t *duplicateNode = temp2;

            while (duplicateNode != NULL) {
                //Indented to not go over 80 character limit
                if (strcmp(temp->firstName, duplicateNode->firstName) == 0 && 
                    strcmp(temp->lastName, duplicateNode->lastName) == 0) {
                    check = 1;
                    break;
                }
                duplicateNode = duplicateNode->next;
            }

            if(!check) {
                fprintf(output, "Name:\t%s %s\n", temp->firstName, temp->lastName);
                fprintf(output, "Date of Birth:\t%s %s, %s\n", 
                temp->bday.month, temp->bday.day, temp->bday.year);
                fprintf(output, "Major:\t%s\n", temp->major);
                fprintf(output, "Year:\t%s\n\n", temp->standing);

                node_t *newNode = (node_t*)malloc(sizeof(node_t));
                assert(newNode != NULL);
                *newNode = *temp;
                newNode->next = temp2;
                temp2 = newNode;
            }
            temp = temp->next;
        }

        printBorder(output);
    }
}

void printBorder(FILE* output)
{
    int i = 0;
    for(i = 0; i < 80; i++)
        fprintf(output,"*");
    
    fprintf(output, "\n");
}


void deleteList(node_t** head) {
    node_t *temp = NULL;
    node_t *nextNode = NULL;

    temp = *head;

    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    *head = NULL;
}


bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

bool checkInvalidDate(node_t *node) {
    int day = atoi(node->bday.day);
    int year = atoi(node->bday.year);

    if (day < 1 || day > 31) {
        return true;
    }

    if (strcmp(node->bday.month, "February") == 0) {
        if (day > 29) {
            return true;
        }
        if (day == 29 && !isLeapYear(year)) {
            return true;
        }
    } else if (strcmp(node->bday.month, "April") == 0 ||
               strcmp(node->bday.month, "June") == 0 ||
               strcmp(node->bday.month, "September") == 0 ||
               strcmp(node->bday.month, "November") == 0) {
        if (day > 30) {
            return true;
        }
    }

    return false;
}

void swapNodes(node_t *a, node_t *b) {
    char tmp[50];
    Birthday btmp;

    //Swap first name
    strcpy(tmp, a->firstName);
    strcpy(a->firstName, b->firstName);
    strcpy(b->firstName, tmp);

    //Swap last name
    strcpy(tmp, a->lastName);
    strcpy(a->lastName, b->lastName);
    strcpy(b->lastName, tmp);

    //Swap major
    strcpy(tmp, a->major);
    strcpy(a->major, b->major);
    strcpy(b->major, tmp);

    //Swap standing
    strcpy(tmp, a->standing);
    strcpy(a->standing, b->standing);
    strcpy(b->standing, tmp);

    //Swap birthday
    btmp = a->bday;
    a->bday = b->bday;
    b->bday = btmp;
}

void sortList(node_t **head, int (*comp)(node_t *, node_t *)) {
    int swapped;
    node_t *ptr1 = NULL;
    node_t *lptr = NULL;

    //Checking for empty list
    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (comp(ptr1, ptr1->next) > 0) {
                swapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int compare_by_lastname(node_t *a_last, node_t *b_last) {
    return strcmp(a_last->lastName, b_last->lastName);
}

int compare_by_firstname(node_t *a_first, node_t *b_first) {
    return strcmp(a_first->firstName, b_first->firstName);
}

//---Lab 6---//

int compareBirthday(Birthday b1, Birthday b2) {
    int year1 = atoi(b1.year), year2 = atoi(b2.year);
    int month1, month2;
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcmp(b1.month, months[i]) == 0) {
            month1 = i;
        }
        if (strcmp(b2.month, months[i]) == 0) {
            month2 = i;
        }
    }
    int day1 = atoi(b1.day), day2 = atoi(b2.day);
    if (year1 < year2) {
        return 1;
    } else if (year1 > year2) {
        return -1;
    } else {
        if (month1 < month2) {
            return 1;
        } else if (month1 > month2) {
            return -1;
        } else {
            if (day1 < day2) {
                return 1;
            } else if (day1 > day2) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

list_stats_t getListStats(node_t *head) {

    list_stats_t stats = {{0}, NULL, NULL};
    node_t *newNode = head;
    
    while (newNode != NULL) {
        // Update oldest person
        if (stats.oldest == NULL || compareBirthday(newNode->bday, stats.oldest->bday) == 1) {
            stats.oldest = newNode;
        }
        // Update youngest person
        if (stats.youngest == NULL || compareBirthday(newNode->bday, stats.youngest->bday) == -1) {
            stats.youngest = newNode;
        }
        // Update birthday counts
        char *month = newNode->bday.month;
        if (strcmp(month, "January") == 0) {
            stats.months[0]++;
        } else if (strcmp(month, "February") == 0) {
            stats.months[1]++;
        } else if (strcmp(month, "March") == 0) {
            stats.months[2]++;
        } else if (strcmp(month, "April") == 0) {
            stats.months[3]++;
        } else if (strcmp(month, "May") == 0) {
            stats.months[4]++;
        } else if (strcmp(month, "June") == 0) {
            stats.months[5]++;
        } else if (strcmp(month, "July") == 0) {
            stats.months[6]++;
        } else if (strcmp(month, "August") == 0) {
            stats.months[7]++;
        } else if (strcmp(month, "September") == 0) {
            stats.months[8]++;
        } else if (strcmp(month, "October") == 0) {
            stats.months[9]++;
        } else if (strcmp(month, "November") == 0) {
            stats.months[10]++;
        } else if (strcmp(month, "December") == 0) {
            stats.months[11]++;
        }
        newNode = newNode->next;
    }
    return stats;

}

void printStats(FILE* output, list_stats_t* head) {

    list_stats_t *temp = NULL;

    if (head == NULL) {
        fprintf(output, "None\n\n");
    }
    else {

        temp = head;

        printBorder(output);
        fprintf(output, "List Statistics:\n");
        fprintf(output, "----------Oldest Person----------\n");
        fprintf(output, "Name:\t%s %s\n", temp->oldest->firstName, temp->oldest->lastName);
        fprintf(output, "Date of Birth:\t%s %s, %s\n", temp->oldest->bday.month, 
        temp->oldest->bday.day, temp->oldest->bday.year);
        fprintf(output, "Major:\t%s\n", temp->oldest->major);
        fprintf(output, "Year:\t%s\n\n", temp->oldest->standing);

        fprintf(output, "----------Youngest Person----------\n");
        fprintf(output, "Name:\t%s %s\n", temp->youngest->firstName, temp->youngest->lastName);
        fprintf(output, "Date of Birth:\t%s %s, %s\n", temp->youngest->bday.month, 
        temp->youngest->bday.day, temp->youngest->bday.year);
        fprintf(output, "Major:\t%s\n", temp->youngest->major);
        fprintf(output, "Year:\t%s\n\n", temp->youngest->standing);

        fprintf(output, "----------Birthday Counts----------\n");
        const char *months[] = {"January", "February", "March", "April", "May", "June", "July", 
        "August", "September", "October", "November", "December"};
        for (int i = 0; i < 12; i++) {
            fprintf(output, "%s: %d\n", months[i], temp->months[i]);
        }

        printBorder(output);
    }
}