#include <stdio.h>
#include <string.h>
int main()
{
    char a[]="hello world";
    printf("输出为%s\n",a);
    printf("占的字符数为%zu",sizeof(a));

    char b[13];
    strcpy_s(b,"Hello World");         //将字符串"Hello World"复制到数组b中,但不能写b="Hello World"

    printf("输出为%s\n",b);
    printf("占的字符数为%zu",sizeof(b));  //虽然数组b的大小为13,但实际存储的字符数为12
    printf("%lu",strlen(b));  //不包括'\0'但包括空格
    return 0;
}


//输出：
//输出为hello world
//占的字符数为12
//输出为Hello World
//占的字符数为13       sizeof返回的是数组的大小
//11                 strlen返回的是字符串的长度
