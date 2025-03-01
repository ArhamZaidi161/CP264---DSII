#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"


/* 
 * Convert infix expression string to postfix expression reprsented by queue data structure. 
 * @param infixstr - string of infix expression. 
 * @return - postfix expression in queue of QUEUE type. 
*/
QUEUE infix_to_postfix(char *infixstr){
    QUEUE PE = {0};  // Postfix expression queue
    STACK S = {0};   // Operator stack

    for (int i = 0; infixstr[i] != '\0'; i++) {
        char token = infixstr[i];

        if (mytype(token) == 5) {  // Skip spaces
            continue;
        }

        int type = mytype(token);

        if (type == 0) {  
            enqueue(&PE, new_node(token - '0', 0));
        } 
        else if (type == 1) {  
            while (S.top && priority(S.top->data) >= priority(token)) {
                enqueue(&PE, pop(&S));
            }
            push(&S, new_node(token, 1));
        } 
        else if (type == 2) {  
            push(&S, new_node(token, 2));
        } 
        else if (type == 3) {  
            while (S.top && S.top->data != '(') {
                enqueue(&PE, pop(&S));
            }
            pop(&S);  // Remove '(' but don't enqueue it
        } 
        else if (type == 4) {  
            continue; // Ignore variables if not needed
        }
    }

    // Pop remaining operators into queue
    while (S.top) {
        enqueue(&PE, pop(&S));
    }

    return PE;
}

/* 
 * Evaluate and return the value postfix expression passed by queue.
 * @parame queue - postfix expression in queue of QUEUE type.
 ^ @return - value of postfix expression
*/
int evaluate_postfix(QUEUE queue) {
    STACK S = {0};  // Stack for evaluation
    NODE *temp;

    while ((temp = dequeue(&queue)) != NULL) {
        if (temp->type == 0) {  
            // Operand → Push onto stack
            push(&S, temp);
        } 
        else if (temp->type == 1) {  
            // Operator → Pop two operands, perform operation
            NODE *b = pop(&S);
            NODE *a = pop(&S);

            int result;
            switch (temp->data) {
                case '+': result = a->data + b->data; break;
                case '-': result = a->data - b->data; break;
                case '*': result = a->data * b->data; break;
                case '/': result = a->data / b->data; break;
            }

            push(&S, new_node(result, 0));

            free(a);
            free(b);
        }
        free(temp);
    }

    // Final result is at top of stack
    NODE *final_result = pop(&S);
    int result = final_result->data;
    free(final_result);
    
    return result;
}

/* 
 * Evaluate and return the value of infix expression passed by string infixstr, 
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.  
 * @return - value of the infix expression.
*/
int evaluate_infix(char *infixstr) {
    QUEUE postfix_q = infix_to_postfix(infixstr);
    return evaluate_postfix(postfix_q);
}
