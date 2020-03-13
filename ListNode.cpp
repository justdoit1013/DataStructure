/**2020.3.11-3.12
 * �ô��빦������:
 * 1.����Ĵ���(��ͷ���)
 * 2.����
 * 3.�������ȴ���ͷ�����������
 * 4.�������÷�������ԭ�طǵݹ�  �ڵݹ� �۲��뷨
 */

#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
};

int ListLength = 0;     //������

ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));

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

//�������÷���һ��ԭ������:pre��cur֮��Ľ���
        /**
         * ע�⣺ͷ��㲻��������
         * ���Դ�ͷ����Ժ�ʼ���ã�������ú��ָ��ָ��ͷ���β��
         */
ListNode* non_recursive_ListReverse(ListNode* pHead) {
    ListNode* pre = pHead->next;    //��ͷ�����һ����㿪ʼ����
    ListNode* cur = pre->next;
    ListNode* rear = cur->next;
    pre->next = NULL;               //ȷ�����ú������ĩβ��NULL
    while (rear) {                  //��ͬ��rear!=NULL
        cur->next = pre;
        pre = cur;
        cur = rear;
        rear = cur->next;
    }
    cur->next = pre;                //nextΪNULL,curǰ���㶼�����򣬽�cur����Ϊ������ĵ�һ�����
    pHead->next = cur;              //����ͷ����
    return pHead;
}
//�������÷��������ݹ�
        /**
        * �Բ���ͷ��������ʹ��
        * ��ͷ��������ͷ�����Ϊ���һ����
        */
ListNode* recursive_ListReverse(ListNode* head) {
    ListNode* cur = head;
    if (!cur || !cur->next)
        return cur;
    ListNode* newHead = recursive_ListReverse(cur->next);//�����һ����㣬Ҳ���������������ͷ
    head->next->next = head;//head�Ǿ�������cur����ǰһ��
    head->next = NULL;
    return newHead;
}

//�������÷����������뷨
        /**
        * ��ͷ������ڶ�����ʼ��������ͷ������һ������
        * �Ժ�����ִ��
        */
ListNode* Insert_ListReverse(ListNode* pHead) {
    ListNode* cur = pHead->next->next;//��ͷ������ڶ������ݿ�ʼ
    ListNode* rear = NULL;
    pHead->next->next = NULL;
    while (cur) {
        //�������Ĺ���
        rear = cur->next;        //����һ��λ��ȷ��
        cur->next = pHead->next; //�������һ�����������cur����
        pHead->next = cur;       //cur��������ͷ����
        cur = rear;              //����curָ�룬�������±���
    }
    return pHead;
}

int main() {
    cout << "����һ����ֵ���ո�ֿ�" << endl;
    InitList(pHead);
    //һ�����ַ���ʹ��ʱ���β��ԣ���Ҫһ�����
    cout << "��ͷ���Ĳ��뷨����:";
    ListTraverse(Insert_ListReverse(pHead));         //��ͷ�����������ǵݹ�����
    cout << endl << "��ͷ���ķǵݹ�����:";
    ListTraverse(non_recursive_ListReverse(pHead));  //��ͷ�����������ǵݹ�����
    cout << endl << "����ͷ���ĵݹ�����:";
    ListTraverse(recursive_ListReverse(pHead->next));//ȥ��ͷ�����������ݹ�����

    return 0;
}