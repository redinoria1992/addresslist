#pragma once
#ifndef NODE_H
#define NODE_H
#include "Person.h"


class Node
{
public:
	Person data;     //������
	Node *next;   //ָ����һ���ڵ�
	void printNode();
};

#endif // !NODE_H

