#include "Manager.h"
#include <fstream>
#include <iomanip>
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
        cout << "文件未初始化或打开失败！" << endl;
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
    // //定义一个结点指针，遍历链表
    // Node* nowNode = nl.getHead();
    // while(nowNode != nullptr){
    //     //调用
    //     nowNode->data.display();
    //     cout << "-----------------------------" << endl;
    //     //下一个结点
    //     nowNode = nowNode->next;
    // }
    nl.display();
}

//筛选展示statistic
void Manager::staDisplay(){
    //读入筛选条件
    string flag;
    int count = 0;
     cout << "请输入筛选条件（性别/年级/院系/专业/班级）：" << endl;
    cin >> flag;
    while(flag.empty() || (flag != "性别" && flag != "年级" && flag != "院系" && flag != "专业" && flag != "班级")){
        cout << "输入错误，请重新输入：";
        cin >> flag;
    }
    string keywords;
    cout << "请输入关键词：";
    cin >> keywords;
    while(keywords.empty()){
        cout << "输入错误，请重新输入：";
        cin >> keywords;
    }
    //定义一个结点指针，遍历链表
    Node* nowNode = nl.getHead();
    while(nowNode != nullptr){
        //根据条件筛选并展示
        if( (flag == "性别" && nowNode->data.getSex() == keywords) ||
        (flag == "年级" && nowNode->data.getGrade() == keywords) ||
        (flag == "院系" && nowNode->data.getDepartment() == keywords) ||
        (flag == "专业" && nowNode->data.getMajor() == keywords) || 
        (flag == "班级" && nowNode->data.getClassNum() == keywords)){
            nowNode->data.display();
            count++;
            cout << "-----------------------------" << endl;
        }
        //下一个结点
        nowNode = nowNode->next;
    }
    cout << "以上是与" << flag << "有关的，共统计到" << count << "条有关信息\n";

}

//查询
void Manager::search(){
    int t;
    while(true){
        //分流，模糊查询和精确查询
        cout << "请选择查询方式：\n1. 模糊查询 \n2. 精确查询\n0. 退出" << endl;
        cin >> t;
        //解决随便输入问题
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "输入错误！" << endl;
            continue;
        }
        break;
        
    }
    string keyword;
    bool flag = false;
    //定义一个结点指针，遍历链表
    Node* nowNode = nl.getHead();
        //模糊查询，包含关系
    if(t == 1){
        cout << "请输入查询关键词：" << endl;
        cin >> keyword;
        while(nowNode != nullptr){
            // if(nowNode->data.getName().find(keyword) != string::npos ||
            // nowNode->data.getGrade().find(keyword) != string::npos ||
            // nowNode->data.getDepartment().find(keyword) != string::npos ||
            // nowNode->data.getMajor().find(keyword) != string::npos ||
            // nowNode->data.getClassNum().find(keyword) != string::npos ||
            // nowNode->data.getAddress().find(keyword) != string::npos ||
            // nowNode->data.getCompany().find(keyword) != string::npos ||
            // nowNode->data.getPhone().find(keyword) != string::npos ||
            // nowNode->data.getQQ().find(keyword) != string::npos ||
            // nowNode->data.getEmail().find(keyword) != string::npos){
            //     nowNode->data.display();
            if(hasa(nowNode->data.getName(),keyword)||
            hasa(nowNode->data.getSex(),keyword)||
            hasa(nowNode->data.getGrade(),keyword)||
            hasa(nowNode->data.getDepartment(),keyword)||
            hasa(nowNode->data.getMajor(),keyword)||
            hasa(nowNode->data.getClassNum(),keyword)||
            hasa(nowNode->data.getAddress(),keyword)||
            hasa(nowNode->data.getCompany(),keyword)||
            hasa(nowNode->data.getPhone(),keyword)||
            hasa(nowNode->data.getQQ(),keyword)||
            hasa(nowNode->data.getEmail(),keyword)){
                flag = true;
                nowNode->data.display();
                cout << "-----------------------------" << endl;
            }
            //下一个结点
            nowNode = nowNode->next;
        }
        if(!flag){
            cout << "未找到符合条件的校友信息！" << endl;
        }
    }else if(t ==2){
        //精确查找，完全匹配
        //输入查询关键词
        cout << "请输入学号或者姓名：" << endl;
        cin >> keyword;
        while(nowNode != nullptr){
            if(nowNode->data.getName() == keyword || nowNode->data.getID() == keyword){
                flag = true;
                nowNode->data.display();
                cout << "-----------------------------" << endl;
            }
            //下一个结点
            nowNode = nowNode->next;
        }
        if(!flag){
            cout << "未找到符合条件的校友信息！" << endl;
        }
    }else if(t ==0){
        return;
    }else{
        cout << "输入错误，请重新选择查询方式！" << endl;
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
            //while(sortNowNd->next != nullptr && cmps(sortNowNd, nowNode)){
            while(sortNowNd->next != nullptr && cmps(sortNowNd->next, nowNode)){
                //如果sort里比nowNode这个结点小，往后srot找，直到不符合的！前一个！
                //sortNowNd后移
                sortNowNd = sortNowNd->next;
            }
            //插入
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
    if(nl.find(cm.getID()) != nullptr){
        cout << "该校友已存在！" << endl;
        return;
    }
    nl.insertCM(cm);
}
//modify函数
void Manager::modify(){
    //
    string targetID;
    cout << "请输入要修改的校友的学号：";
    cin >> targetID;
    while(targetID.empty() || !isNumber(targetID)){
        cout << "错误，请重新输入：";
        cin >> targetID;
    }
    Node* target = nl.find(targetID);
    if(target == nullptr){
        cout << "未找到该校友！\n";
        return;
    }

    cout << "-----------------------------" << endl;
    target->data.display();
    cout << "-----------------------------" << endl;

    nl.deleteCM(targetID);
    cout << "请进行新的信息填写：" << endl;
    add();
}

