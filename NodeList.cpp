#include "NodeList.h"

//NodeList类

NodeList::NodeList(){
    head = nullptr;
}
NodeList::~NodeList(){
    //定义一个进入循环的结点
    Node* nowNode = head;
    //遍历判断是否为空，即最后一个
    while(nowNode != nullptr){
        //定义一个临时结点,用来存储要删除的结点
        Node* temp = nowNode;
        //指向下一个结点
        nowNode = nowNode->next;
        //删除结点
        delete temp;
        //head = nullptr;//最后将头结点置空，防止悬空指针
    }
}

//insertCM函数
void NodeList::insertCM(const ClassFriendCollection& cm){
     //定义新结点
    Node* newNode = new Node;
    //现在数据传入新结点
    newNode -> data = cm;
    //判断是否为空链表
    if(head == nullptr){
        head = newNode;
        newNode -> next = nullptr;
    }else{
        //定义一个进入循环的结点
        Node* nowNode = head;
        //遍历找到最后一个结点
        while(nowNode->next != nullptr){
            nowNode = nowNode->next;
        }
        //将新结点连接到最后一个结点
        nowNode->next = newNode;
        newNode->next = nullptr;
    }
}

//find函数
Node* NodeList::find(const string& ID) const{
    //定义一个进入循环的结点
    Node* nowNode = head;
    //遍历判断是否为空，即最后一个
    while(nowNode != nullptr){
        //如果找到了，返回结点指针
        // if(nowNode->data.name == name){
        //错误，name是父类的保护成员，无法直接访问
        if(nowNode->data.getID() == ID){
            return nowNode;
        }
        //指向下一个结点
        nowNode = nowNode->next;
    }
    //没有找到，返回空指针
    return nullptr;
}

//deleteCM函数
void NodeList::deleteCM(const string& ID){
    //调用find函数
    Node* flagNode = find(ID);
    //如果找到了，删除结点
    if(flagNode != nullptr){
        //判断是否是头结点
        if(flagNode == head){
            head = head -> next;
            //释放结点内存，防止内存泄漏
            delete flagNode;
        }else{
            //定义一个进入循环的结点
            Node* nowNode = head;
            //遍历找到要删除结点的前一个结点
            while(nowNode->next != flagNode){
                nowNode = nowNode->next;
            }
            //将前一个结点连接到要删除结点的下一个结点
            nowNode->next = flagNode->next;
            //释放结点内存，防止内存泄漏
            delete flagNode;
        }
    }
}

//display
void NodeList::display(){
    Node* nowNode = head;
    while(nowNode != nullptr){
        //调用CFC的display函数
        nowNode -> data.display();
        cout << "-----------------------------" << endl;
        //指向下一个结点
        nowNode = nowNode -> next;
    }
}