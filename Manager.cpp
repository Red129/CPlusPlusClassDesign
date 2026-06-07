#include "Manager.h"
#include <fstream>
//管理类

Manager::Manager(){}
Manager::~Manager(){}

//文件流相关
void Manager::saveToFile(){
    //文件流对象
    ofstream fout("classFriends.txt");
    //判断文件是否成功打开
    if(!fout){
        cout << "文件打开失败！" << endl;
        return;
    }
    //定义一个结点指针，遍历链表
    Node* nowNode = nl.getHead();
    while(nowNode != nullptr){
        //将结点中的数据转换为统一形式的字符串，并写入文件
        fout << nowNode->data.toStringLine() << endl;
        //下一个结点
        nowNode = nowNode->next;
    }
    //关闭文件流
    fout.close();
}

//从文件读取
void Manager::fromFile(){
    //文件流对象
    ifstream fin("classFriends.txt");
    //判断文件是否成功打开
    if(!fin){
        cout << "文件打开失败！" << endl;
        return;
    }
    string line;
    //逐行读取文件内容
    while(getline(fin, line)){
        //定义一个临时的ClassFriendCollection对象
        ClassFriendCollection cm;
        //从统一形式的字符串提取数据到对象中
        cm.fromStringLine(line);
        //将对象插入链表
        nl.insertCM(cm);
    }
    //关闭文件流
    fin.close();
}

//display
void Manager::displayAll(){
    //定义一个结点指针，遍历链表
    Node* nowNode = nl.getHead();
    while(nowNode != nullptr){
        //调用
        nowNode->data.display();
        cout << "-----------------------------" << endl;
        //下一个结点
        nowNode = nowNode->next;
    }
}

//筛选展示statistic
void Manager::staDisplay(){
    //读入筛选条件
    string flag;
    int count = 0;
    cout << "请输入筛选条件（年级/院系/专业/班级）：" << endl;
    while(cin >> flag){
        //定义一个结点指针，遍历链表
        Node* nowNode = nl.getHead();
        while(nowNode != nullptr){
            //根据条件筛选并展示
            if((flag == "年级" && nowNode->data.getGrade() == flag) ||
            (flag == "院系" && nowNode->data.getDepartment() == flag) ||
            (flag == "专业" && nowNode->data.getMajor() == flag) || 
            (flag == "班级" && nowNode->data.getClassNum() == flag)){
                nowNode->data.display();
                count++;
                cout << "-----------------------------" << endl;
            }
            //下一个结点
            nowNode = nowNode->next;
        }
        cout << "以上是与" << flag << "有关的，共查找到" << count << "条有关信息\n";
    }
}

//查询
void Manager::search(){
    //分流，模糊查询和精确查询
    int t;
    cout << "请选择查询方式：1.模糊查询 2.精确查询" << endl;
    cin >> t;
    string keyword;
    
    //定义一个结点指针，遍历链表
    Node* nowNode = nl.getHead();
    while(nowNode != nullptr){
        //模糊查询，包含关系
        if(t == 1){
            cout << "请输入查询关键词：" << endl;
            cin >> keyword;
            if(nowNode->data.getName().find(keyword) != string::npos ||
               nowNode->data.getGrade().find(keyword) != string::npos ||
               nowNode->data.getDepartment().find(keyword) != string::npos ||
               nowNode->data.getMajor().find(keyword) != string::npos ||
               nowNode->data.getClassNum().find(keyword) != string::npos ||
               nowNode->data.getAddress().find(keyword) != string::npos ||
               nowNode->data.getCompany().find(keyword) != string::npos ||
               nowNode->data.getPhone().find(keyword) != string::npos ||
               nowNode->data.getQQ().find(keyword) != string::npos ||
               nowNode->data.getEmail().find(keyword) != string::npos){
                nowNode->data.display();
                cout << "-----------------------------" << endl;
            }
        }else if(t ==2){
            //精确查找，完全匹配
            //输入查询关键词
            cout << "请输入学号或者姓名：" << endl;
            cin >> keyword;
            if(nowNode->data.getName() == keyword || nowNode->data.getID() == keyword){
                nowNode->data.display();
                cout << "-----------------------------" << endl;
            }
        }
    }
}

//sort，插入排序
//compare函数
bool Manager::cmps(const Node* a,const Node* b){
    if(a->data.getGrade() < b->data.getGrade()){
        return true;
    }else if(a->data.getGrade() == b->data.getGrade()){
        if(a->data.getName() < b->data.getName()){
            return true;
        }else {return false;}
    }else {return false;}
}

void Manager::slsort(){
    if(nl.getHead() == nullptr || nl.getHead()->next == nullptr){return;}
    Node* sorted = nullptr;//已经有序的链表头指针，插入点
    Node* nowNode = nl.getHead();
    while(nowNode != nullptr){
        //进行排序
        Node* tempNext = nowNode->next;
        //比较当前与下一个，还有sorted为空的情况
        if(sorted == nullptr || cmps(nowNode,sorted)){
                //交换传递
                nowNode->next = sorted;
                sorted = nowNode;
        }
        //在已经排序的进行比较
        else{
            //定义一个进入循环遍历的sorted链表
            Node* sortNowNd = sorted;
            //遍历比较已经排序的，进行插入
            //从第二个开始
            while(sortNowNd->next != nullptr && cmps(sortNowNd, nowNode)){
                //如果sort里比nowNode这个结点小，往后srot找，直到不符合
                //sortNowNd后移
                sortNowNd = sortNowNd->next;
            }
            //把nowNode后面和刚好大于的接上
            nowNode->next = sortNowNd->next;
            //再将这段拼进小的后面
            sortNowNd->next = nowNode;
        }
        //进入下一轮比较
        nowNode = tempNext;
    }
    //将sorted变为新的头结点
    //需要接口，sethead
    nl.setHead(sorted);
}

//add函数
void Manager::add(){
    ClassFriendCollection cm;
    cm.input();
    nl.insertCM(cm);
}

//删除rmv函数
void Manager::rmv(){
    //定义一个字符串变量，存储要删除的姓名
    string targetName;
    cin >> targetName;
    //调用链表的删除函数
    nl.deleteCM(targetName);
}

void Manager::modify(){
    cout << "setting: \n
    1. 增加校友\n
    2. 删除校友\n
    0. back\n";
    cout << "请选择："；
    int a;
    
    while(cin >> a){
        if(a == 1){
            add();
        }else if(a == 2){
            rmv();
        }else if(a == 0){
            return;
        }else{
            cout << "错误，请重新输入！\n";
            continue;
        }
    }
}