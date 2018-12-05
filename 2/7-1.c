#include <stdio.h>
#include <malloc.h>

//j + i = n - 1 副对角线
int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);           //1< num <= 10
    //申请二位数组
    int **p = malloc(sizeof(int*) * num);
    for(int i = 0; i < num; i++) p[i] = malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    // for(int i = 0; i < num; i++) {
    //     for(int j = 0; j < num; j++) {
    //         printf("%d ", p[i][j]);
    //     }
    //     printf("\n");
    // }
    int result = 0;
    for(int i = 0; i < num - 1; i++) {
        for(int j = 0; j < num - 1; j++) {
            if(i+j == num - 1) continue;
            result += p[i][j];
        }
    }
    printf("%d", result);
    return 0;
}
