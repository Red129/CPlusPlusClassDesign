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
		//展示排序stringLine
		void slDisplay();

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
		void setting();

		//经ai建议，打算使用函数模板简化search（）
		template<typename T>
		//编译时，发生错误，经询问，模板实现也建议写在头文件里，
		//编译器需要生成，但只看见了声明
		bool hasa(const T& zone, const string& keyword){
			return zone.find(keyword) != string::npos;
		}

		bool isNumber(const string& s);
};


#endif
