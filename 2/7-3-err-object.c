//
// Created by Solomon Guo on 2018/12/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// 这道题我就是为了玩
// 尝试下用面向对象的思想去做这题
// 故而不取最快逻辑，也不取最佳时间效率和空间效率



//果断封装一个数据结构
typedef struct CS CS;


typedef void (*Push)(CS *cs, char c);

typedef void (*func)(char* c, char);

typedef void (*ForEach)(CS *cs, func dosome, char);

struct CS{
    int cap;
    char* cs;
    int size;
    Push push;
    ForEach  forEach;
};

void csPush(CS *cs, char c) {
    if(cs->size == cs->cap-1) {
        cs->cap *= 2;
        cs->cs = (char*)realloc(cs->cs, sizeof(char) * cs->cap);
    }
    cs->cs[cs->size++] = c;
}

void forEach(CS *cs, func dosome, char c) {
    for(int i = 0; i < cs->size; i++) {
        dosome(&(cs->cs[i]), c);
    }
}

CS* NewCS() {
    CS *cs = (CS*)malloc(sizeof(CS));
    cs->cap = 16;
    cs->cs = (char*)malloc(sizeof(char) * 16);
    cs->size = 0;
    cs->push = csPush;
    cs->forEach = forEach;
    return cs;
}

void dosomething(char *c, char);
int main() {
    char cs[81];
    int num = 0;
    CS *cc = NewCS();
    for(num = 0; num < 81; num++) {
        scanf("%c", cs + num);
        cc->push(cc, cs[num]);
        if(cs[num] == '\n') {
            break;
        }
    }
    cc->forEach(cc, dosomething, 'a');

    return 0;
}

void dosomething(char *c, char c2) {
    if(*c == c2) {
        return;
    }
    printf("%c ", *c);
}

//int dosome(char *c, char c2) {
//    if(*c == c2) {
//        return 0;
//    }
//    return 1;
//}
//int isHere(CS *cs, char c) {
//    cs->forEach(cs, dosome, c);
//}

