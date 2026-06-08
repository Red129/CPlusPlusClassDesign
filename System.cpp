#include "System.h"
#include <iomanip>
//系统类，负责输出输入等的UI界面

//构造
System::System(){
    manager.fromFile();
}
void System::premenu(){
    cout << "\n================================================================================\n";
    cout << endl;
    cout << "********************************************************************************\n";
    cout << center("Welcom ! 欢迎使用校友录管理系统" , 80)<< endl;
    cout << "********************************************************************************" << endl;
    cout << "\n================================================================================\n";
    cout << endl;
    //进行登陆
    login();
    pause();
}

void System::menu(){

    cout << "\n================================================================================\n";
    cout << endl;
    cout << "\033[36m";
    cout << center("校友录管理系统", 80) << endl;
    cout << "\033[0m";
    cout << "\n================================================================================\n";

    cout << "\033[36m";
    cout << "请选择要进行的操作：" << endl;
    cout << "退出请输入exit/EXIT" << endl;
    cout << "\033[0m";
    cout << endl;

    cout << "-------------------------------------------" << endl;
    cout << "|1. 查询                                  |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|2. 设置                                  |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|3. 查看                                  |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|4. 排序                                  |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|5. 筛选统计                              |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|6. 保存                                  |" << endl;
    cout << "-------------------------------------------" << endl;

    cout << "\033[36m";
    cout << "|7. more about 我                         |" << endl;
    cout << "\033[0m";
    cout << "-------------------------------------------" << endl;	

    cout << "\n================================================================================\n";
    cout << endl;
}

void System::run(){
        string sInput;//stringInput
    do{
        menu();
        cout << "请选择：";

        cin >> sInput;

        if(sInput == "exit" || sInput =="EXIT"){
            manager.saveToFile();
            cout << "已自动保存。。。。。。" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "感谢使用，Goodbye！" << endl;
            cout << "-------------------------------------------" << endl;
            cout << endl;
            cout << "\n================================================================================\n";
            cout << endl;
            cout << "\033[36m";
            cout << center("Incase I don't see you, good afternoon, good evening, and good night !",80) << endl;
            cout << right << setw(80) << "RED.";
            cout << "\033[0m";
            cout << "\n================================================================================\n";
            cout << endl;
            pause();
		return;
        }else if(isNum(sInput)){
            int choice = stringToInt(sInput);

            switch(choice){
                case 1://查询
                    manager.search();
                    pause();
                    break;
                case 2://设置
                    if(getRole() == 1){
                        manager.modify();
                        cout << "Finished!" << endl;
                    }else if(getRole() == 0){
                        cout << "你无权使用该功能！";
                    }
                    pause();
                    break;
                case 3://查看
                    cout << "===========================================\n";
                    cout << "正在查看所有校友信息。。。。。。" << endl;
                    cout << "===========================================\n";
                    manager.displayAll();
                    cout << "Finished!" << endl;
                    pause();
                    break;
                case 4://排序
                    cout << "============================================\n";
                    cout << "排序（按届级及姓名排序）" << endl;
                    cout << "============================================\n";
                    cout << "是否需要展示排序前结果？（y/n）" << endl;
                    manager.slDisplay();
                    manager.slsort();
                    cout << "Finished!是否需要展示排序后结果？（y/n）" << endl;
                    manager.slDisplay();
                    cout << "已按届级和姓名排序。\n";
                    pause();
                    break;
                case 5://筛选统计
                    manager.staDisplay();
                    pause();
                    break;
                case 6://保存
                    manager.saveToFile();
                    cout << "Finished!" << endl;
                    pause();
                    break;

                case 7://我
                    cout << "我的Github账号:Red129，https://github.com/Red129，\n欢迎follow，一个普普通通有点笨的大学生\n";
                    break;
                default:
                    cout << "输入错误，请重新输入！" << endl;
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
    if(isdigit(s[0]) && s.size() == 1){
        flag = true;
    }
    return flag;
}

int System::stringToInt(const string& s){
    //转为数字int
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

//pause
void System::pause(){
    cout << "按任意键以继续。。。。" << endl;
    cin.ignore();//防止前面的输入有\n换行符残留
    cin.get();
}

//center()
string System::center(const string& s, int width){
    if(s.size() >= width){return s;}
    int left = (width - s.size())/2;
    int right = width - s.size() - left;
    return string(left, ' ') + s + string(right, ' ');
}


//登录
void System::login(){
    cout << endl;
    cout << "请选择登录身份：" << endl;

    cout << "-------------------------------------------" << endl;
    cout << "|1. 管理员" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|0. 普通用户" << endl;
    cout << "-------------------------------------------" << endl;

    int choice;
    while(true){
        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "输入错误，请重新输入！" << endl;
            continue;
        }
        break;
    }
    if(choice == 1){
        cout << "用户：root，请输入密码：";
        string password;
        int PWcount = 5;//5次机会

        while(PWcount--){
            cin >> password;

            if(password == getSPW()){
                setRole(1);
                cout << "root用户登录成功，你可以使用所有功能！" << endl;
                return;
            }else{
                cout << "密码错误，重新输入，还有" << PWcount << "次机会！"<< endl;
            }
        }
        cout << "登录失败，已切换为普通用户!" << endl;
        setRole(0);
        
    }else if(choice == 0){
        setRole(0);
        cout << "普通用户登录成功！您不能使用设置功能。" << endl;
    }

}