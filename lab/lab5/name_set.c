/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

/**
 * Frees all of the nodes in the set, including the header node.
 * Returns a count of the number of nodes freed, including the header node.
 *
 * @param set - pointer to an initialized name_set
 * @return number of nodes freed
 */
int name_set_free(name_set **set) {
    int counter = 1;
    name_set_node *ptr = (*set)->front;   
    while (ptr != NULL) {
        name_set_node *temp = ptr->next;  
        free(ptr); 
        counter += 1;
        ptr = temp; 
    } 
    free(*set); 
    *set = NULL; 
    return counter;  
}

/**
 * Print the contents of the linked set of names, one name per line in the format:
 * last name, first name
 * ex:
 * Brown, David
 *
 * @param set - pointer to an initialized name_set
 */
void name_set_print(const name_set *set) {
    name_set_node *ptr = set->front; 
    while (ptr != NULL) {
        printf("%s, %s\n", ptr->last_name, ptr->first_name); 
        ptr = ptr->next; 
    }
}

/**
 * Appends a name to a name_set, but only if the name is not already present in the set.
 * That is, only unique names are inserted.
 *
 * @param set - pointer to an initialized name_set
 * @param first_name - a first name string
 * @param last_name - a last name string
 * @return TRUE if the name was appended, FALSE otherwise
 */
BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name){
    name_set_node *ptr = set->front;
    if (ptr == NULL) { //adds new node to empty linked list and updates front and rear
            name_set_node *new_node = (name_set_node*) malloc(sizeof(name_set_node));
            strcpy(new_node->first_name, first_name);
            strcpy(new_node->last_name, last_name);
            set->front = new_node; 
            set->rear = new_node; 
            new_node->next = NULL; 
            return TRUE; 
    } else{
        while (ptr != NULL) { //traverses list to see if name is already there, if yes returns false 
            if (strcmp(ptr->first_name, first_name) == 0 && strcmp(ptr->last_name, last_name) == 0) {
                return FALSE;
            }
            ptr = ptr->next; 
        }
    }
    name_set_node *new_node = (name_set_node*) malloc(sizeof(name_set_node)); //if name is not there creates new node and inserts it at the end 
    strcpy(new_node->first_name, first_name);
    strcpy(new_node->last_name, last_name);
    set->rear->next = new_node; //node is attached to after rear
    set->rear = new_node; //rear is then moved to the new node
    new_node->next = NULL; //new node points to null
    return TRUE;
}

/**
 * Determines if a name is already in a name_set.
 *
 * @param set - pointer to an initialized name_set
 * @param first_name - a first name string
 * @param last_name - a last name string
 * @return TRUE if the name in set, FALSE otherwise
 */
BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name){
    
    name_set_node *ptr = set->front;

    while (ptr != NULL) {
        if (strcmp(ptr->first_name, first_name) == 0 && strcmp(ptr->last_name, last_name) == 0) {
            return TRUE; 
        }
        ptr = ptr->next;
    }
    return FALSE; 
}
