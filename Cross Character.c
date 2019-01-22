#include <stdio.h>
#include <string.h>
#define SIZE 100
int main() {
	int t;
	scanf("%i ",&t);
	while(t--){
	    char array[SIZE];
	    fgets(array, SIZE, stdin);
	    int len = strlen(array);
	    for(int i=0; i<len-1; i++){
	        for(int j=0; j<len-1; j++){
	            if(j == i || j == (len-i-2)){
	                printf("%c", array[i]);
	            }else
	                printf(" ");
	        }
	        printf("\n");
	    }
	}
	return 0;
}
