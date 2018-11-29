
// 7-3 统计素数并求和 （20 分）
//本题要求统计给定整数M和N区间内素数的个数并对它们求和。
//
//输入格式:
//输入在一行中给出两个正整数M和N（1≤M≤N≤500）。
//
//输出格式:
//在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。
//
//输入样例:
//10 31
//输出样例:
//7 143

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* findPri(int begin,int end);
int* scanfmyself(int n);

int main() {
    int* p = NULL;
    int result = 0;
    p = scanfmyself(2);
    p = findPri(p[0], p[1]);
    for(int i = 1; i <= p[0]; i++) {
        result += p[i];
    }
    printf("%d %d", p[0], result);
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
int* findPri(int begin,int end) {
    int num = 0;
    int* p = NULL;    //数组记录素数
    int size = 7;
    p = (int*)malloc(size * sizeof(int));
    p[0] = num;
    if(begin != 2) {
        begin = (begin%2 == 0||(begin == 1&&end != 1))?begin+1:begin;
    }
    if(begin == 2){
        //when == 2
        num = 1;
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
            num++;
            if(size <= num) {
                size *= 2;
                p = (int*)realloc(p, size * sizeof(int));
            }
            p[0] = num;
            p[num] = i;            //记录素数
        }
    }
    return p;
}