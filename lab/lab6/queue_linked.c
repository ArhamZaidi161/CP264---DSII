/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {
    queue_linked *new_queue = (queue_linked*) malloc(sizeof(queue_linked)); 
    new_queue->front = NULL; 
    new_queue->rear = NULL;
    new_queue->count = 0; 

    return new_queue;
}

void queue_free(queue_linked **source) {

    free(*source); 
    *source = NULL; 
    return;
}

/**
 * Determines if a queue is empty.
 *
 * @param source - pointer to a queue
 * @return - true if source is empty, false otherwise
 */
bool queue_empty(const queue_linked *source) {

    if (source->front == NULL && source->rear == NULL) {
        return true; 
    } else {
        return false;
    }
}

int queue_count(const queue_linked *source) {

    return source->count;
}

bool queue_insert(queue_linked *source, data_ptr item) {

    queue_node *new_node = (queue_node*) malloc(sizeof(queue_node));
    new_node->item = item; 

    if (source->front == NULL) {
        source->front = new_node; 
        source->rear = new_node; 
        new_node->next = NULL; 
    } else {
        source->rear->next = new_node;
        source->rear = new_node; 
        new_node->next = NULL;
    }
    source->count++; 
    return true;
}

bool queue_peek(const queue_linked *source, data_ptr item) {

    if (source->front == NULL) {
        return false; 
    } else {
        return true; 
    }
}

bool queue_remove(queue_linked *source, data_ptr *item) {

    queue_node *ptr = source->front; 
    
    if (source->front == NULL) {
        return false; 
    } else if (source->front == source->rear) {
        free(source->front);
        source->front = NULL; 
        source->rear = NULL;
        source->count--;
        return true;
    } else {
        source->front = source->front->next; 
        free(ptr); 
        source->count--; 
        return true;
    }
    
}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while(current != NULL) {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}
