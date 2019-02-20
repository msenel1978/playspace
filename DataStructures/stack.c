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

int is_empty_stack(const new_stack_t *stk) {
	return ((stk->cnt == 0) ? 1 : 0);
}

void push_stack(data new_data, new_stack_t *stk) {
	elem_t *p;

	p = malloc(sizeof(elem_t));
	p->d = new_data;
	p->next = stk->top;

	stk->top = p;
	stk->cnt++;
}

data pop_stack(new_stack_t *stk) {

	elem_t *top;
	data top_data;

	if (is_empty_stack(stk)) {
		printf("\nError: Stack empty!\n");
		return (0);
	}

	top = stk->top;
	top_data = top->d;

	stk->top = stk->top->next;
	stk->cnt--;
	free(top);
	
	return(top_data);
}


data top_stack(new_stack_t *stk) {

	return (stk->top->d);
}

/* TODO: Check this! */
void print_stack(new_stack_t *stk) {
	elem_t *newtop;
	int i;

	if (is_empty_stack(stk)) {
		printf("Stack empty!\n");
		return;
	}

	newtop = stk->top;

	while (!(newtop->next)) {
		printf("%d\t", newtop->d);
		newtop = newtop->next;
	}
	printf("\n");
}