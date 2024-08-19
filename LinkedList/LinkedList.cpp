#include <iostream>
#include <stdlib.h>
#include <time.h>
/**
 * 实现一个单链表:
 * 1.成员变量
 * 2.常用接口
 */
/**
 * 1.结构体成员变量
 * 数据域:data_
 * 指针域:next_
 * 1.成员变量
 * 头结点:head_(链表入口节点)
 */
/**
 * 2.常用接口
 * 链表尾插法:void InsertTail(int val)  时间复杂度O(n)
 * 链表头插法:void Inserthead_(int val)  时间复杂度O(1)
 * 链表删除第一个符合val的结点 void Remove(int val) 时间复杂度O(n)
 * 链表删除所有符合val的结点 void RemoveAll(int val) 时间复杂度O(n)
 * 链表搜索bool Find(int val) 时间复杂度O(n)
 * 单链表逆序 void ReverseLink(){}    时间复杂度O(n)
 * 单链表求倒数第K个结点 bool GetLastKNode(int k,int&val);  时间复杂度O(n)
 *
 */
/**
 * 3.常用操作
 * 合并两个有序单链表,使其仍然有序 void MergeLink(SingleLink& l1,SingleLink& l2) 思路:双指针
 * 判断单链表是否有环,并找出环的入口结点 bool IsLinkHasCircle(ListNode* head,int &val) 思路:快慢指针
 * 判断两个单链表是否相交 bool IsLinkHasMerge(ListNode* head1,LishNode* head2) 思路:双指针
 *
 */
struct Node
{
    Node(int val = 0, Node *next = nullptr) : data_(val), next_(next) {};
    int data_;   // 数据域
    Node *next_; // 指针域
};
class SingleLink
{
public:
    SingleLink()
    {
        // 构造函数
        head_ = new Node(0);
    }
    ~SingleLink()
    {
        // 结点的释放 头插法删除
        // Node *p = head_->next_;
        // while (p != nullptr)
        // {
        //     head_->next_ = head_->next_->next_;
        //     delete p;
        //     p = head_->next_;
        // }
        // delete head_;
        // 结点的释放2 顺序删除
        Node *p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }

private:
    Node *head_; // 指向链表的头结点,链表的入口
public:
    void InsertTail(int val)
    {
        // 尾插法
        // 找到末尾结点
        // ? 末尾结点的特点是:其结点的地址域为nullptr
        Node *p = head_; // 指向第一个结点
        while (p->next_ != nullptr)
        { // 只有找尾结点时 才写p->next_
            p = p->next_;
        }
        // 创建新结点
        Node *temp = new Node(val);
        // 把新结点添加到末尾结点之后
        p->next_ = temp;
    }
    void Inserthead_(int val)
    {
        // 创建新结点
        Node *p = new Node(val);
        // 新结点的地址域为head_->next_
        p->next_ = head_->next_;
        // 更新head_的地址域
        head_->next_ = p;
    }
    void Remove(int val)
    {
        // 删除第一个符合的结点
        Node *p = head_->next_; // 指向第一个结点
        Node *q = head_;        // 指向p前面一个结点
        // 首先找到符合的结点
        while (p != nullptr)
        {
            if (p->data_ != val)
            {
                q = p;
                p = p->next_;
            }
            else
            {
                break;
            }
        }
        q->next_ = p->next_;
        delete p;
    }
    void RemoveAll(int val)
    {
        Node *p = head_->next_;
        Node *q = head_;
        while (p != nullptr)
        {
            if (p->data_ != val)
            {
                q = p;
                p = p->next_;
            }
            else
            {
                q->next_ = p->next_;
                delete p;
                p = q->next_; // 重置一下p
            }
        }
        return;
    }
    bool Find(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                return true;
            }
            p = p->next_;
        }
        return false;
    }
    void Reverse()
    {
        // 接下来结点挨个按头插法插入头结点中
        Node *p = head_->next_; // 挨个遍历所有有效结点
        Node *q = head_->next_; // 保存结点的下一个元素
        // 取下头结点
        head_->next_ = nullptr;
        // 空链表判断
        if (p == nullptr)
        {
            return;
        }
        // 进行非空链表逆序
        while (p != nullptr)
        {
            q = p->next_;
            // 进行头插法插入head_中
            p->next_ = head_->next_;
            head_->next_ = p;
            p = q;
        }
        return;
    }
    bool GetLastKNode(int k, int &val)
    {
        // 查询倒数第k个结点,返回的值用val值带出来
        // 1.进行参数有效性判定
        if (k < 1)
        {
            return false;
        }
        // 创建pre,p指针
        Node *p = head_;
        Node *pre = head_;

        for (int i = 0; i < k; i++)
        {
            // p结点总共要先走n - k + 1步  4 - 3
            p = p->next_;
            if (p == nullptr)
            {
                return false; // 如果p指针变成空,则直接return false
            }
        }
        // 此时 p和pre同时移动,当p指向空结点时,pre指向的就是目标结点
        while (p != nullptr)
        {
            pre = pre->next_;
            p = p->next_;
        }
        val = pre->data_;
        return true;
    }
    void show()
    {

        Node *p = head_->next_;
        while (p != nullptr)
        {
            std::cout << p->data_ << " ";
            p = p->next_;
        }
        std::cout << std::endl;
    }
    friend void MergeLink(SingleLink &l1, SingleLink &l2);
};

