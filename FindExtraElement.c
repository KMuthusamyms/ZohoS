/*
	Find the extra element and its index
	Input : [ 10, 20, 30, 12, 5 ]
    [ 10, 5, 30, 20 ]
	Output : 12 is the extra element in array 1 at index 4

	Input : [ -1, 0, 3, 2 ]
    	[ 3, 4, 0, -1, 2 ]
	Output : 4 is the extra element in array 2 at index 1

*/
#include<stdio.h>
#include<malloc.h>
int isContains(int elem, int * array, int size){
	for(int i=0; i<size; i++){
		if(elem == i[array])
			return 1;
	}
	return 0;
}
int getIndex(int * array, int * array1, int t, int t1){
	if(t > t1){
		for(int i=0; i<t; i++){
			if(!isContains(i[array], array1, t1)){
				printf("the uncommon element in first array at index: ");
				return i;
			}
		}
	}else{
		for(int i=0; i<t1; i++){
			if(!isContains(i[array1], array, t)){
				printf("the uncommon element in second array at index: ");
				return i;
			}
		}
	}
}
int main(int argc, char const *argv[]){
	int t, t1; 
	int *array, *array1;	

	scanf("%i",&t);
	array = (int *)malloc(sizeof(int)*t);	      
	for(int i=0; i<t; i++){
		scanf("%i",&i[array]);
	}

	scanf("%i",&t1);
	array1 = (int *)malloc(sizeof(int)*t);
	for(int i=0; i<t1; i++){
		scanf("%i", &i[array1]);
	}

	printf("%i \n", getIndex(array, array1, t, t1));
	free(array);
	free(array1);
	return 0;
}