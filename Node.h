// 链表,  节点
// 能用后改成模板类

#ifndef NODE_H
#define NODE_H

#include "ClassFriendCollection.h"
struct Node{

	//数据域,存放数据
	ClassFriendCollection data;

	//指针域,指向下一个节点
	Node* next;
};

#endif
