// 基础数据类 -> 链表类 -> 管理系统 -> 读取 -> 菜单
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// 人类

class Person{
	protected:
		string name;
		string sex;
		string birthday;
	public:
	//输入
	virtual void input();
	//输出展示
	virtual void display();
	//信息检查，比如生日年龄是否合理
	void check();
};

//校友类

class ClassFriendCollection : public Person {
	private:
		string grade;
		string department;
		string major;
		string classNum;
		string address;
		string company;
		string phone;
		string qq;
		string email;

	public:
		// 设置输入
		void input();
		// 输出展示
		void display();
		// // 搜索
		// void search();
		// 保存为统一形式
		string toStringLine();
		// 从统一形式提取
		void fromStringLine();
};

//链表

struct Node{
	//数据域,存放数据
	ClassFriendCollection data;
	//指针域,指向下一个节点
	Node* next;
};

// 链表类  ，CM --> 同学的缩写
class NodeList{
	private:
		Node *head;
	public:
	void insertCM();
	void deleteCM();
	void find();
	void display();
};

//管理类

class Manager{
	private:
	NodeList nl;
	public:
	void saveToFile();
	void fromFile();
	void search();
	//包含模糊查询和精确查询

};

// 系统类

class System{
	private:
	Manager manager;
	public:
	void menu();

	//void goodbye();
};