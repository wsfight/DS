/**
 * 学习目的:双指针逆序字符串
 * 思路: 1.指向索引0位置指针p,执行索引strlen(str)-1位置指针q,两者元素互换,
 *       2.接着p++,q--
 *       3.循环至p>=q
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void reverse(char str[], int len)
{
    char *p = str;
    char *q = str + len - 1;
    char temp;
    while (p < q)
    {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    return;
}

int main()
{
    char str[] = "hello,world";
    reverse(str, strlen(str));
    cout << str << endl;
    return 0;
}