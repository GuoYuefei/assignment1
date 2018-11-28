//
// Created by Administrator on 2018/11/28.
//


//不是最快的，为了以后应付作业，尽量写成可以复用的函数
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* scanfmyself(int);
int* splitInt(int num);
int powInt(int num, int n);
int composeInt(const int *p);
int cmp1(const void* a, const void* b);
int cmp2(const void* a, const void* b);
//只需演算三位黑洞数的过程
int main() {
    int* p = scanfmyself(1);
    int* pp = splitInt(p[0]); free(p);
    int max,min,rst = 1, n = 0; //n为次数


    while(rst != 495&&rst != 0) {
        n++;
        qsort(pp+1, pp[0] - 1, sizeof(int), cmp1);
        max = composeInt(pp);
        qsort(pp+1, pp[0] - 1, sizeof(int), cmp2);
        min = composeInt(pp);
        rst = max - min;
        printf("%d: %d - %d = %d\n", n, max, min, rst);
        free(pp); pp = splitInt(rst);
    }

//    qsort(pp+1, pp[0] - 1, sizeof(int), cmp1);
//    for(int i = 0; i < pp[0]; i++) {
//        printf("%d ", pp[i]);
//    }
//    max = composeInt(pp);
//    printf("\nmax = %d", max);

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

//拆分int类型，自动判定num的位数，并以int*类型返回
//个位在p[1]
int* splitInt(int num) {
    int cap = 7;        //容器大小刚刚开始为7，用p[0]记录
    int temp = num,temp1;
    int* p = (int*)malloc(cap * sizeof(int)); int size = 1; p[0] = size;     //p[0]用于装size
    while(temp) {
        if(size >= cap) {
            cap *= 2;
            p = (int*)realloc(p, cap * sizeof(int));
        }
        temp1 = temp % 10;
        temp /= 10;
        p[size++] = temp1;
        p[0] = size;
    }
    p = (int*)realloc(p, size * sizeof(int));
    return p;
}

int powInt(int num, int n) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= num;
    }
    return result;
}


//根据p重组成一个int   p内容格式得符合splitInt返回p的那种格式 p[0] == 个数
//地址高位的是整型高位，也就是P[1]是个位
int composeInt(const int *p) {
    int result = 0;
    for(int i = 1; i < p[0]; i++) {
        result += p[i]*powInt(10,i - 1);
    }
    return result;
}



//升序 从小到大
int cmp1(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

//降序 从大到小
int cmp2(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}
