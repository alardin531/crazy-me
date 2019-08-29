#include<stdio.h>
void printN(int N){
		if (N>0){
			printN(N-1);
			printf("%d\n",N);
		}
		return;
	}
int main(){
	int N;
	scanf("%d",&N);
	printN(N);
	return 0;
}
