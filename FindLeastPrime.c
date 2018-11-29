/*
Find the least prime number that can be added with first array element that 
makes them divisible by second array elements at respective index 
(check for prime numbers under 1000, if exist return -1 as answer) & (Consider 1 as prime number)

Input : [ 20, 7 ]
    [ 11, 5 ]
Output : [ 2, 3 ]

Explanation : 
(20 + ?) % 11 
( 7 + ?) % 5
*/
#include<stdio.h>
#include<malloc.h>

int isPrime(int n){
	if(n == 1)
		return 1;

	for (int i = 2; i <=(n/2); ++i){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
int getPrime(int first, int second){
	int temp = 0;
	for(int i=1; i<1000; i++){		
		if(isPrime(i)){
			temp = first + i;
			if(temp % second == 0)
				return i;
		}
	}

	return -1;
}
int * get(int * fArray, int * sArray, int size){
	int * finalArray;
	finalArray = (int *)malloc(sizeof(int) * size);

	for(int i=0; i<size; i++){
		finalArray[i] = getPrime(fArray[i], sArray[i]);
	}

	return finalArray;
}
int main(int argc, char const *argv[]){
	int t;
	scanf("%i",&t);
	while(t--){
		int * fArray, *sArray;
		int * finalArray;
		int size; scanf("%i",&size);
		
		fArray = (int *)malloc(sizeof(int) * size);
		sArray = (int *)malloc(sizeof(int) * size);
		finalArray = (int *)malloc(sizeof(int) * size);

		for(int i=0; i<size; i++){
			scanf("%i",&fArray[i]);
		}

		for(int i=0; i<size; i++){
			scanf("%i", &sArray[i]);
		}

		finalArray = get(fArray, sArray, size);

		for(int i=0; i<size; i++){
			printf("%i ", finalArray[i]);
		}
		printf("\n");
		
		free(finalArray);
		free(fArray);
		free(sArray);
	}
	return 0;
}