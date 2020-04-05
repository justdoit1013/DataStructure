```
/**
* 2020.3.27
* 顺序栈数组实现——主要函数
* 1.初始化
* 2.栈入、栈出
* 3.获取栈长度
* 4.获取栈顶元素
* 5.判空
* 6.打印
*/
/**
注意：此处的Push和Pop函数中的S.top
是先加后移动还是先移动后加，是看S.top赋予的初值，在指针中即初始指向
这里需要注意。做题时需要灵活
*/
#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define SElemType int
#define STACK_INIT_SIZE 10
#define Status int
#define true 1
#define false 0

struct Stack {
	SElemType data[STACK_INIT_SIZE];//数组
	SElemType top;//栈顶
};
Stack S;

Status InitStack(Stack& S) {
	S.top = -1;
	return true;
}
//判空
bool StackEmpty(Stack S) {
	if (S.top == -1)
		return true;
	else return false;
}

Status Push(Stack& S, SElemType e) {
	if (S.top == STACK_INIT_SIZE-1)//边界判断
		return false;
	//S.top = S.top++;
	S.data[++S.top] = e;//指针先加1，再入栈，栈指向最后一个值
	return true;
}

Status Pop(Stack& S, SElemType& e) {
	if (S.top == -1)//边界判断
		return false;
	e = S.data[S.top--];//先出栈，指针再减1，栈指向最后一个值
	return true;
}

Status getTop(Stack S,SElemType& e) {
	if (S.top == -1)
		return false;
	else e = S.data[S.top];
	return true;
}

Status Traverse(Stack S) {
	while (S.top != -1) {
		cout << S.data[S.top] << " ";
		S.top--;
	}
	return true;
}

//InitStack、Push和Pop函数的参数中，得接收地址 & 或者结构体变量的引用

int  main() {
	int value;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	cout << S.top << endl;
	//获取栈顶
	getTop(S, value);
	cout << "栈顶元素为:" << value << endl;
	//栈中元素遍历
	cout << "栈中数值为:";
	Traverse(S);
	cout << endl;

	Pop(S, value);
	Pop(S, value);
	Pop(S, value);
	Pop(S, value);
	//栈空判断
	cout << "栈为空吗？1是/0否：" << StackEmpty(S) << endl;
	
	return 0;
}
```
