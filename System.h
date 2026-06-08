// 系统类

#ifndef SYSTEM_H
#define SYSTEM_H

#include "Manager.h"

class System{
	private:
		//实现调用
		Manager manager;
		int role;
		string sudopassword = "123456";
		
	public:
		System();
		//展示出菜单页面，负责输入，输出，入口和出口
		void menu();
		
		void run();
		bool isNum(const string& s);
		int stringToInt(const string& s);
		void pause();//为了有更好的交互体验，
		//发现在进行操作后直接跳转到了菜单
		//更好的视觉体验
		string center(const string& s, int width);
		//开始与登录有关
		void premenu();
		void login();
		string getSPW(){return sudopassword;}
		void setRole(int a){role = a;}
		int getRole(){return role;}
};

// class User{
// 	private:
// 		string username;
// 		string sudopassword = "123456";
// 		int role;
// 		//0user,1是管理员root
// 	public:
// 		void login();
// 		void signup();
// 		int setRole(int a){role = a;}
// 		string getSPW(){return sudopassword;}
// };

#endif
	