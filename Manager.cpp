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
        fout << nowNode -> data.toStringLine() << endl;
        //下一个结点
        nowNode = nowNode -> next;
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
        nowNode -> data.display();
        cout << "-----------------------------" << endl;
        //下一个结点
        nowNode = nowNode -> next;
    }
}

//筛选展示statistic
void Manager::staDisplay(){
    //读入筛选条件
    string flag;
    cout << "请输入筛选条件（年级/院系/专业/班级）：" << endl;
    cin >> flag;
    //定义一个结点指针，遍历链表
    Node* nowNode = nl.getHead();
    while(nowNode != nullptr){
        //根据条件筛选并展示
        if((flag == "年级" && nowNode->data.getGrade() == flag) ||
           (flag == "院系" && nowNode->data.getDepartment() == flag) ||
           (flag == "专业" && nowNode->data.getMajor() == flag) || 
           (flag == "班级" && nowNode->data.getClassNum() == flag)){
            nowNode -> data.display();
            cout << "-----------------------------" << endl;
        }
        //下一个结点
        nowNode = nowNode -> next;
    }
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
