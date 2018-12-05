/**
    Copyright 2018 The C Authors Solomon Guo. All rights reserved.
​	Use of this source code is governed by a MIT
​	license that can be found in the LICENSE file.
 */

//索性写一个专门接受整型的函数吧
//p是数组，n是我要输入的整型的数字
//依赖 stdio.h malloc.h
int* scanfmyself(int n){
    int *p = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", p+i);
    }
    return p;
}


//num的因子(除1与本身外)以数组形式返回   参照找素数

/**
 * 依赖malloc.h math.h
 * @param num 要查找的数字
 * @return 因子数组p[0]代表数组本身的大小，也就是因子数为p[0]-1
 */
int* findFactor(int num) {
    int cap = 7;
    int* p = (int*)malloc(cap * sizeof(int)); int size = 1; p[0] = size;
    for(int j = 2; j <= sqrt(num)+0.001; j++) {         //+0.001是因为double的大小难以控制
        if(num%j==0) {
            if(size+2 > cap) {
                cap *= 2;
                p = (int*)realloc(p, cap * sizeof(int));
            }
            p[size++] = j; p[0] = size;
            if(j != num/j) {
                p[size++] = num/j; p[0] = size;
            }
        }
    }
    p = (int*)realloc(p, p[0] * sizeof(int));
    return p;
}

//返回的数组0号元素为size，其他是素数

/**
 * 近可能的高效
 * //依赖malloc.h math.h
 * @param begin 搜寻的第一个数字
 * @param end 搜寻的结束数字
 * @return  返回一个数组P，P[0]代表这个数组的长度，P[1]开始是搜寻到的素数，升序排列
 */
int* findPri(int begin,int end) {
    int num = 0;
    int* p = NULL;    //数组记录素数
    int size = 7;
    p = (int*)malloc(size * sizeof(int));
    p[0] = num;
    if(begin != 2) {
        begin = (begin%2 == 0||(begin == 1&&end != 1))?begin+1:begin;
    }
    if(begin == 2){
        //when == 2
        num = 1;
        p[0] = 1;
        p[1] = 2;
        begin++;
    }
    for(int i = begin; i <= end && i > 2; i += 2) {
        int flag = 1;
        //从二开始，可以排除一
        for(int j = 2; j <= sqrt(i); j++) {
            if(i%j==0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            num++;
            if(size <= num) {
                size *= 2;
                p = (int*)realloc(p, size * sizeof(int));
            }
            p[0] = num;
            p[num] = i;            //记录素数
        }
    }
    return p;
}

//---------------------------整数的拆分与重组-------------------------------------/

/**
 * malloc.h
 * @param num 要拆分的整型数
 * @return 返回一个num拆分后的int指针 其中p[0]记录数组的长度，p[1]代表个位
 */
int* splitInt(int num) {
    int cap = 7;        //容器大小刚刚开始为7，用p[0]记录
    int temp = num,temp1;
    int* p = (int*)malloc(cap * sizeof(int)); int size = 1; p[0] = size;     //p[0]用于装size
    while(temp) {
        if(size >= cap) {
            cap *= 2;
            p = (int*)realloc(p, cap * sizeof(int));
        }
        temp1 = temp % 10;
        temp /= 10;
        p[size++] = temp1;
        p[0] = size;
    }
    p = (int*)realloc(p, size * sizeof(int));
    return p;
}

/**
 * 依赖下面的函数powInt
 * @param p 需要重组的数组，其中p[0]代表数组的长度  p[1]代表个位。。。
 * @return 返回重组后的整型数 与
 */
int composeInt(const int *p) {
    int result = 0;
    for(int i = 1; i < p[0]; i++) {
        result += p[i]*powInt(10,i - 1);
    }
    return result;
}

/**
 * 整型求幂
 * @param num 数
 * @param n 幂
 * @return 结果
 */
int powInt(int num, int n) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= num;
    }
    return result;
}


//--------------------------------万能的读取一行字符串----------------------//

/**
 * 万能获取一行字符串的函数诞生了，windows上貌似没有getline函数，手写一个针对stdin的吧
 * 从命令行中获取一行的字符串，字符串以char指针的方式返回
 * 可直接用空的字符指针接收
 * 2018.12.4 依赖malloc.h string.h stdio.h
 * 2018.12.5 fix
 * @return 返回接收到的字符数组
 */
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

//---------------------------------删除出现的第一个子串---------------------------------//

/**
 * 2018.12.5 依赖string.h
 * 只会删除第一个找到的cs子串
 * @param str 母串
 * @param cs 子串
 * @return 删除成功返回1，失败（不存在子串）返回0
 */
int deletestr(char const *str, const char const *cs) {
    char *p = strstr(str, cs);
    if(!p) return 0;        //p == null时说明查找都失败了，也就删除失败了
    int i;
    for (i = 0; i < strlen(p) - strlen(cs); ++i) {
        p[i] = p[i+strlen(cs)];
    }
    p[i] = '\0';
    return 1;
}

//--------------------------------math-----------------------------------//

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

//long的abs
long longabs(long a) {
    return a < 0 ? -a : a;
}