void MergeLink(SingleLink &l1, SingleLink &l2)
{
    // 1.创建三个指针,p 顺序遍历l1链表 ,q 顺序遍历l2链表,last指向合并后链表的最后一个元素
    Node *p = l1.head_->next_;
    Node *q = l2.head_->next_;
    Node *last = l1.head_;
    while (p != nullptr && q != nullptr)
    {
        if (p->data_ < q->data_)
        {
            last->next_ = p;
            p = p->next_;
            last = last->next_;
        }
        else
        {
            last->next_ = q;
            q = q->next_;
            last = last->next_;
        }
    }
    if (p != nullptr)
    {
        last->next_ = p;
    }
    if (q != nullptr)
    {
        last->next_ = q;
    }
    l2.head_ = nullptr;
}
bool IsLinkHasCircle(Node *head, int &val)
{
    // 快慢指针的思想
    Node *fast = head;
    Node *slow = head;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;
        if (fast == slow)
        {
            // 找到了环
            fast = head;
            while (fast != slow)
            {
                fast = fast->next_;
                slow = slow->next_;
            }
            val = fast->data_;
            return true;
        }
    }
    return false;
}
bool IsLinkHasMerge(Node *head1, Node *head2)
{
    // 首先判断2个单链表的长度
    int cnt1 = 0;
    int cnt2 = 0;
    Node *p1 = head1->next_;
    while (p1 != nullptr)
    {
        cnt1++;
        p1 = p1->next_;
    }
    Node *p2 = head2->next_;
    while (p2 != nullptr)
    {
        cnt2++;
        p2 = p2->next_;
    }
    p2 = head2;
    p1 = head1;
    if (cnt1 > cnt2)
    {
        // 第一个链表长度更长
        // 让第一个链表先走cnt1 - cnt2步

        for (int i = 0; i < (cnt1 - cnt2); i++)
        {
            p1 = p1->next_;
        }
    }
    else
    {
        // 第二个链表长度更长
        // 让第二个链表先走cnt2 - cnt1步

        for (int i = 0; i < (cnt2 - cnt1); i++)
        {
            p2 = p2->next_;
        }
    }
    // 如果指针非空,接下来每一个链表走一步
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1 == p2)
        {
            return true;
        }
        p1 = p1->next_;
        p2 = p2->next_;
    }
    return false;
}
int main()
{
    // 释放种子
    Node n1(10), n2(20), n3(30), n4(40), n5(50);
    Node *head = new Node();

    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;
    n4.next_ = &n5;
    n5.next_ = &n5;
    head->next_ = &n1;
    int val = 0;
    if (IsLinkHasCircle(head, val))
    {
        std::cout << "环的值为:" << val << std::endl;
    }
    return 0;
}