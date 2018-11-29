//
// Created by Administrator on 2018/11/28.
//

#include <stdio.h>
#include <malloc.h>


//用欧几里得算法写的递归法
long GCD1(long a, long b) ;

//辗转相除---欧几里得 迭代
long GCD(long a, long b) ;


//最小公倍数
long LCM(long a, long b) ;

long longabs(long a) ;

//此题的难点是求最大公约数
//一般算法题不会赤裸裸的让你写求最大公约数，此题就是套了一个外壳
int main() {
    int n = 0;
    scanf("%d", &n);
    long *z, *m;
    long lcm;
    long fz = 0;         //记录通分后分子和
    long integer,decimalz;        //整数部分和小数部分分子
    //分子数组
    z = (long*)malloc(n * sizeof(long));
    //分母数组
    m = (long*)malloc(n *sizeof(long));
    int flag = 1;
    for(int i = 0; i < n; i++) {
        scanf("%ld/%ld", z+i, m+i);
        if(z[i]) flag=0;          //只要分子不全为零
    }
    if(flag){
        free(z);free(m);
        goto AAA;          //出现全零
    }

    if(n == 1) {
        lcm = m[0];     //分母就是自己
        fz = z[0];      //分子就是自己
        goto HAHAHA;
    }

    //n > 2时
    lcm = LCM(m[0], m[1]);
    for (int i = 2; i < n; ++i) {
        //通过两两找最小公倍数得最终最小公倍数
        lcm = LCM(lcm, m[i]);
    }

    for (int i = 0; i < n; ++i) {
        fz += z[i] * lcm/m[i];       //得到通分后的分子
    }

HAHAHA:         //这里是format分式部分，也可以单独写一个函数哈
    free(z);free(m);
    integer = fz / lcm;
    decimalz = fz % lcm;
    long gcd = longabs(GCD(decimalz, lcm));
//    long gcd = GCD(decimalz, lcm);
//    printf("gcd = %ld\n", gcd);
    if(integer) {
        decimalz = longabs(decimalz);
        printf("%ld", integer);
        if(decimalz) {
            printf(" %ld/%ld", decimalz/gcd, lcm/gcd);
        }
    } else {
        if(decimalz) {
            printf("%ld/%ld", decimalz/gcd, lcm/gcd);
        } else {
AAA:
            printf("0");
        }
    }
    return 0;
}

//最大公约数 迭代法
//辗转相除---欧几里得 迭代
long GCD(long a, long b) {
    if(b) while((a %= b) && (b %= a));
    return a+b;
}
//最小公倍数
long LCM(long a, long b) {
    return a * b / GCD(a, b);
}

//最大公约数 递归法 --- 易理解
long GCD1(long a, long b) {
    if(a%b == 0) {
        return b;
    } else {
        return GCD1(b, a%b);
    }
}

long longabs(long a) {
    return a < 0 ? -a : a;
}