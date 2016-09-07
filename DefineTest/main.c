//
//  main.c
//  DefineTest
//
//  Created by BiuKia on 16/9/6.
//  Copyright © 2016年 SHP. All rights reserved.
//

#include <stdio.h>
#include <limits.h>


//使用#是把参数变成字符串，使用##是把前后连接的参数拼接起来，方便使用
#define A              2
#define STR_A(a)       #a
#define MULTI(a, b)    (a##e##b)


//转换宏
#define _STR_A(a)     STR_A(a)
#define _MULTI(a, b)  MULTI(a, b)

int main(int argc, const char * argv[]) {

    
    printf("情况一：入参中都是具体的变量，没有宏参数，可以正常使用\n");
    printf("A：%d\n",A);
    printf("STR_A:%s\n",STR_A(3));
    int rel = MULTI(2, 3);
    printf("MULTI:%d\n",rel);
    
    printf("\n********************************\n\n");
    
    
    printf("情况二：入参中有宏参数，此时使用宏定义中有# ，##的地方，宏参数不会再次展开，使用#的宏定义此时会把宏参数直接当成字符串处理，使用##的地方，会报语法错误或者编译错误");
//    printf("使用宏参数：%s\n",STR_A(INT_MAX));
//    int rel2 = MULTI(A, A);    //!Error:Use of undeclared identifier AeA
//    printf("使用宏参数：%d",rel2);
    
    printf("当使用宏参数的处理办法：多加一层中间转换宏，加这层宏的用意是使用所有宏的参数都在这一层展开，就能正常使用\n");
    printf("加入转换宏后，使用宏参数:\n STR_A:%s\n",_STR_A(INT_MAX));
    int rel2 = _MULTI(2, 3);
    printf("加入转换宏后，使用宏参数:\n MULTI:%d\n",rel2);
    
    
    
    return 0;
}

