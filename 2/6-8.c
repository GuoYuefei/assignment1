

#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
// void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN] = "1223352462222", c;
    scanf("%c", &c);
    // ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}

#include <string.h>
void delchar( char *str, char c ) {
    for(int i = 0; i < strlen(str);) {
        if(str[i]==c) {
            for(int j = i; j < strlen(str)-1; j++) {
                str[j] = str[j+1];
            }
            str[strlen(str)-1] = '\0';continue;
        }
        i++;
    }
}

