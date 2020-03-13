## 主要以问题为导向，实现两个增序链表的增序合并


/**20.3.13
 * 题目描述
 * 输入两个单调递增的链表，输出两个链表合成后的链表，合成后的链表满足单调不减
 * 测试数据：1 3 5  / 2 4 6 
 * 输出数据：1 2 3 4 5 6 
 */

#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
};

int ListLength = 0;     //链表长度
ListNode* pHead1 = (ListNode*)malloc(sizeof(ListNode));
ListNode* pHead2 = (ListNode*)malloc(sizeof(ListNode));
ListNode* pHead = (ListNode*)malloc(sizeof(ListNode)); //合成后的链表,带头结点

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

//链表合并方法1
/**
* 法1开辟了新的空间，方法不是很好，但逻辑相对清晰
*/
ListNode* merge1(ListNode* pHead1, ListNode* pHead2) {
    ListNode* p1 = pHead1->next;  //第一个链表指针
    ListNode* p2 = pHead2->next;  //第二个链表指针
    ListNode* p3 = pHead;         //合成链表的指针
    while (p1!=NULL || p2!=NULL) {//注意是或，不是与
        if (!p1) {
            p3->next = p2;
            break;
        }            
        else if (!p2) {
            p3->next = p1;
            break;
        }           
        while (p1 && p2 && (p1->val <= p2->val)) {
            p3->next = p1;       
            p3 = p1;
            p1 = p1->next;           
        }
        while (p1 && p2 && (p2->val < p1->val)) {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;            
        }
    }
    pHead->val = ListLength;    //给新链表头结点赋链表长度值
    return pHead;
}


//链表合并方法2——递归
/*
* 代码会简洁很多，但是难以理解
*/
ListNode* merge2(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL)
        return pHead2;
    if (pHead2 == NULL)
        return pHead1;
    else {
        if (pHead1->val <= pHead2->val) {
            pHead1->next = merge2(pHead1->next,pHead2);
            return pHead1;
        } else {           
            pHead2->next = merge2(pHead1, pHead2->next);
            return pHead2;
        }
    }
}

int main() {
    cout << "输入两个递增链表：" << endl;
    InitList(pHead1);
    InitList(pHead2);
    cout << "带头结点的链表合并方法1：";
    ListTraverse(merge1(pHead1->next, pHead2->next));//除去头结点，故加next
    //cout << "带头结点的链表递归合并：";
    //ListTraverse(merge2(pHead1->next, pHead2->next));//除去头结点，故加next
    return 0;
}
