#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

/* 
 * Creates and returns a new node with the given data value.
 */
NODE *dll_node(char value) {
    NODE *node = malloc(sizeof(NODE));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/*
 * Inserts a given node at the beginning of the doubly linked list.
 * If the list is empty, sets both start and end to the new node.
 * Otherwise, adjusts pointers so that the new node becomes the start.
 */
void dll_insert_start(DLL *dllp, NODE *np) {
    if (dllp->start == NULL) {
        dllp->start = np;
        dllp->end = np;
    } else {
        np->next = dllp->start;
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
}

/*
 * Inserts a given node at the end of the doubly linked list.
 * If the list is empty, sets both start and end to the new node.
 * Otherwise, adjusts pointers so that the new node becomes the end.
 */
void dll_insert_end(DLL *dllp, NODE *np) {
    if (dllp->end == NULL) {
        dllp->start = np;
        dllp->end = np;
    } else {
        np->prev = dllp->end;
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
}

/*
 * Deletes the first node of the doubly linked list.
 * Frees the node and adjusts pointers.
 */
void dll_delete_start(DLL *dllp) {
    if (dllp->start == NULL)
        return;
    
    NODE *temp = dllp->start;
    if (dllp->start == dllp->end) {  // Only one node in the list
        dllp->start = NULL;
        dllp->end = NULL;
    } else {
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }
    free(temp);
    dllp->length--;
}

/*
 * Deletes the last node of the doubly linked list.
 * Frees the node and adjusts pointers.
 */
void dll_delete_end(DLL *dllp) {
    if (dllp->end == NULL)
        return;
    
    NODE *temp = dllp->end;
    if (dllp->start == dllp->end) {  // Only one node in the list
        dllp->start = NULL;
        dllp->end = NULL;
    } else {
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }
    free(temp);
    dllp->length--;
}

/*
 * Cleans the doubly linked list by freeing all nodes.
 * Resets the start, end, and length fields.
 */
void dll_clean(DLL *dllp) {
    NODE *curr = dllp->start;
    while (curr != NULL) {
        NODE *temp = curr;
        curr = curr->next;
        free(temp);
    }
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length = 0;
}
