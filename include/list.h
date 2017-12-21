#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
	DataType data;                                           //данные элемента структуры
	Node *next;												//Указатель для связи между структурами такого же типа
	Node();
	~Node() {}
	Node(DataType d, Node *n);
	Node(const Node& node2);
	Node operator=(const Node& node2);
	bool operator==(const Node& node2) const;
};

class List
{
	Node *head;

public:
	List() { head = NULL; };
	List(const List& list2);
	List& operator=(const List& list2);
	~List() { Clean(); };
	void InsertToHead(const DataType& d);					// вставить элемент d первым
	void InsertToTail(const DataType& d);					// вставить элемент d последним
	void InsertAfter(Node* node, const DataType& d);		// вставить элемент d после звена node
	void Delete(const DataType& d);						// удалить звено со значением data = d
	Node* Search(const DataType& d);						// найти указатель на звено со значением data = d
	void Del();
	void Clean();											// удалить все звенья
	int GetSize();										// узнать число звеньев в списке
	Node* GetHead() { return head; };						// получить указатель на первое звено списка
	void Inverse();										// инвертировать список, т.е. звенья должны идти в обратном порядке
	List Merge(Node* node, const List& list2);			// создать список3, добавив список2 в текущий список после указателя node  
	List Merge(const List& list2);						// создать список3, добавив в конец текущего списка список2
	bool operator==(const List& list2) const;
	friend ostream& operator<<(ostream& os, const List& l);
};

#endif