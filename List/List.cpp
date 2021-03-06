#include "stdafx.h"
#include "List.h"
#include "Node.h"

List::List()
{
	m_pList = new Node;
	m_pList->data.name = "*";
	m_pList->data.phone = "0";
	m_pList->next = NULL;
	m_iLength = 0;
}


void List::clearList() //清空除了链表首位置的其余成员,并释放空间
{
	Node *currentNode = m_pList->next;   //保存首节点的下一节点的指针域
	while (currentNode != NULL)    //判断指针域是否为空，如果不为空，则执行清除
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;    //此前并没有将m_pList的下一个节点删除
}


List::~List()
{
	clearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::listEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int List::listLength()
{
	return m_iLength;
}

bool List::getElement(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}

	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;

	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::locateElement(Node *pNode)      //根据输入内容寻找链表节点位置
{
	Node *currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL)      //遍历整个链表，直到等于NULL
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;
}

bool List::priorElement(Node *pCurrentNode, Node *pPreNode)   //取前驱
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while (currentNode->next != NULL)      //遍历整个链表，直到等于NULL
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::nextElement(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while (currentNode->next != NULL)      //遍历整个链表，直到等于NULL
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == NULL)
			{
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

void List::listTraverse()         //打印出整个链表
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}

bool List::listInsert(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;     //原本currentNode的下一节点变为了newNode的下一个节点
	currentNode->next = newNode;           //newNode成为了currentNode的下一节点
	m_iLength++;

	return true;

}

bool List::listDelete(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;

	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;      //取出currentNode的值
	delete currentNode;
	currentNode = NULL;
	m_iLength--;

	return true;

}


bool List::listInsertHead(Node *pNode)    //将一个节点插入到头节点之后
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;

	return true;
}

bool List::listInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)      //遍历整个链表，直到等于NULL
	{
		currentNode = currentNode->next;    
	}
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;        
	newNode->next = NULL;
	currentNode->next = newNode;        //使newNode成为整个链表最后一个节点
	m_iLength++;

	return true;
}