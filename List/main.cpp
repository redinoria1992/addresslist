// List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Node.h"
#include "List.h"
#include <iostream>

using namespace std;

int menu()
{
	cout << "功能菜单" << endl;
	cout << "1 新建联系人" << endl;
	cout << "2 删除联系人" << endl;
	cout << "3 浏览通讯录" << endl;
	cout << "4 退出通讯录" << endl;
	cout << "请输入：";
	int order = 0;
	cin >> order;
	return order;
}

void creatperson(List *pList)
{
	Node node;
	Person person;
	cout << "输入用户姓名：";
	cin >> person.name;
	cout << "输入电话号码：";
	cin >> person.phone;
	node.data = person;
	pList->listInsertTail(&node);


}


int main()
{
	Node node1,node2,node3,node4,node5;
	node1.data.name = "tester1";
	node1.data.phone = "13500328593";
	node2.data.name = "tester2";
	node2.data.phone = "13983061818";


		
	List *pList = new List();

	/*pList->listInsertHead(&node1);
	pList->listInsertHead(&node2);
	pList->listInsertHead(&node3);
	pList->listInsertHead(&node4);*/

	pList->listInsertTail(&node1);
	pList->listInsertTail(&node2);
	
	pList->listTraverse();

	//cout <<"temp = "<< temp.data << endl;
	delete pList;
	pList = NULL;


	system("pause");
	return 0;
}

