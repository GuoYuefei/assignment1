#include <stdio.h>

void printdigits( int n );



int main()
{
    static int p[3][3];
    printf("%d", p[1][1]);
    int n;
    scanf("%d", &n);
    printdigits(n);

    return 0;
}

void printdigits(int n) {
    if(!n) printf("0");
    int temp = n;
    int temp1;
    int p[20] = {1};
    while(temp) {
        temp1 = temp % 10;
        temp /= 10;
        p[p[0]++] = temp1;
    }
    for(int i = p[0]-1; i > 0; i--){
        printf("%d\n", p[i]);    
    }
}
