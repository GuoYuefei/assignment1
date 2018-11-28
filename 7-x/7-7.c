//
// Created by Administrator on 2018/11/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* scanfmyself(int n);
int* findFactor(int num);
int cmp1(const void *, const void *);

int main() {
    int* p = scanfmyself(2);
    int begin = p[0], end = p[1];
    free(p);
    int flag = 1;
    for(int num = begin; num <= end; num++) {
        p = findFactor(num);
        int rst = 1;
        for(int i = 1; i < p[0]; i++) {
            rst += p[i];
        }
        if(rst == num) {
            if(!flag) printf("\n");
            flag = 0;       //证明该区间有完数
            qsort(p+1, (unsigned int)(p[0]-1), sizeof(int), cmp1);
            printf("%d = 1", num);

            for(int i = 1; i < p[0]; i++) {
                printf(" + %d", p[i]);
            }
        }
        free(p);
    }

    if(flag) {
        printf("None");
    }

    return 0;
}

//num的因子(除1与本身外)以数组形式返回   参照找素数
int* findFactor(int num) {
    int cap = 7;
    int* p = (int*)malloc(cap * sizeof(int)); int size = 1; p[0] = size;
    for(int j = 2; j <= sqrt(num)+0.001; j++) {         //+0.001是因为double的大小难以控制
        if(num%j==0) {
            if(size+2 > cap) {
                cap *= 2;
                p = (int*)realloc(p, cap * sizeof(int));
            }
            p[size++] = j; p[0] = size;
            if(j != num/j) {
                p[size++] = num/j; p[0] = size;
            }
        }
    }
    p = (int*)realloc(p, p[0] * sizeof(int));
    return p;
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

//升序 从小到大
int cmp1(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}