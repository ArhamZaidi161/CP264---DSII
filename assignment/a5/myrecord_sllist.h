#ifndef MYRECORD_SLLIST_H
#define MYRECORD_SLLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* RECORD structure: holds a person's name and score. */
typedef struct {
    char name[20];
    float score;
} RECORD;

/* NODE structure: singly linked node holding a RECORD. */
typedef struct node {
    RECORD data;
    struct node *next;
} NODE;

/* Singly linked list structure: holds the number of nodes and a pointer to the first node. */
typedef struct sllist {
    int length;
    NODE *start;
} SLL;

/*
 * Searches the singly linked list for a record with the given name.
 * Returns pointer to the found node, or NULL if not found.
 */
NODE *sll_search(SLL *sllp, char *name);

/*
 * Inserts a new record into the singly linked list in sorted order (by name).
 */
void sll_insert(SLL *sllp, char *name, float score);

/*
 * Deletes the node whose record matches the given name.
 * Returns 1 if a node was deleted; 0 otherwise.
 */
int sll_delete(SLL *sllp, char *name);

/*
 * Cleans the singly linked list by deleting all nodes.
 */
void sll_clean(SLL *sllp);

#endif
