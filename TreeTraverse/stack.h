//
//  stack.h
//  Stack
//
//  Created by Murat Senel on 11/26/13.
//  Copyright (c) 2013 Murat Senel. All rights reserved.
//

#ifndef stack_h
#define stack_h
typedef char data;
typedef enum {false, true} boolean;

struct elem {
    data    d;
    struct elem *next;
};

typedef struct elem elem_t;

struct stack {
    int cnt;
    elem_t *top;
};

typedef struct stack stack_t;

int init_stack(stack_t *stk);
stack_t *push(stact_t *node, data new_data);
stack_t *pop(stack_t stk, data *new_data);
void print_stack(stack_t *head);
int empty_stack(stack_t *stk);

#endif
