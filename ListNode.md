## 这篇主要是记录了关于链表的基本操作，包括 1.创建链表 2.链表的遍历 3.链表的逆置——三种方法实现 
/**2020.3.11-3.12
 * 该代码功能如下:
 * 1.链表的创建(带头结点)
 * 2.遍历
 * 3.将链表长度存在头结点数据域中
 * 4.三种逆置方法：①原地非递归  ②递归 ③插入法
 */
```
#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
};

int ListLength = 0;     //链表长度

ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));

//创建链表
void InitList(ListNode* pHead) {
    int val;
    ListNode* q = pHead;//q就是个苦力，给pHead招兵买马，组成行伍

    while (cin >> val) {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->val = val;
        p->next = NULL;
        q->next = p;   //带头结点
        q = p;
        ListLength++;  //链表长度

        if (getchar() == '\n')
            break;
    }
    pHead->val = ListLength;
}

//链表遍历
void ListTraverse(ListNode* pHead) {
    ListNode* p = pHead;
    while (p) {
        ListLength++;
        cout << p->val << " ";
        p = p->next;
    }
}

//链表逆置方法一、原地逆置:pre和cur之间的交换
        /**
         * 注意：头结点不参与逆置
         * 所以从头结点以后开始逆置，最后将逆置后的指针指向头结点尾部
         */
ListNode* non_recursive_ListReverse(ListNode* pHead) {
    ListNode* pre = pHead->next;    //从头结点下一个结点开始逆置
    ListNode* cur = pre->next;
    ListNode* rear = cur->next;
    pre->next = NULL;               //确保逆置后的链表末尾是NULL
    while (rear) {                  //等同于rear!=NULL
        cur->next = pre;
        pre = cur;
        cur = rear;
        rear = cur->next;
    }
    cur->next = pre;                //next为NULL,cur前面结点都已逆向，将cur逆向为数据域的第一个结点
    pHead->next = cur;              //挂至头结点后
    return pHead;
}
//链表逆置方法二、递归
        /**
        * 对不带头结点的链表使用
        * 带头结点的链表，头结点会变为最后一个点
        */
ListNode* recursive_ListReverse(ListNode* head) {
    ListNode* cur = head;
    if (!cur || !cur->next)
        return cur;
    ListNode* newHead = recursive_ListReverse(cur->next);//即最后一个结点，也是新链表数据域的头
    head->next->next = head;//head是旧链表中cur结点的前一个
    head->next = NULL;
    return newHead;
}

//链表逆置方法三、插入法
        /**
        * 从头结点后面第二个开始，插入至头结点与第一个结点间
        * 以后依次执行
        */
ListNode* Insert_ListReverse(ListNode* pHead) {
    ListNode* cur = pHead->next->next;//从头结点后面第二个数据开始
    ListNode* rear = NULL;
    pHead->next->next = NULL;
    while (cur) {
        //链表插入的过程
        rear = cur->next;        //将下一个位置确定
        cur->next = pHead->next; //数据域第一个结点连接至cur后面
        pHead->next = cur;       //cur再连接至头结点后
        cur = rear;              //更新cur指针，继续向下遍历
    }
    return pHead;
}

int main() {
    cout << "输入一串数值，空格分开" << endl;
    InitList(pHead);
    //一下三种方法使用时屏蔽测试，不要一起输出
    cout << "带头结点的插入法逆置:";
    ListTraverse(Insert_ListReverse(pHead));         //带头结点的链表——非递归逆置
    cout << endl << "带头结点的非递归逆置:";
    ListTraverse(non_recursive_ListReverse(pHead));  //带头结点的链表——非递归逆置
    cout << endl << "不带头结点的递归逆置:";
    ListTraverse(recursive_ListReverse(pHead->next));//去掉头结点的链表——递归逆置

    return 0;
}
```
