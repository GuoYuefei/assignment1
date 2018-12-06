#include <stdio.h>
#define MAXN 10

int ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */

//算上begin，不算end
//n[begin] ->n[end-1]
void inversion(int* n,int begin,int end){
	for(int i=begin;i<(end+begin)/2;i++){
		int temp = n[i];
		n[i] = n[begin+end-i-1];
		n[begin+end-i-1] = temp;
	}
}

int ArrayShift( int a[], int n, int m ) {
    m = m % n;
    inversion(a, 0, n);
    inversion(a, 0, m);
    inversion(a, m, n);
    return 0;
}

