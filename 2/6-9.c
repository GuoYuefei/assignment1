#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */

#include <string.h>

void StringCount( char *s ) {
    int lala[5] = {0};
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            lala[0]++;continue;
        }
        if(s[i] >= 'a' && s[i] <='z') {
            lala[1]++;continue;
        }
        if(s[i] == ' ') {
            lala[2]++;continue;
        }
        if(s[i] >= '0' && s[i] <= '9') {
            lala[3]++;continue;
        }
        lala[4]++;
    }
    for(int i = 0; i < 4; i++) {
        printf("%d ", lala[i]);
    }
    printf("%d", lala[4]);
}
