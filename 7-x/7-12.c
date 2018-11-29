//
// 7-12 天梯赛座位分配 （20 分）
//天梯赛每年有大量参赛队员，要保证同一所学校的所有队员都不能相邻，分配座位就成为一件比较麻烦的事情。为此我们制定如下策略：假设某赛场有 N 所学校参赛，第 i 所学校有 M[i] 支队伍，每队 10 位参赛选手。令每校选手排成一列纵队，第 i+1 队的选手排在第 i 队选手之后。从第 1 所学校开始，各校的第 1 位队员顺次入座，然后是各校的第 2 位队员…… 以此类推。如果最后只剩下 1 所学校的队伍还没有分配座位，则需要安排他们的队员隔位就坐。本题就要求你编写程序，自动为各校生成队员的座位号，从 1 开始编号。
//
//输入格式：
//输入在一行中给出参赛的高校数 N （不超过100的正整数）；第二行给出 N 个不超过10的正整数，其中第 i 个数对应第 i 所高校的参赛队伍数，数字间以空格分隔。
//
//输出格式：
//从第 1 所高校的第 1 支队伍开始，顺次输出队员的座位号。每队占一行，座位号间以 1 个空格分隔，行首尾不得有多余空格。另外，每所高校的第一行按“#X”输出该校的编号X，从 1 开始。
//
//输入样例：
//3
//3 4 2
//

#include <stdio.h>
#include <stdlib.h>

//索性写一个专门接受整型的函数吧
//p是数组，n是我要输入的整型的数字
int* scanfmyself(int n) ;

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

typedef unsigned int uint;

//队列思想， 只需size无需容器
//哇哈哈，减少空间，增加逻辑
int main() {
    int *n = scanfmyself(1);
    int *p = scanfmyself(n[0]);
    int *tempp = (int*)malloc(n[0]*sizeof(int));
    for (int i = 0; i < n[0]; ++i) {
        tempp[i] = p[i];            //在拷贝一份
    }
    qsort(tempp, (uint)n[0], sizeof(int), cmp);         //升序
    //要分析每个高校的
    for(int j = 0; j < n[0]; j++) {
        int space = n[0]; int s = 0;int hm = j+1;
        printf("#%d", j+1);
        for(int i = 0; i < p[j]*10; i++) {
            if(!(i%10)) {
                printf("\n");
            } else {
                printf(" ");
            }
            printf("%d", hm);
            //这儿加入分析代码
            if(s < n[0] && i >= 10*(tempp[s]) && space >2) {
                do {
                    if(space > 2) space--;
                    s++;
                } while(s < n[0]&&tempp[s] == tempp[s-1]);
            }
            hm += space;
        }
        printf("\n");
    }

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

