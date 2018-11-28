////索性写一个专门接受整型的函数吧
////p是数组，n是我要输入的整型的数字
//int* scanfmyself(int n){
//    int *p = (int*)malloc(n * sizeof(int));
//    for(int i = 0; i < n; i++) {
//        scanf("%d", p+i);
//    }
//    return p;
//}
//
////返回的数组0号元素为size，其他是素数
//int* findPri(int begin,int end) {
//    int num = 0;
//    int* p = NULL;    //数组记录素数
//    int size = 7;
//    p = (int*)malloc(size * sizeof(int));
//    p[0] = num;
//    if(begin != 2) {
//        begin = (begin%2 == 0||(begin == 1&&end != 1))?begin+1:begin;
//    }
//    if(begin == 2){
//        //when == 2
//        num = 1;
//        p[0] = 1;
//        p[1] = 2;
//        begin++;
//    }
//    for(int i = begin; i <= end && i > 2; i += 2) {
//        int flag = 1;
//        //从二开始，可以排除一
//        for(int j = 2; j <= sqrt(i); j++) {
//            if(i%j==0) {
//                flag = 0;
//                break;
//            }
//        }
//        if(flag == 1) {
//            num++;
//            if(size <= num) {
//                size *= 2;
//                p = (int*)realloc(p, size * sizeof(int));
//            }
//            p[0] = num;
//            p[num] = i;            //记录素数
//        }
//    }
//    return p;
//}