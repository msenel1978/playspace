//
//  stack.c
//  Stack
//
//  Created by Murat Senel on 11/26/13.
//  Copyright (c) 2013 Murat Senel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(new_stack_t *stk) {
	stk->cnt = 0;
	stk->top = NULL;
}

void push_stack(data new_data, new_stack_t *stk) {
	elem_t *p;

	p = malloc(sizeof(elem_t));
	p->d = new_data;
	p->next = stk->top;

	stk->top = p;
	stk->cnt++;
}

/* TODO: Check this! */
data pop_stack(new_stack_t *stk) {

	elem_t *top = stk->top;
	data top_data = top->d;

	stk->top = stk->top->next;
	stk->cnt--;
	free(top);
	
	return(top_data);
}

/* TODO: Check this! */
data top_stack(new_stack_t *stk) {

	return (stk->top->d);
}

/* TODO: Check this! */
void print_stack(new_stack_t *stk) {

	while (stk->top->next != NULL) {
		printf("%c\t",stk->top->d);
		stk->top = stk->top->next;
	}
}