// List.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Node.h"
#include "List.h"
#include <iostream>

using namespace std;

int menu()
{
	cout << "���ܲ˵�" << endl;
	cout << "1 �½���ϵ��" << endl;
	cout << "2 ɾ����ϵ��" << endl;
	cout << "3 ���ͨѶ¼" << endl;
	cout << "4 �˳�ͨѶ¼" << endl;
	cout << "�����룺";
	int order = 0;
	cin >> order;
	return order;
}

void creatperson(List *pList)
{
	Node node;
	Person person;
	cout << "�����û�������";
	cin >> person.name;
	cout << "����绰���룺";
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

