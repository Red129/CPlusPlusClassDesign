//人类的声明


//分文件的头文件保护

#ifndef PERSON_H

#define PERSON_H

#include <iostream>
#include <string>

using namespace std;
//
//头文件相关结束

//人，类声明
class Person
{
	protected:
		string name;
		string sex;
		string birthday;

	public:
		//构造函数
		Person();
		//重载构造函数，常引用，避免不必要的复制
		Person(const string& n, const string& s, const string& b);
		virtual ~Person();

		//输入
		virtual void input();

		//输出展示
		virtual void display() const;

		//信息检查，比如生日年龄是否合理
		void checkName();
		void checkSex();
		void checkBirth();

		//防止调用成员受限，提供访问接口
		string getName() const { return name; }
		string getSex() const { return sex; }
		string getBirthday() const { return birthday; }
};


#endif
