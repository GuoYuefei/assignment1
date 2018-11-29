//
// Created by Solomon Guo on 2018/11/29.
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

//索性写一个专门接受整型的函数吧
//p是数组，n是我要输入的整型的数字
int* scanfmyself(int n) ;

//num的因子(除1与本身外)以数组形式返回   参照找素数
//p[0]是整个数组的大小
int* findFactor(int num) ;

typedef  struct {
    int temp;
    int length;
    int begin;
    int longest;
    int longestBegin;
} MLFS;

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
typedef unsigned int uint;

int main() {
    int *p1 = scanfmyself(1);
    int *p = findFactor(p1[0]);
    qsort(p+1, (uint)(p[0]-1), sizeof(int), cmp);
    MLFS mlfs = {0, 0, 0, 0, 0};
    //只要对p升序排序，然后从小到大取值，看是否能在把这些因子相乘后还是p1[0]的因子，若不能+1重新演算
    for(int i = 1; i < p[0]; i++) {
        mlfs.temp = p[i];
        mlfs.length = 1;
        mlfs.begin = i;
        for (int j = i+1; j < p[0]; ++j) {
            if(p[j] - p[j-1] == 1) {
                //相邻
                mlfs.temp *= p[j];
                if(p1[0]%mlfs.temp == 0) {
                    mlfs.length++;
                    continue;
                }
            }
            break;
        }
        if(mlfs.length > mlfs.longest) {        //记录下当前最长
            mlfs.longest = mlfs.length;
            mlfs.longestBegin = mlfs.begin;
        }
    }

    printf("%d\n", mlfs.longest==0?1:mlfs.longest);
    for (int l = 0; l < mlfs.longest-1; ++l) {
        printf("%d*", p[mlfs.longestBegin+l]);
    }
    if(mlfs.longest) {          //不是素数时
        printf("%d", p[mlfs.longestBegin + mlfs.longest - 1]);
    } else {
        printf("%d", p1[0]);
    }

//    for (int k = 0; k < p[0]; ++k) {
//        printf("%d ", p[k]);
//    }
//    printf("\n%d %d", mlfs.longestBegin, mlfs.longest);

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

//num的因子(不包括1与本身外)以数组形式返回   参照找素数
//p[0]是整个数组的大小
int* findFactor(int num) {
    int cap = 9;
    int* p = (int*)malloc(cap * sizeof(int));
//    p[1] = 1; p[2] = num;
    int size = 1; p[0] =size;
    for(int j = 2; j <= sqrt(num)+0.0001; j++) {         //+0.0001是因为double的大小难以控制
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

