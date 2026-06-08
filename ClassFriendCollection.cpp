#include "ClassFriendCollection.h"
#include <sstream>
//写流对象时报错了，忘记加了

//校友录类的实现

//构造函数
ClassFriendCollection::ClassFriendCollection() : Person() {}

//析构函数
ClassFriendCollection::~ClassFriendCollection() {}

//输入
void ClassFriendCollection::input() {
    //调用父类输入函数
    Person::input();

    cout << "请输入学号：";
    cin >> ID;
    checkID();

    cout << "请输入年级：(example:2025)";
    cin >> grade;
    checkGr();

    cout << "请输入院系：";
    cin >> department;
    while(department.empty()){
        cout << "错误，请重新输入：";
        cin >> department;
    }
    cout << "请输入专业：";
    cin >> major;
    while(major.empty()){
        cout << "错误，请重新输入：";
        cin >> major;
    }
    cout << "请输入班级：(example:02)";
    cin >> classNum;
    checkCN();

    cout << "请输入现在的地址：";
    cin >> address;
    while(address.empty()){
        cout << "请重新输入：";
        cin >> address;
    }
    cout << "请输入现在的公司：";
    cin >> company;
    while(company.empty()){
        cout << "请重新输入：";
        cin >> company;
    }

    cout << "请输入联系方式：";
    cin >> phone;
    checkPhone();
    cout << "请输入qq号：";
    cin >> qq;
    checkQQ();
    cout << "请输入邮箱：(example:xxxxxxxx@qq.com)";
    cin >> email;
    checkEmail();
    return;
}

//检查函数
//年级
void ClassFriendCollection::checkGr(){
    while(grade.size() != 4 || !isNumber(grade) ){
        cout << "错误，请重新输入：";
        cin >> grade;
    }
}
//班级
void ClassFriendCollection::checkCN(){
    while(classNum.size() != 2 || !isNumber(classNum)){
        cout <<"错误，请重新输入：";
        cin >> classNum;
    }
}
//Phone
void ClassFriendCollection::checkPhone(){
    while(phone.size() != 11 || !isNumber(phone)){
        cout <<"错误，请重新输入：";
        cin >> phone;
    }
}
//qq
void ClassFriendCollection::checkQQ(){
    while(qq.size() < 5 || qq.size() > 11|| !isNumber(qq)){
        cout <<"错误，请重新输入：";
        cin >> qq;
    }
}
//email
void ClassFriendCollection::checkEmail()
{
    while(true)
    {
        size_t atPos = email.find('@');
        size_t dotPos = email.find('.', atPos);

        if(
            !email.empty() &&          // 非空
            atPos != string::npos &&   // 存在@,即不等于npos
            atPos > 0 &&               // @前有内容
            atPos < email.size()-1 &&  // @后有内容
            dotPos != string::npos &&  // @后存在.
            dotPos < email.size()-1    // .后有内容
        )
        {
            break;
        }

        cout << "邮箱格式错误，请重新输入：";
        cin >> email;
    }
}

void ClassFriendCollection::checkID(){
    while(ID.empty() || !isNumber(ID)){
        cout << "错误，请重新输入：";
        cin >> ID;
    }
}
//检查是否是只含数字
bool ClassFriendCollection::isNumber(const string& s)
{
    for(char ch : s)//遍历读取每一位
    {
        if(!isdigit(ch))//是否是数字
        {
            return false;
        }
    }

    return true;
}
void ClassFriendCollection::display(){
    Person::display();
    cout << "年级：" << grade << endl;
    cout << "院系：" << department << endl;
    cout << "专业：" << major << endl;
    cout << "地址：" << address << endl;
    cout << "公司：" << company << endl;
    cout << "电话：" << phone << endl;
    cout << "QQ号：" << qq << endl;
    cout << "邮箱：" << email << endl;
}

//统一形式
string ClassFriendCollection::toStringLine(){
    return name + "|" + sex + "|" + birthday + "|" + ID + "|"
	    + grade + "|" + department + "|" + major + "|" + classNum + "|"
	    + address + "|" + company + "|"
	    + phone + "|" + qq + "|" + email;
}

//提取统一形式
void ClassFriendCollection::fromStringLine(string line){
    stringstream ss(line);
    //定义一个string流，方便处理
    //学习到的：stringstream 是 C++ 标准库里的一个工具类，
    //用来把字符串当作“流”来处理，
    //可以像操作 cin 或 cout 一样对字符串进行读写。
    //它的作用就是把字符串包装成一个输入/输出流，方便做解析或拼接。
    getline(ss, name, '|');
    getline(ss, sex, '|');
    getline(ss, birthday, '|');
    getline(ss, ID, '|');
    getline(ss, grade, '|');
    getline(ss, department, '|');
    getline(ss, major, '|');
    getline(ss, classNum, '|');
    getline(ss, address, '|');
    getline(ss, company, '|');
    getline(ss, phone, '|');
    getline(ss, qq, '|');
    getline(ss, email, '|');
}

//重载的实现
ostream& operator<<(ostream& out, const ClassFriendCollection& cm){
    cout << "|" << cm.getName() << "|" << cm.getSex() << "|" << cm.getBirthday() << "|" << cm.getID() << 
    "|" << cm.getGrade() << "|" << cm.getDepartment() << "|" << cm.getMajor() << "|" << cm.getClassNum() << "|"
    << cm.getAddress() << "|" << cm.getCompany() << "|" 
    << cm.getPhone() << "|" << cm.getQQ() << "|" << cm.getEmail() << "|" << endl;
    return out;
}