//
// Created by Solomon Guo on 2018/12/5.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>

const int power[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char table[] = {"10X98765432"};

char* getline();
int isNum(char a);
int powersum(char *p, const int *power, int);
int main() {
    int a;
    scanf("%d", &a);getchar();      //'\n'去除
    char **p = (char**)malloc(a * sizeof(char*));
    char *flag = (char*)malloc((a+1) * sizeof(char));
    for(int i = 0; i < a+1; i++) flag[i] = 1;             //默认全部合格
    for (int i = 0; i < a; ++i) {
        p[i] = getline();
    }
    for (int i = 0; i < a; ++i) {
        int len = strlen(p[i]);
        if(table[powersum(p[i], power, len-1)%11] != p[i][len-1]) {
            //校验
            flag[i] = 0;flag[a] = 0;
            continue;
        }
        for (int j = 0; j < len; ++j) {
            if(len - 1 != j && !isNum(p[i][j])) {
                flag[i] = 0;flag[a] = 0;
                break;
            }

        }
    }
    if(flag[a]){
        printf("All passed");
        return 0;
    }
    for (int i = 0; i < a; ++i) {
        if(!flag[i]) printf("%s\n", p[i]);
    }

    return 0;
}

//万能获取一行字符串的函数诞生了,windows上貌似没有getline函数,手写一个针对stdin的把
char* getline() {
    const int BUFSIZE = 17;
    int cap = BUFSIZE+1;       //初始cap设置BUFSIZE 动态增长空间,防止空间损失
    char *str = (char*)malloc(cap * sizeof(char));
    *str = '\0';
    char buffer[BUFSIZE];buffer[0] = '\0';
    //调试发现\n也会被存储
    while(strlen(fgets(buffer, BUFSIZE, stdin))) {
//        printf("buffer: %d %d\n", (int)strlen(buffer), (int)sizeof(buffer));
        if(strlen(str)+BUFSIZE >= cap) {
            cap += 2;cap <<= 1;               //每次cap不够时cap+2翻倍,防止多次分配空间造成时间损失
            str = (char*)realloc(str, sizeof(char) * cap);
        }
        strcat(str, buffer);
        if(buffer[strlen(buffer)-1] == '\n') break;
    }
    str[strlen(str)-1] = '\0';          //手动替换\n -> \0
    str = (char*)realloc(str, sizeof(char)*(strlen(str)+1));
    return str;
}

int isNum(char a) {
    if(a>='0'&&a<='9') {
        return 1;
    }
    return 0;
}

//加权求和
int powersum(char *const p, const int * const power, int len) {
    int result = 0;
    for (int i = 0; i < len; ++i) {
        result += (p[i]-'0')*power[i];
    }
    return result;
}

