#include "myrecord_sllist.h"

/* 
 * Searches for a node with the given name.
 * Traverses the list from the start until a match is found.
 */
NODE *sll_search(SLL *sllp, char *name) {
    NODE *curr = sllp->start;
    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

/* 
 * Inserts a new record into the list.
 * The insertion is done in sorted order (by name).
 */
void sll_insert(SLL *sllp, char *name, float score) {
    NODE *new_node = malloc(sizeof(NODE));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    /* Copy name safely (ensuring null-termination) */
    strncpy(new_node->data.name, name, 19);
    new_node->data.name[19] = '\0';
    new_node->data.score = score;
    new_node->next = NULL;
    
    /* Insert at beginning if list is empty or new node comes before the first node */
    if (sllp->start == NULL || strcmp(new_node->data.name, sllp->start->data.name) < 0) {
        new_node->next = sllp->start;
        sllp->start = new_node;
    } else {
        /* Otherwise, find the proper insertion point */
        NODE *curr = sllp->start;
        while (curr->next != NULL && strcmp(curr->next->data.name, new_node->data.name) < 0) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
    sllp->length++;
}

/*
 * Deletes the node with a record matching the given name.
 * Returns 1 if deletion was successful; 0 if the record was not found.
 */
int sll_delete(SLL *sllp, char *name) {
    if (sllp->start == NULL)
        return 0;
    NODE *curr = sllp->start;
    NODE *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0) {
            if (prev == NULL) {  /* Delete the head node */
                sllp->start = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            sllp->length--;
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

/*
 * Cleans the list by freeing all nodes and resetting the list structure.
 */
void sll_clean(SLL *sllp) {
    NODE *ptr = sllp->start;
    while (ptr != NULL) {
        NODE *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sllp->start = NULL;
    sllp->length = 0;
}
