
#include <stdio.h>
#include <stdlib.h>

int isHere(char const * cs, int len) ;

//除大写外false
int isUpper(char c) ;

int main() {
    char cs[27];
    int num = 0;
    for(num = 1; num < 27;) {
        scanf("%c", cs);        //cs[0]记当前
        if(cs[0] == '\n') {
            break;
        }
        if(!isUpper(cs[0])||isHere(cs, num)) {
            continue;
        }
        cs[num] = cs[0];
        printf("%c", cs[num]);
        num++;
    }
    if(num==1) {
        printf("Not Found");
    }
    return 0;
}

int isHere(char const * cs, int len) {
    for (int i = 1; i < len; ++i) {
        if(cs[i]==cs[0]) return 1;      //存在
    }
    return 0;               //不存在
}

//除大写外false
int isUpper(char c) {
    if(c>='A'&&c<='Z') {
        return 1;
    }
    return 0;
};





