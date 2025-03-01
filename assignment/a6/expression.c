#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"
#include <ctype.h>


/* 
 * Convert infix expression string to postfix expression reprsented by queue data structure. 
 * @param infixstr - string of infix expression. 
 * @return - postfix expression in queue of QUEUE type. 
*/
QUEUE infix_to_postfix(char *infixstr) {
    QUEUE PE = {0};  // Postfix expression queue
    STACK S = {0};   // Operator stack

    for (int i = 0; infixstr[i] != '\0'; i++) {
        char token = infixstr[i];

        if (mytype(token) == 5) {  // Skip spaces
            continue;
        }

        int type = mytype(token);

        if (type == 0) {  
            // Handle multi-digit numbers
            int num = 0;
            while (isdigit(infixstr[i])) {
                num = num * 10 + (infixstr[i] - '0');
                i++;
            }
            i--;  // Adjust 'i' since the for-loop will increment it
            enqueue(&PE, new_node(num, 0));  // Enqueue the complete number
        } 
        else if (type == 1) {  
            // Operator: pop operators from S with higher or equal precedence
            while (S.top && priority(S.top->data) >= priority(token)) {
                enqueue(&PE, pop(&S));
            }
            push(&S, new_node(token, 1));
        } 
        else if (type == 2) {  
            // Left parenthesis '(' → push onto stack
            push(&S, new_node(token, 2));
        } 
        else if (type == 3) {  
            // Right parenthesis ')' → pop from stack until '(' is encountered
            while (S.top && S.top->data != '(') {
                enqueue(&PE, pop(&S));
            }
            pop(&S);  // Remove the '(' from the stack (do not enqueue)
        } 
        else if (type == 4) {  
            // Variables (letters) – ignore if not needed
            continue;
        }
    }

    // Pop any remaining operators from the stack into the queue
    while (S.top) {
        enqueue(&PE, pop(&S));
    }

    return PE;
}

int evaluate_postfix(QUEUE queue) {
    STACK S = {0};  // Stack for evaluation
    NODE *temp;

    while ((temp = dequeue(&queue)) != NULL) {
        if (temp->type == 0) {  
            // Operand: push onto evaluation stack
            push(&S, new_node(temp->data, 0));
        } 
        else if (temp->type == 1) {  
            // Operator: pop two operands and perform the operation
            NODE *b = pop(&S);
            NODE *a = pop(&S);
            if (!a || !b) {
                printf("Error: Stack underflow\n");
                exit(1);
            }
            int result;
            switch (temp->data) {
                case '+': result = a->data + b->data; break;
                case '-': result = a->data - b->data; break;
                case '*': result = a->data * b->data; break;
                case '/': 
                    if (b->data == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = a->data / b->data; 
                    break;
                default: result = 0; break;
            }
            push(&S, new_node(result, 0));
            free(a);
            free(b);
        }
        free(temp);
    }

    // Final result is at the top of the evaluation stack
    NODE *final_result = pop(&S);
    int result = final_result->data;
    free(final_result);
    return result;
}

int evaluate_infix(char *infixstr) {
    QUEUE postfix_q = infix_to_postfix(infixstr);
    return evaluate_postfix(postfix_q);
}
