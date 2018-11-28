//
// Created by Administrator on 2018/11/28.
//

#include <stdio.h>


//用欧几里得算法写的递归法
int GCD1(int a, int b) ;

//辗转相除---欧几里得 迭代
int GCD(int a, int b) ;

//此题的难点是求最大公约数
//一般算法题不会赤裸裸的让你写求最大公约数，此题就是套了一个外壳
int main() {
    int a = GCD1(27, 15);
    printf("a = %d\n", a);
    a = GCD(27, 15);
    printf("a = %d", a);
    return 0;
}

//分析，需要找几个数的公因子，然后

//辗转相除---欧几里得 迭代
int GCD(int a, int b) {
    if(b) while((a %= b) && (b %= a));
    return a+b;
}
int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

//用欧几里得算法写的递归法
int GCD1(int a, int b) {
    if(a%b == 0) {
        return b;
    } else {
        return GCD1(b, a%b);
    }
}

