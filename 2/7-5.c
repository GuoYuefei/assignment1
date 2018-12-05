//
// Created by Solomon Guo on 2018/12/4.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>

//万能获取一行字符串的函数诞生了，windows上貌似没有getline函数，手写一个针对stdin的把
char* getline() ;


//只会删除第一个找到的cs子串
//成功返回就返回非0，失败返回0
int deletestr(char * str, const char  *  cs) ;

int main() {
    char *str = getline();
    char *cs = getline();
    while(deletestr(str, cs));
    free(cs);
    printf("%s", str);
    free(str);
    return 0;
}

//只会删除第一个找到的cs子串
//成功返回就返回非0，失败返回0
int deletestr(char *const str, const char * cs) {
    char *const p = strstr(str, cs);
    if(!p) return 0;        //p == null时说明查找都失败了，也就删除失败了
    int i = 0;
    for (i = 0; i < strlen(p) - strlen(cs); ++i) {
        p[i] = p[i+strlen(cs)];
    }
    p[i] = '\0';
    return 1;
}

//万能获取一行字符串的函数诞生了，windows上貌似没有getline函数，手写一个针对stdin的把
char* getline() {
    const int BUFSIZE = 17;
    int cap = BUFSIZE+1;       //初始cap设置BUFSIZE 动态增长空间，防止空间损失
    char *str = (char*)malloc(cap * sizeof(char));
    *str = '\0';
    char buffer[BUFSIZE];buffer[0] = '\0';
    //调试发现\n也会被存储
    while(strlen(fgets(buffer, BUFSIZE, stdin))) {
//        printf("buffer: %d %d\n", (int)strlen(buffer), (int)sizeof(buffer));
        if(strlen(str)+BUFSIZE >= cap) {
            cap += 2;cap <<= 1;               //每次cap不够时cap+2翻倍，防止多次分配空间造成时间损失
            str = (char*)realloc(str, sizeof(char) * cap);
        }
        strcat(str, buffer);
        if(buffer[strlen(buffer)-1] == '\n') break;
    }
    str[strlen(str)-1] = '\0';          //手动替换\n -> \0
    str = (char*)realloc(str, sizeof(char)*(strlen(str)+1));
    return str;
}
