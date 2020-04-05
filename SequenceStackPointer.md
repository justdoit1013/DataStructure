```
/**
* 2020.3.23
* 顺序栈指针实现——主要函数
* 1.初始化
* 2.栈入、栈出
* 3.获取栈长度
* 4.获取栈顶元素
* 5.判空
*/
#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define Status int

typedef struct SElemType {//栈中结点类型
	Status value;
};
typedef struct Stack {	 //栈中整体结构：指针表示
	SElemType* base;
	SElemType* top;
	int stacksize;
};
Stack S; //若此处是Stack* S,则以下Stack& -> Stack*,且所有S. -> S->

Status InitStack(Stack& S);

Status Push(Stack& S, int e);
Status Pop(Stack& S);

Status GetTop(Stack& S);
Status StackLength(Stack& S);
Status StackIsEmpty(Stack& S);
Status StackTraverse(Stack& S);
Status DestroyStack(Stack& S);

//栈初始化
Status InitStack(Stack& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}

//栈入
Status Push(Stack& S, int e) {

	if (S.top - S.base == STACK_INIT_SIZE) {//扩容
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * (sizeof(SElemType)));
		if (!S.base)	exit(OVERFLOW);
		S.stacksize = S.stacksize + STACKINCREMENT;
		S.top = S.base + S.stacksize;
	}
	S.top->value = e;
	S.top++;
	return 1;
}
//栈出
Status Pop(Stack& S) {
	if (S.top != S.base)
	{
		S.top--;
		return 1;
	}
	else return 0;
}

//取栈顶
Status GetTop(Stack& S) {
	if (S.base == S.top)	return 0;
	else return (S.top - 1)->value;//因为top指向的最后一个空的位置,实际数据在前一个
}

//栈打印
Status StackTraverse(Stack& S) {
	SElemType* p = S.base;
	cout << "栈中元素：";
	while (p < S.top) {
		cout << p->value << " ";
		p++;
	}
	return 1;
}

//栈长度
Status StackLength(Stack& S)
{
	return S.top - S.base;
}

//栈空
Status StackIsEmpty(Stack& S) {
	if (S.base == S.top)
		return 1;
	else return 0;
}

//销毁
Status DestroyStack(Stack& S) {
	while (S.base != S.top) {
		free(S.top);
	}
	return 1;
}

int main() {
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	StackTraverse(S);
	cout << endl;
	Pop(S);
	StackTraverse(S);
	cout << endl << "栈顶元素：" <<GetTop(S) << " ";
	cout << "栈长度：" << StackLength(S) << endl;
	return 0;
}
```
