# 数组
## 回忆:三个区
1. data 存放全局变量(系统分配,系统释放)
2. heap 可自行申请释放(new ,delete)
3. stack(系统分配,系统释放) 
   
## 构成常用的数组接口及成员变量
### 成员变量
- 1.维护数组的指针int* myparr
- 2.指针的容量capacity
- 3.指针的实际大小与末尾的后一个位置cur
### 常用接口
- 1.尾插void push_back(int val)
- 2.尾删int pop_back()
- 3.按索引添加void insert(int pos,int val)
- 4.查找第一个符合的元素int find(int val)
- 5.删除第一个符合的元素void erase(int val)

## 特别:双指针算法(reverse 逆序字符串)

