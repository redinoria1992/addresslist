#pragma once
#ifndef NODE_H
#define NODE_H
#include "Person.h"


class Node
{
public:
	Person data;     //数据域
	Node *next;   //指向下一个节点
	void printNode();
};

#endif // !NODE_H

