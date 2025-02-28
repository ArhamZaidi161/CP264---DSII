#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

  
  /* 
   * Push a node into a linked list stack
   * @param STACK *sp - pointer to the stack 
   * @param NODE *np - pointer to the node.
  */ 
  void push(STACK *sp, NODE *np) {
    if (sp->top == NULL) {
        sp->top = np;
        sp->length++; 
        return; 
    } else {
        np->next = sp->top;
        sp->top = np; 
        sp->length++;
        return; 
    }

  }
  
  /* 
   * Pop and return the pointer of the removed top node
   * @param STACK *sp - pointer to the stack
   * @return - the reference of the removed node and set it's next to NULL  
  */ 
  NODE *pop(STACK *sp) {
    if (sp->top == NULL) {
        return NULL; 
    } else {
        NODE *temp = sp->top; 
        sp->top = sp->top->next;
        temp->next = NULL; 
        sp->length--; 
        return temp; 
    }
  }
  
  /*
   * clean the linked list stack
   */ 
  void clean_stack(STACK *sp){
    NODE *curr = sp->top; 

    if (curr == NULL) {
        return; 
    } else {
        while (curr != NULL) {
            NODE *temp = curr->next;
            free(curr);
            curr = temp;
        }
    }

    sp->top = NULL;
    sp->length = 0; 
  }