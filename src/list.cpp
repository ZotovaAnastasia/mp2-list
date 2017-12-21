#include "list.h"

#include "list.h"

Node::Node()
{
	data = NULL;
	next = NULL;
}

Node::Node(DataType d, Node *n)
{
	data = d;
	next = n;
}

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}

Node Node::operator=(const Node& node2)
{
	data = node2.data;
	next = node2.next;
	return *this;
}

bool Node::operator==(const Node& node2) const
{
	int flag = 0;
	if ((data != node2.data) || (next != node2.next))
		flag = 1;
	if (flag = 0)
		return true;
	else return false;
}

List::List(const List& list2)
{
	if (list2.head != NULL)
	{
		head = new Node(list2.head->data, list2.head->next);
		Node* tmp = head;
		while (tmp->next != NULL)
		{
			tmp->next = new Node(tmp->data, tmp->next);
			tmp = tmp->next;
		}
	}
	else head = NULL;
}

List& List::operator=(const List& list2)
{
	if (head != list2.head)
	{
		if (list2.head == NULL)
		{
			head = list2.head;
			return *this;
		}
		else
		{
			this->Clean();
			Node *prev = head;
			Node *tmp = list2.head;
			while (tmp != NULL)
			{
				prev = new Node(tmp->data, tmp->next);
				prev = prev->next;
				tmp = tmp->next;
			}
		}
	}
	return *this;
}

void List::InsertToHead(const DataType & d)
{
	Node *tmp = new Node(d, head);
	head = tmp;
}

void List::InsertToTail(const DataType& d)
{
	Node *tmp = head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new Node(d, NULL);
	}
	else
		head = new Node(d, NULL);
}


void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
{
	if (head != NULL)
	{
		Node *tmp;
		tmp = new Node(d, node->next);
		node->next = tmp;
	}
	else
		throw "Error";
};

void List::Delete(const DataType & d)
{
	Node *tmp = head;
	Node *prev;
	if (head)
	{
		if (head->data == d)
		{
			prev = tmp->next;
			delete head;
			head = prev;
		}
		else
		{
			while (tmp->next)
			{
				if (tmp->next->data == d)
				{
					prev = tmp->next;
					break;
				}
				tmp = tmp->next;
			}
			if (tmp->next)
			{
				tmp->next = prev->next;
				delete prev;
			}
		}
	}
}

Node* List::Search(const DataType& d)
{
	Node *tmp = head;
	while (tmp)
	{
		if (tmp->data == d)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void List::Del()
{
	Node *tmp = head;
	while (tmp->next != NULL)
	{
		Node * prev = tmp->next;
		delete tmp;
		tmp = prev;
	}
}

void List::Clean()
{
	Node *tmp = head;
	Node *p;

	if (tmp != NULL)
	{
		Del();
		delete tmp;
		p = NULL;
	}
}

int List::GetSize()
{
	int p = 0;
	Node *tmp = head;

	while (tmp != NULL)
	{
		p++;
		tmp = tmp->next;
	}

	return p;
}

void List::Inverse()
{
	if (head)
	{Node *prev,*tmp,*next;
	prev = head;
	tmp = head->next;
	prev->next = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	head = prev;
	}
}

List List::Merge(Node* node, const List& list2)
{
	if (head == NULL)
		return list2;
	List list3 = *this;
	Node *prev = list3.head, *n, *tmp = list2.head;
	while (prev != node)
	{
		prev = prev->next;
	}
	n = prev->next;
	while (tmp != NULL)
	{
		prev->next = new Node(tmp->data, tmp->next);
		prev = prev->next;
		tmp = tmp->next;
	}
	prev->next = n;
	return list3;
}

List List::Merge(const List& list2)
{
	if (head == NULL)
		return list2;
	List list3 = *this;
	Node *tmp = list3.head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = list2.head;
	return list3;
}

ostream & operator<<(ostream & os, const List & l)
{
	Node *tmp = l.head;
	while (tmp)
	{
		os << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;
}

bool List::operator==(const List & list2) const
{
	int flag = 0;
	Node *prev = head;
	Node *tmp = list2.head;
	while (prev && tmp && flag)
	{
		if (prev->data != tmp->data)
			flag = 1;
		else
		{
			prev = prev->next;
			tmp = tmp->next;
		}

	}
	if (prev || tmp)
		flag = 0;
	if (flag=0)
		return false;
	else 
		return true;
}