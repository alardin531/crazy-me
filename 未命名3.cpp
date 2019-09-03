#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Average( ElementType S[], int N ){
	double sum=0;
	int i;
	for(i=0;i<N;i++){
		sum+=S[i];
	} 
	double ave=sum/N;
	return ave;
} 

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));

    return 0;
}

