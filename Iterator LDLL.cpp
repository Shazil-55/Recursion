#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct DNode
{
	T info;
	DNode<T>* next;
	DNode<T>* prev;

	DNode()
	{
		info = 0;
		next = nullptr;
	}
	DNode(T value)
	{
		info = value;
		next = prev = nullptr;
	}

};

template <typename T>
class LDLL
{
	DNode<T>* head; // jo pehle object ko point karay ga
public:

	LDLL()
	{
		head = nullptr;
	}
	~LDLL()
	{
		DNode<T>* p = head;
		DNode<T>* nextNode = p;
		while (p != nullptr)
		{
			nextNode = p->next;
			delete p;
			p = nextNode;
		}
	}
	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (!head)
		{
			head = p;
			return;
		}
		p->next = head;
		head->prev = p;
		head = p;

	

	}
	void insertAtTale(T val)
	{
		DNode<T>* p2 = head;
		DNode<T>* p = new DNode<T>(val);
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
			p->prev = p2;
			p->next = nullptr;
		}
	}

	void insertAfter(T key, T val)
	{
		if (!head)return;
		DNode<T>* p = head;
		DNode<T>* after = head->next;
		while (after != nullptr)
		{
			if (p->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				p->next = x;
				x->prev = p;
				x->next = after;
				after->prev = x;

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
		DNode<T>* p = head->next;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				x->next = p;
				p->prev->next = x;
				x->prev = p->prev;
				p->prev = x;
			}
			p = p->next;
		}

	}
	// REMOVES
	void remove(T key)
	{
		if (!head)return;
		DNode<T>* p = head->next;
		if (head->info == key)
		{
			removeAtHead();
		}
		while (p != nullptr)
		{
			if (p->info == key)
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				return;
			}
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
			DNode<T>* x = head->next;
			delete head;
			head = x;
			return;
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
			DNode<T>* p = head->next;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			
			p->prev->next = nullptr;
			delete p;
			p = nullptr;
		}

	}

	void removeAfter(T key)
	{
		if (!head || head->next == nullptr)return;
		DNode <T>* after = head->next;
		DNode <T>* p = head;
		while (p->next != nullptr)
		{
			if (p->info == key && after->next == nullptr)
			{
				removeAtTale();
				return;
			}
			if (p->info == key && after->next != nullptr)
			{
				DNode <T>* temp = p->next;
				p->next = after->next;
				after->next->prev = p;
				after = after->next;
				delete temp;
			}
			if (after != nullptr)
			{
				p = p->next;
				after = p->next;
			}
		}
	}
	void removeBefore(T key)
	{
		if (!head)return;
		DNode <T>* p = head->next->next;
		if (p->prev->info == key)removeAtHead();
		while (p->next != nullptr)
		{
			if (p->info == key)
			{
				DNode <T>* temp = p->prev;
				p->prev-> prev->next = p;
				p->prev = p->prev->prev;
				delete temp;
			}
				p = p->next;			
		}
	}
   
	void display()
	{
		DNode <T>* p = head;

		while (p != nullptr)
		{
			cout << " " << p->info;
			p = p->next;
		}
	}
	

	class Iterator
	{
		friend class LDLL<T>;
		DNode<T>* pointer;
		Iterator(DNode<T>* curr)
		{
			pointer = curr;
		}
	public:
		const Iterator& operator ++ ()
		{
			if (!pointer)exit(0);
			pointer = pointer->next;
			return*this;
		}
		const Iterator& operator -- ()
		{
			if (!pointer)exit(0);
			pointer = pointer->prev;
			return*this;
		}
		T& operator *();

		bool operator !=(const Iterator& rhs)
		{
			return pointer != rhs.pointer;
		}

	};
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}


};

//int main()
//{
//	LDLL<int> l;
//	for (int i = 0; i < 5; i++)
//	{
//		l.insertAtHead(i);
//	}
//	// How ton access iterator? or how to make its nested classs obj 
//
//	LDLL<int>::Iterator obj = l.begin();;
//	cout << *obj;
//	++obj;
//	cout << *obj;
//	--obj;
//	cout << *obj;
//
//}


// wese hi bahir likha takay yaad rahay kese likhtayy
template<typename T>
T& LDLL<T>::Iterator::operator * ()
{
	if (pointer == nullptr)exit(0);
	return pointer->info;
}

