#include <stdio.h>

void PrintN ( int N ){
	int i;
	for(i=1;i<=N;i++){
		printf("%d\n",i);
	}
}

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN(printN(N)); 

    return 0;
}
