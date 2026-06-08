#include "System.h"
//系统类，负责输出输入等的UI界面

//构造
System::System(){
    manager.fromFile();
}

void System::menu(){
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
            cout << "感谢使用，Goodbye！" << endl;
            cout << "Incase I don't see you, good afternoon, good evening, and good night !" << endl;
		return;
        }else if(isNum(sInput)){
            int choice = stringToInt(sInput);

            switch(choice){
                case 1://查询
                    manager.search();
                    pause();
                    break;
                case 2://设置
                    manager.modify();
                    cout << "Finished!" << endl;
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
