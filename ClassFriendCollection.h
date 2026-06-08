//校友类

#ifndef CLASSFRIENDCOLLECTION_H
#define CLASSFRIENDCOLLECTION_H

#include "Person.h"

class ClassFriendCollection : public Person {
	private:
		//学生信息
		string ID;
		string grade;
		string department;
		string major;
		string classNum;

		//工作信息
		string address;
		string company;

		//联系方式
		string phone;
		string qq;
		string email;

	public:
		//构造函数
		ClassFriendCollection();
		// ClassFriendCollection(const string& n, const string& s, const string& b,
		// 	const string& g, const string& d, const string& m, const string& c,
		// 	const string& a, const string& co, 
		// 	const string& p, const string& q, const string& e);
		~ClassFriendCollection();

		// 设置输入
		void input();
	
		//检查联系方式
		bool isNumber(const string& s);
		void checkGr();
		void checkCN();
		void checkPhone();
		void checkQQ();
		void checkEmail();
		void checkID();

		// 输出展示
		void display();

		// 保存为统一形式
		string toStringLine();

		// 从统一形式提取
		void fromStringLine(string line);

		//接口函数，提供访问权限
		string getGrade() const { return grade; }
		string getDepartment() const { return department; }
		string getMajor() const { return major; }
		string getClassNum() const { return classNum; }
		string getAddress() const { return address; }
		string getCompany() const { return company; }
		string getPhone() const { return phone; }
		string getQQ() const { return qq; }
		string getEmail() const { return email; }
		string getID() const { return ID; }
};


#endif