//删除rmv函数
void Manager::rmv(){
    //定义一个字符串变量，存储要删除的学号
    string targetID;
    cout << "请输入要删除的校友的学号：";
    cin >> targetID;
    while(targetID.empty() || !isNumber(targetID)){
        cout << "错误，请重新输入：";
        cin >> targetID;
    }
    //调用链表的删除函数
    nl.deleteCM(targetID);
}

void Manager::setting(){
    cout << "setting: \n1. 增加校友\n2. 删除校友\n3. 修改校友\n0. back\n";
    
    int a;

    while(true)
    {
        cout << "请选择：";
        cin >> a;
        //解决乱输入
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "输入错误，请重新输入！\n";
            continue;
        }
        switch(a)
        {
            case 1:
                add();
                return;

            case 2:
                rmv();
                return;

            case 3:
                modify();
                return;

            case 0:
                return;

            default:
                cout << "错误，请重新输入！\n";
        }
    }
}

void Manager::slDisplay(){
    char choice;
    while(true){
        cin >> choice;
        //乱输入
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "错误，请重新输入！" << endl;
            continue;
        }
        break;
    }
    if(choice == 'y' || choice == 'Y'){
        if(nl.getHead() == nullptr){return;}
        Node* nowNode = nl.getHead();
        cout << "======================================================================================================================================\n";
        //cout << "|姓名|性别|生日|学号|年级|院系|专业|班级|地址|公司|电话|QQ号|邮箱|\n";
        //后面考虑了对齐，重写
        cout << "|" 
            << left 
            << setw(8) << "姓名" << "|"
            << setw(4) << "性别" << "|" 
            << setw(10) << "生日" << "|" 
            << setw(12) << "学号" << "|" 
            << setw(4) << "届级" << "|" 
            << setw(16) << "院校" << "|" 
            << setw(14) << "专业" << "|" 
            << setw(4) << "班级" << "|" 
            << setw(10) << "现居地址" << "|" 
            << setw(12) << "公司" << "|" 
            << setw(11) << "电话" << "|" 
            << setw(12) << "QQ" << "|" 
            << setw(18) << "邮箱" << "|" << endl;
        cout << "======================================================================================================================================\n";
        while(nowNode != nullptr){
            cout << nowNode->data;
            nowNode = nowNode->next;
        }
    }else if(choice == 'n' || choice == 'N'){
    }else{
        cout << "错误，请重新进入！" << endl;
    }
    return;
}

bool Manager::isNumber(const string& s)
{
    for(char c : s)
        if(!isdigit(c)) return false;

    return true;
}