
/**20.3.13
 * ��Ŀ����
 * ���������������������������������ϳɺ�������ϳɺ���������㵥������
 * �������ݣ�1 3 5  / 2 4 6 
 * ������ݣ�1 2 3 4 5 6 
 */

#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
};

int ListLength = 0;     //������
ListNode* pHead1 = (ListNode*)malloc(sizeof(ListNode));
ListNode* pHead2 = (ListNode*)malloc(sizeof(ListNode));
ListNode* pHead = (ListNode*)malloc(sizeof(ListNode)); //�ϳɺ������,��ͷ���

//��������
void InitList(ListNode* pHead) {
    int val;
    ListNode* q = pHead;//q���Ǹ���������pHead�б������������

    while (cin >> val) {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->val = val;
        p->next = NULL;
        q->next = p;   //��ͷ���
        q = p;
        ListLength++;  //������

        if (getchar() == '\n')
            break;
    }
    pHead->val = ListLength;
}

//�������
void ListTraverse(ListNode* pHead) {
    ListNode* p = pHead;
    while (p) {
        ListLength++;
        cout << p->val << " ";
        p = p->next;
    }
}

//����ϲ�����1
/**
* ��1�������µĿռ䣬�������Ǻܺã����߼��������
*/
ListNode* merge1(ListNode* pHead1, ListNode* pHead2) {
    ListNode* p1 = pHead1->next;  //��һ������ָ��
    ListNode* p2 = pHead2->next;  //�ڶ�������ָ��
    ListNode* p3 = pHead;         //�ϳ������ָ��
    while (p1!=NULL || p2!=NULL) {//ע���ǻ򣬲�����
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
    pHead->val = ListLength;    //��������ͷ��㸳������ֵ
    return pHead;
}


//����ϲ�����2�����ݹ�
/*
* �������ܶ࣬�����������
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
    cout << "����������������" << endl;
    InitList(pHead1);
    InitList(pHead2);
    cout << "��ͷ��������ϲ�����1��";
    ListTraverse(merge1(pHead1->next, pHead2->next));//��ȥͷ��㣬�ʼ�next
    //cout << "��ͷ��������ݹ�ϲ���";
    //ListTraverse(merge2(pHead1->next, pHead2->next));//��ȥͷ��㣬�ʼ�next
    return 0;
}