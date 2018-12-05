//
// Created by Administrator on 2018/11/28.
//
#include <stdio.h>
#include <malloc.h>


//索性写一个专门接受整型的函数吧
//p是数组，n是我要输入的整型的数字
int* scanfmyself(int n) ;

//拆分int类型，自动判定num的位数，并以int*类型返回
//个位在p[1]
int* splitInt(int num) ;

const char GG[5] = {'Q', 'W', 'S', 'B', 'Y'};

int main() {
    int *pp = scanfmyself(1);
    int *p = splitInt(pp[0]);
    free(pp);
    int cap = 9, size = 0;
    char *str = (char*)malloc(cap * sizeof(char));
    if(p[0] == 1) {
        str[size++] = 'a';
        goto HAHAHA;
    }
    for (int i = p[0] - 1; i > 0; i--) {
        if(size+4 < cap) {          //保证\0能加到最后
            cap *= 2;
            str = (char*)realloc(str, cap * sizeof(char));
        }

        if(p[i] == 0) {         //零位处理
            //其实应该检查个位和万位
            if(i == 5) {
                //万位
                size--;         //前面的a删除
                str[size++] = GG[1];
                if(p[i-1] == 0) str[size++] = 'a';           //千位有零在加
            } else if(i == 1) {
                size--;         //个位删a
            }
            continue;
        }
        char g, l = ' ';
        if(i%4 != 1) {      //十百千
            g = GG[i%4];
        } else if(i == 5) {
            g = GG[1];      //W
        } else if(i == 9){
            g = GG[4];          //Y
        } else {
            g = ' ';
        }
        if(p[i-1] == 0) {
            //如果低一位出现0，则需要多加个代表0的a
            l = 'a';
        }
        str[size++] = (char) ('a' + p[i]);
        if(g != ' ') {
            str[size++] = g;
        }

        if(l != ' ') {
            str[size++] = l;
        }
    }
HAHAHA:
    str[size++] = '\n';
    str = (char*)realloc(str, size * sizeof(char));
//    printf("%d\n", size);
    printf("%s",str);
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

