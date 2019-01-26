/*
	Approaches:
		1. Sort Jobs, Deadlines and Profit based on profit in decreasing order.
		2. create a slot, such that each job will take 1 unit of time.
		3. initialise first job, at the last slot possible, which not exceeds deadline.
		4. fill empty slots accordingly.
		
		Reference:
		url: https://www.youtube.com/watch?v=R6Skj4bT1HE#action=share

		Example: (after sorting)
		Job 		Deadline 		Profit
		a 			2				100
		c 			2				27
		d 			1				25
		b 			1 				19
		e 			3 				15

			slot:
			1	2	3
	1->			a
	2->		c 	a
	3->     (not find slot)
	4-> 	(not find slot)
	5->		c 	a 	e

	Coder:
		SJ. 

*/
#include<stdio.h>
#include<stdlib.h>

void sortIt(int * deadlines, char * jobs, int * profits, int size){
	for(int i=1; i<size; i++){
		int j = i-1;
		
		int d = deadlines[i];
		char c = jobs[i];
		int p = profits[i];

		while(j>=0 && profits[j] <= p){
			profits[j+1] = profits[j];
			deadlines[j+1] = deadlines[j];
			jobs[j+1] = jobs[j];

			--j;
		}
		profits[j+1] = p;
		jobs[j+1] = c;
		deadlines[j+1] = d;
	}

	return;
}



void sortSlots(int * array, int size){
	for(int i=1; i<size; i++){
		int k = array[i];
		int j = i-1;
		while(j>=0 && array[j] >= k){
			array[j+1] = array[j];
			--j;
		}
		array[j+1] = k;
	}
}
void createSlots(int * deadlines, char * jobs, int * profits, int t){
	int gainProfits = profits[0];
	
	int x = deadlines[0];
	printf("%c ", jobs[0]);
	for(int i=1; i<t; i++){
		if(deadlines[i] > x){
			printf("%c ", jobs[i]);
			gainProfits += profits[i];			
		}
	}
	printf("\nmaximum profit gained: %i ", gainProfits);
}
int main(void){
	int t;
	scanf("%i",&t);

	int deadlines[t];
	int profits[t];
	char jobs[t];
	char c = 'a';
	
	for(int i=0; i<t; i++){
		printf("enter deadline and profit for job:\t%c\n",c);
		scanf("%i",&i[deadlines]);
		scanf("%i",&i[profits]);
		jobs[i] = c;
		c++;
	}

	sortIt(deadlines, jobs, profits, t);
	printf("\t\t----ENTERED DETAILS----\n");
	printf("Jobs\tDeadlines\tProfit\n");
	for(int i=0; i<t; i++){
		printf("%c\t%i\t\t%i\n", jobs[i], deadlines[i], profits[i]);
	}
		
	createSlots(deadlines, jobs, profits, t);	 
	
	// ARRENGE DEADLINES, JOBS, PROFIT ACCORDING TO SLOTS AVAILABLE

	
}