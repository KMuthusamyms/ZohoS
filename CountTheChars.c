/*
	
Given a string S. The task is to count the characters that have ‘N’ number of occurrences. If a character appears consecutively it is counted as 1 occurrence.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string S and a number N as input.

Output:
For each test case, print the count of characters in new line.

Constraints:
1<=T<=100
1<=|String length |<=104
1<=N<=103

Example:
Input:
2
abc 1
geeksforgeeks 2

Output:
3
4
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char stack[10000], str[10000];
int top = -1, t,k;
void push(char c){
    stack[++top] = c;
}
char peek(){
   return stack[top];
}
int getOccurance(char str[]){
   push(str[0]);
   for(int i=1; str[i] !='\0'; i++){
        // if peek-character from stack isn't same, push it on stack
        if(peek() != str[i])
	    push(str[i]);
    }
   int count=0;
   for(int i=0; i<top+1; i++){
	int get =1;
        // if character is already counted, marked it
	if(stack[i] == '0')
	   continue;
	bool flag = false;
      for(int j=i+1; j<top+1; j++){
	    if(stack[i] == stack[j]){
		get++;
		flag = true;
		stack[j] = '0';
	    }
      }
	if(flag)
	   stack[i] = '0';
        // if the character have K number of occurrence, increment the count 
	if(get == k)
	  count++;
     }
    return count;
}
int main(void){	
   scanf("%i",&t);
   while(t-- > 0){
	scanf("%s",str);
	scanf("%i",&k);
	printf("%i",getOccurance(str));	
	printf("\n");
   }
}

