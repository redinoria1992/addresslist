#pragma once
#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List
{
public:
	List();
	~List();
	void clearList();
	bool listEmpty();
	int listLength();
	bool getElement(int i, Node *pNode);
	int locateElement(Node *pNode);
	bool priorElement(Node *pCurrentNode, Node *pPreNode);
	bool nextElement(Node *pCurrentNode, Node *pNextNode);
	void listTraverse();
	bool listInsert(int i, Node *pNode);
	bool listDelete(int i, Node *pNode);
	bool listInsertHead(Node *pNode);
	bool listInsertTail(Node *pNode);
private:
	Node *m_pList;
	int m_iSize;
	int m_iLength;
 
};
#endif