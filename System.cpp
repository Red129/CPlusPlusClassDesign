#include "System.h"
//系统类，负责输出输入等的UI界面

//构造
System::System(){
    manager.fromFile();
}

void System::menu(){
    string sInput;//stringInput
    cout << "***************************************\n";
    cout << "Welcom ! 欢迎使用校友录管理系统" << endl;
    cout << "****************************************" << endl;
    //cout << "请进行登陆" << endl;

    cout << "请选择要进行的操作：" << endl;
    cout << "退出请输入exit" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1. 查询" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "2. 设置" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "3. 查看" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "4. 排序" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "5. 筛选统计" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "6. 保存" << endl;
    cout << "-------------------------------------------" << endl;

    cout << "7. learn more about 我" << endl;
    cout << "-------------------------------------------" << endl;	

    cout << "\n=============================================\n";
    do{
        cout << "请选择：";

        cin >> sInput;

        if(sInput == "exit" || sInput =="EXIT"){
		return;
        }else if(isNum(sInput)){
            int choice = stringToInt(sInput);

            switch(choice){
                case 1://查询
                    manager.search();
                    break;
                case 2://设置
                    manager.modify();
                    break;
                case 3://查看
                    manager.displayAll();
                    break;
                case 4://排序
                    manager.slsort();
                    break;
                case 5://筛选统计
                    manager.staDisplay();
                    break;
                case 6://保存
                    manager.saveToFile();
                    break;

                case 8://我
                    cout << "我的Github:    Red129，欢迎follow，一个普普通通有点笨的大学生\n";
                    break;
            }
        }else{
            cout << "输入错误，请重新输入！" << endl;
        }
    }while(true);
}

//isNum()
bool System::isNum(const string& s){
    bool flag = false;
    //是否只含数字
    if(){
        flag = true;
    }
}

int stringToInt(const string& s){
    //转为数字int
    return ;
}