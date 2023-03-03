#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct Node {
	T info;
	int next;
};

template <typename T>
class Array
{
private:
	Node<T> arr[10];
	int SL;
	int UL;
	int getNewNode()
	{
		int temp = SL;
		SL = arr[SL].next;
		return temp;
	}
	void returnNode(int x)
	{
		arr[x].next = SL;
		SL = x;
	}
public:
	Array()
	{
		int i = 0;
		for (i; i < 9; i++)
		{
			arr[i].next = i + 1;
		}
		arr[i].next = -1;
		SL = 0;
		UL = -1;
	}
	void insertAtTail(T val)
	{
		int x = getNewNode();
		if (UL == -1)
		{
			arr[x].info = val;
			arr[x].next = UL;
			UL = x;
			return;
		}
		int p = UL;
		while (arr[p].next != -1)
		{
			p = arr[p].next;
		}
		arr[p].next = x;
		arr[x].info = val;
		arr[x].next = -1;
	}
	void insertAtHead(T val)
	{
		int x = getNewNode();
		arr[x].info = val;
		arr[x].next = UL;
		UL = x;
	}
	void removeAtHead()
	{
		int x = UL;
		UL = arr[UL].next;
		returnNode(x);
	}
	void removeAtTail()
	{
		if (arr[UL].next == -1)
		{
			int x = UL;
			UL = arr[UL].next;
			returnNode(x);
			return;
		}
		int p = UL;
		int prev = p;
		while (arr[p].next != -1)
		{
			prev = p;
			p = arr[p].next;
		}
		arr[prev].next = -1;
		returnNode(p);
	}
	void print()
	{
		int p = UL;
		while (p != -1)
		{
			cout << arr[p].info << " ";
			p = arr[p].next;
		}
		cout << "UL:" << UL << endl;
		cout << "SL:" << SL << endl;
	}

};

