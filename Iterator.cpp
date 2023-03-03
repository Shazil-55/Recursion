#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T info;
	Node<T>* next;

	Node()
	{
		info = 0;
		next = nullptr;
	}
	Node(T value)
	{
		info = value;
		next = nullptr;
	}

};

template <typename T>
class LSLL
{
	Node<T>* head; // jo pehle object ko point karay ga
public:

	

	LSLL()
	{
		head = nullptr;
	}
	void insertAtHead(T val)
	{
		Node<T>* p = new Node<T>(val);
		p->next = head;
		head = p;
	}
	void insertAtTale(T val)
	{
		Node<T>* p2 = head;
		Node<T>* p = new Node<T>(val);
		if (head == nullptr)
		{
			insertAtHead(val);
		}
		else
		{
			while (p2->next != nullptr)
			{
				p2 = p2->next;
			}
			p2->next = p;
			p->next = nullptr;
		}
	}

	void insertAfter(T key, T val)
	{
		if (!head)return;
		Node<T>* p = head;
		Node<T>* after = head->next;
		while (after != nullptr)
		{
			if (p->info == key)
			{
				Node<T>* x = new Node<T>(val);
				p->next = x;
				x->next = after;

			}
			p = p->next;
			after = after->next;
		}


	}
	void insertBefore(T key, T val)
	{
		if (!head)return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		Node<T>* prev = head;
		Node<T>* p = head->next;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				Node<T>* x = new Node<T>(val);
				x->next = p;
				prev->next = x;
			}
			prev = p;
			p = p->next;
		}

	}
	// REMOVES
	void remove(T key)
	{
		if (!head)return;
		Node<T>* p = head->next;
		Node<T>* prev = head;
		if (head->info == key)
		{
			Node<T>* x = head->next;
			delete head;
			head = x;
			return;
		}
		while (p != nullptr)
		{
			if (p->info == key)
			{
				prev->next = p->next;
				delete p;
				return;
			}
			prev = p;
			p = p->next;

		}
	}
	void removeAtHead()
	{
		if (!head)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T>* p = head->next;
			delete head;
			head = p;
		}
	}
	void removeAtTale()
	{
		if (!head)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T>* p = head->next;
			Node<T>* prev = head;
			while (p != nullptr)
			{
				if (p->next == nullptr)
				{

					delete p;
					p = nullptr;
					prev->next = nullptr;
					break;
				}
				prev = prev->next;
				p = p->next;
			}
		}

	}

	void removeAfter(T key)
	{
		if (!head || head->next == nullptr)return;
		Node <T>* after = head->next;
		Node <T>* p = head;
		while (p->next != nullptr)
		{
			if (p->info == key && after == nullptr)return;
			if (p->info == key && after->next == nullptr)
			{
				removeAtTale();
				return;
			}
			if (p->info == key && after->next != nullptr)
			{
				Node <T>* temp = p->next;
				p->next = after->next;
				after = after->next;
				delete temp;
			}
			if (after != nullptr)
			{
				p = p->next;
				after = after->next;
			}
		}
	}
	void removeBefore(T key)
	{
		if (!head)return;
		Node <T>* p = head->next->next;
		Node <T>* before = head;
		if (before->next->info == key)removeAtHead();
		while (p->next != nullptr)
		{
			int count = 0;

			if (p->info == key)
			{
				Node <T>* temp = before->next;
				before->next = p;
				p = p->next;
				delete temp;
				count++;
			}
			if (count == 0)
			{
				p = p->next;
				before = before->next;
			}
		}
	}
	void display()
	{
		Node <T>* p = head;

		while (p != nullptr)
		{
			cout << " " << p->info;
			p = p->next;
		}
	}

	class Iterator2
	{
		friend class LSLL<T>;
		Node<T>* pointer;
		Iterator2(Node<T>* curr)
		{
			pointer = curr;
		}
	public:
		const Iterator2& operator ++ ()
		{
			if (!pointer)exit(0);
			pointer = pointer->next;
			return*this;
		}
		T& operator *();

		bool operator !=(const Iterator2& rhs)
		{
			return pointer != rhs.pointer;
		}

	};
	Iterator2 begin()
	{
		return Iterator2(head);
	}
	Iterator2 end()
	{
		return Iterator2(nullptr);
	}

};
#include<vector>
int main()
{

	vector<int> v = { 100,2,4,5 };
	vector<int>::iterator it = v.begin(); 
	cout << *it<< endl  ;
	it.operator++();
	cout << *it << endl;

	LSLL<int> l;
	for (int i = 0; i < 5; i++)
	{
		l.insertAtHead(i);
	}
	// How ton access iterator? or how to make its nested classs obj 

	LSLL<int>::Iterator2 obj = l.begin();;
	cout << *obj;
	++obj;
	cout << *obj;
	obj = l.end();
	cout << *obj;

}


// wese hi bahir likha takay yaad rahay kese likhtayy
template<typename T>
T& LSLL<T>::Iterator2::operator * ()
{
	if (pointer == nullptr)exit(0);
	return pointer->info;
}