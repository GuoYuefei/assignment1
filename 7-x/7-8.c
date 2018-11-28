//
// Created by Administrator on 2018/11/28.
//
#include <stdio.h>
#include <malloc.h>
#include <math.h>
int* scanfmyself(int n);
int* findPri(int begin,int end);
int powInt(int, int);

int main() {
    int* p = scanfmyself(1);
    int n, flag = 1;
    for(int i = 2; i <= p[0]; i++) {
        n = powInt(2, i) - 1;
        int *pp = findPri(n, n);
        if(pp[0]) {
            flag = 0;
            printf("%d\n", n);
        }
    }
    if(flag) printf("None");
    return 0;
}


int powInt(int num, int n) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= num;
    }
    return result;
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

//返回的数组0号元素为size，其他是素数
//这里的p[0]，表示的是其后素数的个数，与我之后写的其他函数不同
int* findPri(int begin,int end) {
    int size = 0;
    int* p = NULL;    //数组记录素数
    int cap = 7;
    p = (int*)malloc(cap * sizeof(int));
    p[0] = size;
    if(begin != 2) {
        begin = (begin%2 == 0||(begin == 1&&end != 1))?begin+1:begin;
    }
    if(begin == 2){
        //when == 2
        size = 1;
        p[0] = 1;
        p[1] = 2;
        begin++;
    }
    for(int i = begin; i <= end && i > 2; i += 2) {
        int flag = 1;
        //从二开始，可以排除一
        for(int j = 2; j <= sqrt(i); j++) {
            if(i%j==0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            size++;
            if(cap <= size) {
                cap *= 2;
                p = (int*)realloc(p, cap * sizeof(int));
            }
            p[0] = size;
            p[size] = i;            //记录素数
        }
    }
    return p;
}
