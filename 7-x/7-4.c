#include <stdio.h>
#include <stdlib.h>
int* scanfmyself(int n);
int assembleInt(int a, int n);

int main() {
    int* p = NULL;
    p = scanfmyself(2);
    int result = 0;
    for(int i = 1; i <= p[1]; i++) {
        result += assembleInt(p[0], i);
    }
    printf("s = %d", result);
    free(p);
    return 0;
}

//索性写一个专门接受整型的函数吧
//p是数组，n是我要输入的整型的数字
int* scanfmyself(int n) {
    int *p = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", p+i);
    }
    return p;
}


int assembleInt(int a, int n) {
    char* p = (char*)malloc(n * sizeof(char));
    for(int i = 0; i < n; i++) {
        p[i] = '0'+a;
    }
    return atoi(p);
}