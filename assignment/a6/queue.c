#include "queue.h"
#include <stdio.h>
#include <stdlib.h> 

  /* 
   * Enqueue a node into a queue
   * @param *qp - pointer to the queue 
   * @param NODE *np - pointer to the node.
  */
  void enqueue(QUEUE *qp, NODE *np) {
    if (qp->front == NULL) {
        qp->front = np; 
        qp->rear = np; 
        qp->length++; 
        return;
    }

    else {
        qp->rear->next = np; 
        qp->rear = np; 
        qp->rear->next = NULL; 
        qp->length++; 
        return; 
    }
  }
  
  /* 
   * Dequeue and return the pointer of the removed node. 
   * @param *qp - pointer to the queue
   * @return - the reference of the removed node, and set it's next to NULL 
  */
  NODE *dequeue(QUEUE *qp) {
    if (qp->front == NULL) {
        return NULL; 
    } else if (qp->front == qp->rear) {
        NODE *temp = qp->front;
        qp->front = NULL; 
        qp->rear = NULL;
        qp->length--; 
        return temp; 
    } else {
        NODE *temp = qp->front; 
        qp->front = qp->front->next; 
        qp->length--;  
        return temp; 
    }
  }
  
  /* 
   * Clean the linked list queue
   * @param *qp - pointer to the queue
  */
  void clean_queue(QUEUE *qp){
    NODE *curr = qp->front; 
    if (qp->front == NULL) {
        return; 
    } else {
        while (curr != NULL) {
            NODE *temp = curr->next; 
            free(curr);  
            curr = temp; 
        }
    } 
    
    qp->front = NULL; 
    qp->rear = NULL; 
    qp->length = 0; 
  }