//管理类

#ifndef MANAGER_H
#define MANAGER_H

#include "NodeList.h"

class Manager{
	private:
		//可以调用
		NodeList nl;
	public:

		Manager();
		~Manager();

		//文件流相关
		void saveToFile();
		void fromFile();

		//展示
		//全展示
		void displayAll();
		//筛选展示statistic
		void staDisplay();

		//查询
		//包含模糊查询和精确查询
		void search();

		//排序stringline
		void slsort();
		//比起来小
		bool cmps(const Node* a, const Node* b);
		
		//增加删除
		void add();
		void rmv();
		void modify();
};


#endif
