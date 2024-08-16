/**
 * 学习目的:双指针算法的应用
 * 问题:给你一个整形数组,把偶数调整到数组左边,把奇数调整到数组的右边
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void adjustArray(int arr[], int size)
{
    /**
     * 双指针
     */
    int *p = arr;
    int *q = arr + size - 1;
    // 已经分别指向开头和末尾
    while (p < q)
    {
        if (*p % 2 == 0)
        {
            p++; // 找左边的奇数
            continue;
        }
        if (*q % 2 == 0)
        {
            // 此时右边是偶数
            // 交换
            int temp = *q;
            *q = *p;
            *p = temp;
        }
        else
        {
            q--;
        }
    }
}
int main()
{
    int arr[10] = {0};
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    adjustArray(arr, 10);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}