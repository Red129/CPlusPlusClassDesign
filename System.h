// 系统类

#ifndef SYSTEM_H
#define SYSTEM_H

#include "Manager.h"

class System{
	private:
		//实现调用
		Manager manager;
	public:
		//展示出菜单页面，负责输入，输出，入口和出口
		void menu();

};

#endif
