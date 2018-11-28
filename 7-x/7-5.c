//
// Created by Administrator on 2018/11/28.
//
#include <stdio.h>
#include <stdlib.h>

int* scanfmyself(int);
int powInt(int, int);
int isOk(int, int);
int minN(int);

//gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
int main() {
    int flag = 0;
    int rst[10] = {0};            //不超过9个, rst[0] = 数量
    int* p = scanfmyself(1);
    int begin = minN(p[0]), end = minN(p[0] + 1);
    for(int i = begin; i < end; i++) {
        if(isOk(i, p[0])) {
            rst[0]++;
            rst[rst[0]] = i;
        }
    }

    for(int i = 0; i < rst[0]; ) {
        printf("%d\n", rst[++i]);
    }
    return 0;
}

//索性写一个专门接受整型的函数吧
//p是数组，n是我要输入的整型的数字
int* scanfmyself(int n){
    int *p = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", p+i);
    }
    return p;
}

int powInt(int num, int n) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= num;
    }
    return result;
}

//1 true,0 false
int isOk(int num,int n) {
//    int* p = (int*)malloc(n * sizeof(int));
    int a = 0,temp;
    int temp1 = num;
    for(int i = 0; i < n; i++) {
//        p[i] = num % 10;
        temp = temp1 % 10;
        temp1 /= 10;
        a += powInt(temp, n);
    }
    return a == num;
}

//返回最小的n位数
int minN(int n) {
    char* p = (char*)malloc(n * sizeof(char));
    p[0] = '1';
    for(int i = 1; i < n ; i++) {
        p[i] = '0';
    }
    return atoi(p);
}