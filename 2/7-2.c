//看到题目，其实就是选择排序， 在这个过程顺便把重复的给解决掉
//最简单的逻辑 先排序，连续去重
#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a, const void* b) {
    return *(char *)a - *(char *)b;       //升序排序
}
int main() {
    char cs[81];
    int num = 0;
    for(num = 0; num < 81; num++) {
        scanf("%c", cs + num);
        if(cs[num] == '\n') {
            break;
        }
    }
    qsort(cs, num, sizeof(char), cmp);          //先排序

    int result[80];int size = 0;
    for(int i = 0; i < num;){
        result[size++] = cs[i];
        i++;
        for(int j = i-1; j < num; j++) {
            if(cs[j] != cs[j+1]) {
                break;          //因为排好序的，所以可以认定没有重复的
            }
            i++;
        }
    }
    for(int i = 0; i < size; i++) {
        printf("%c", result[i]);
    }
}

