/**
 * 实现动态扩容的数组:
 * 1.成员变量
 * 2.常用接口
 */

/**
 * 成员变量
 * 1.指针mypArr:用来维护数组
 * 2.容量myCapcity
 * 3.实际大小cur
 */
/**
 * 常用接口:
 * 1.末尾删除元素int pop_back()
 * 2.末尾增加元素void push_back(int val)
 * 3.按位置增加元素void insert(int pos,int val)
 * 4.按元素删除void erase(int val)
 * 5.按值查询索引int find(int val)
 * 6.内部接口
 * 6.1.扩容expand(2 * myCapacity) // 原来基础上进行二倍扩容
 */

#include <iostream>
using namespace std;

class Aarry
{
private:
    int *mypArr;
    int myCapacity;
    int cur;
    void expand(int size)
    {
        int *p = new int(size);
        memcpy(p, mypArr, sizeof(myCapacity * sizeof(int)));
        delete[] mypArr;
        mypArr = p;
    }

public:
    Aarry(int size = 10) : cur(0), myCapacity(size)
    {
        // 默认构造
        mypArr = new int[myCapacity];
    }
    ~Aarry()
    {
        // 析构函数
        delete[] mypArr;
        mypArr = nullptr;
    }
    int pop_back()
    {
        // 1.末尾删除元素
        int ret = mypArr[cur - 1];
        cur--;
        return ret;
    }
    void push_back(int val)
    {
        // 2.末尾添加元素
        if (cur == myCapacity)
        {
            // 表明需要扩容
            expand(myCapacity * 2);
            myCapacity *= 2;
        }
        mypArr[cur] = val;
        cur++;
    }
    void insert(int pos, int val)
    {
        // 3.按位置添加元素
        if (cur == myCapacity)
        {
            expand(myCapacity * 2);
            myCapacity *= 2;
        }
        // 所有处于pos后的元素后移
        for (int i = cur - 1; i >= pos; i--)
        {
            mypArr[i + 1] = mypArr[i];
        }
        mypArr[pos] = val;
        cur++;
    }
    int find(int val)
    {
        // 4.按值查找第一个符合要求的,并返回其索引
        for (int i = 0; i < cur; i++)
        {
            if (mypArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void erase(int val)
    {
        // 5.按值进行删除
        // 首先查找其索引
        int ret = find(val);
        if (ret == -1)
        {
            return; // throw wrong val;
        }
        for (int i = ret + 1; i < cur; i++)
        {
            mypArr[i - 1] = mypArr[i];
        }
        cur--;
        return;
    }
    void print()
    {
        for (int i = 0; i < cur; i++)
        {
            std::cout << mypArr[i] << std::endl;
        }
    }
};

int main()
{
    Aarry array;
    for (int i = 0; i < 10; i++)
    {
        array.push_back(i * 2);
    }
    return 0;
}