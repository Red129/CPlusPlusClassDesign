// 链表类  ，CM --> 同学的缩写

#ifndef NODELIST_H
#define NODELIST_H

#include "Node.h"

class NodeList{
	private:
		//头部指针
		Node* head;
	public:
		//构造，析构函数
		NodeList();
		~NodeList();

		// //排序
		// void nodeSort();
		//破坏了链表类只负责接删查找节点的结构
		//移动至manager

		//增删查现函数
		//const 传递防止修改参数
		void insertCM(const ClassFriendCollection& cm);
		void deleteCM(const string& name);

		Node* find(const string& name) const;

		void display();

		//接口
		Node* getHead() const { return head; }

};


#endif
