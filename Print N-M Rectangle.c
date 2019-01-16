/*
	Given two dimensional matrix of integer and print the rectangle can be formed using
	given indices and also find the sum of the elements in the rectangle
	Input: mat[M][N] = {{1, 2, 3, 4, 6}, {5, 3, 8, 1, 2}, {4, 6, 7, 5, 5}, {2, 4, 8, 9, 4} };
	index = (2, 0) and (3, 4)
	Output:
	Rectangle
	4 6 7 5 5
	2 4 8 9 4
	sum 54
*/
#include<stdio.h>
#include<stdlib.h>
#define M 4
#define N 5

int print(int array[][N], int x, int y, int x1, int y1){
	int sum =0;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if((i>=x && j>=y) && (i<=x1 && j<=y1)){
				sum += array[i][j];
				printf("%i ", array[i][j]);
			}
		}
		printf("\n");
	}
	return sum;
}
int main(void){

	int array[M][N] = {{1, 2, 3, 4, 6}, {5, 3, 8, 1, 2}, {4, 6, 7, 5, 5}, {2, 4, 8, 9, 4} };
	
	int x, y;
	scanf("%i",&x);
	scanf("%i",&y);

	int x1, y1;
	scanf("%i",&x1);
	scanf("%i",&y1);

	printf("sum: %i",print(array, x, y, x1, y1));

}