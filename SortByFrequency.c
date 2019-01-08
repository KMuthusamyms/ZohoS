#include<stdio.h>
#include<stdlib.h>

struct List{
	int num;
	int freq;
	struct List * next;
};

struct List * putInList(int elem, int frequency, struct List * head){
	struct List * newnode = (struct List *)malloc(sizeof(struct List));
	newnode->num = elem;
	newnode->freq = frequency;
	newnode->next = NULL;

	if(head == NULL){
		head = newnode;
		return head;
	}else if(frequency > head->freq){
		newnode->next = head;
		head = newnode;
		return head;
	}
	
	struct List * temp = head;
	struct List * current = NULL;

	while(temp != NULL){
		if(temp != NULL && temp->next == NULL){
			temp->next = newnode;
			return head;
		}
		current = temp;
		if(frequency == temp->freq || (temp->freq > frequency && temp->next->freq < frequency)){
			newnode->next = current->next;
			current->next = newnode;
			return head;
		}
		temp = temp->next;
	}
	return head;
}
void display(struct List * head){
	struct List * temp = head;
	while(temp != NULL){
		printf("%i->%i\n",temp->num,temp->freq);
		temp = temp->next;
	}
}
/*
struct List * putInListOne(int elem, int frequency, struct List * head){
	struct List * newnode = (struct List *)malloc(sizeof(struct List));
	newnode->num = elem;
	newnode->freq = frequency;
	newnode->next = NULL;


	if(head == NULL){
		head = newnode;
		return head;
	}else if(head != NULL && head->num > elem){
		newnode->next = head;
		head = newnode;
		return head;
	}

	struct List * temp = head;
	struct List * current = NULL;

	while(temp->next != NULL || temp->num > 1)
		temp = temp->next;

	while(temp->next != NULL){
		if(temp != NULL && temp->next == NULL){
			temp->next = newnode;
			return head;
		}

		current = temp;
		if(temp->num >= elem){
			newnode->next = current->next;
			current->next = newnode;
			return head;
		}
		temp = temp->next;
	}
	
	return head;
}
*/
void functionForSorting(int * array, int size){
	struct List * head = NULL;

	for(int i=0; i<size; i++){
		if(array[i] == -1000)
			continue;
		int count = 1;
		for(int j=i+1; j<size; j++){
			if(array[i] == array[j]){
				count++;
				array[j] = -1000;
			}
		}
		
		head = putInList(array[i], count, head);
		array[i] = -1000;
	}
	display(head);
}

int main(void){
	int t;
	scanf("%i",&t);
	while(t--){
		int size;
		scanf("%i",&size);
		int * array = (int *)malloc(sizeof(int) * size);

		int i=0;
		while(i<size)
			scanf("%i",&i++[array]);			
		
		
		functionForSorting(array, size);
		free(array);
	}
}