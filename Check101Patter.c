/*
	approach:
	1. initialise stack and put first one in it.
	2. if i-th char is not => 0, 1
		2.1 remove elements until you got '0' (i.e, remove a complete pattern)
	3. if i-th char is '1' and top of stack is '1'
		3.1 increment count and push '1' in stack
	4. if i-th char is '0' and top of stack is '1'
		4.1 push '0' on stack
	5. if i-th char is '1' and top of stack is also '1'
		ignore.
	6. continue till end of char array.

	That's it. :)

	url: https://www.geeksforgeeks.org/count-of-occurrences-of-a-101-pattern-in-a-string/

*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 1000

struct Stack
{
	char data;
	struct Stack * next;
};

struct Stack * push(char elem, struct Stack * head)
{
	struct Stack * newelement = (struct Stack *)malloc(sizeof(struct Stack));
	newelement->data = elem;
	newelement->next = NULL;

	if(head == NULL)
		head = newelement;
	else{
		newelement->next = head;
		head = newelement;
	}
	return head;
}

bool stackIsEmpty(struct Stack * head)
{
	return (head == NULL);
}

struct Stack * pop(struct Stack * head)
{
	head = head->next;
	return head;
}

char peek(struct Stack * head)
{
	return head->data;
}

int function(const char * array)
{
	struct Stack * head = NULL;
	int count = 0;

	for(int i=0; array[i] != '\0'; i++)
	{
		if((i == 0 && array[i] == '1') || (array[i] == '1' && head == NULL))
		{
			head = push(array[i], head);
			continue;
		}		

		if(!stackIsEmpty(head)){
			if((array[i] != '0' && array[i] != '1'))
			{
				while(peek(head) != '1')
				{
					head = pop(head);
				}
				head = pop(head);
			}
			if(array[i] == '1' && peek(head) == '0')
			{												
				count++;
				head = push(array[i], head);
			}

			if(array[i] == '0' && peek(head) == '1')
			{				
				head = push(array[i], head);				
			}

			if(array[i] == '1' && peek(head) == '1')
			{
				continue;
			}
		}	
	}	
	

	return count;

}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%i ",&t);
	
	while(t--)
	{
		char array[MAX_SIZE];
		fgets(array, MAX_SIZE, stdin);
		printf("count of pattern [ 1[0+]1 ]: %i\n",function(array));
	}
	return 0;
}