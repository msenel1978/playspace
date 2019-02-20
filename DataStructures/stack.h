//
//  stack.h
//  Stack
//
//  Created by Murat Senel on 11/26/13.
//  Copyright (c) 2013 Murat Senel. All rights reserved.
//

#ifndef stack_h
#define stack_h
//typedef char data;
typedef int data;
typedef enum {false, true} boolean;

struct elem {
    data    d;
    struct elem *next;
};

typedef struct elem elem_t;

struct stack {
    int cnt;		/* num of elements */
    elem_t *top;	/* ptr to the top element */
};

typedef struct stack new_stack_t;

void init_stack(new_stack_t *stk);
void push_stack(data new_data, new_stack_t *stk);
data pop_stack(new_stack_t *stk);
data top_stack(new_stack_t *stk);
void print_stack(new_stack_t *stk);
int is_empty_stack(const new_stack_t *stk);
int full_stack(const new_stack_t *stk);
#endif
