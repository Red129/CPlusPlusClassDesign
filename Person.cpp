#include "Person.h"

//构造函数
Person::Person(){
    // name = "";
    // sex = "";
    // birthday = "";
}

//常引用构造函数，保证值不被修改，避免不必要的复制
Person::Person(const string& n, const string& s, const string& b){
    name = n;
    sex = s;
    birthday = b;
}
//析构函数
Person::~Person(){

}

//输入
void Person::input(){

    cout << "请输入姓名：";
    cin >> name;
    checkName();//检查姓名

    cout << "请输入性别：";
    cin >> sex;
    checkSex();//检查性别

    cout << "请输入生日：";
    cin >> birthday;
    checkBirth();//检查生日

}

//输出展示
void Person::display() const {
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "生日(格式: YYYY/MM/DD)：" << birthday << endl;
}
//信息检查
//name
void Person::checkName(){
    //循环检查，以防一直错
    while(name.empty()){
        cout << "输入不能为空，请重新输入" << endl;
        cin >> name;
    }
}

//sex
void Person::checkSex(){
    //性别检查
    while(sex != "男" && sex != "女"){
        cout << "性别输入有误，请重新输入" << endl;
        cin >> sex;
    }
}

//birthday
void Person::checkBirth(){
    while(birthday.size() != 10 || birthday[4] != '/' || birthday[7] != '/'){
        cout << "生日输入有误，格式为YYYY/MM/DD，请重新输入" << endl;
        cin >> birthday;
    }
}

