#ifndef DLL_H
#define DLL_H

/* NODE structure for a doubly linked list holding a char data value */
typedef struct node {
    char data;
    struct node *prev;  
    struct node *next;
} NODE;

/* Doubly linked list structure holding the length and pointers to the start and end nodes */
typedef struct dllist {
    int length;
    NODE *start;
    NODE *end;
} DLL;

/* 
 * Creates and returns a new node (allocated with malloc) with the given char value.
 */
NODE *dll_node(char value);

/* 
 * Inserts a given node at the beginning of the doubly linked list.
 */
void dll_insert_start(DLL *dllp, NODE *np);

/* 
 * Inserts a given node at the end of the doubly linked list.
 */
void dll_insert_end(DLL *dllp, NODE *np);

/* 
 * Deletes the first node of the doubly linked list.
 */
void dll_delete_start(DLL *dllp);

/* 
 * Deletes the last node of the doubly linked list.
 */
void dll_delete_end(DLL *dllp);

/* 
 * Cleans (frees) all nodes of the doubly linked list and resets its fields.
 */
void dll_clean(DLL *dllp);

#endif
