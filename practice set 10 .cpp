#include<iostream>
#include "Array.h"
using namespace std;

int sumup(int n)
{
	if (n == 1)return 1;
	return n + sumup(n - 1);
}

// 14535
int sum(int n)
{
	if (n / 10 == 0)return n ;

	int index = n % 10; // 5

	return index + sum(n / 10);

}

void printsq(int n)
{
	if (n == 1)
	{
		cout << 1<< " "; return;
	}
	if (n % 2 == 1)
	{
		cout << n * n << " " ;
		printsq(n - 1);
	}

	if (n % 2 == 0)
	{
		printsq(n - 1);
		cout << n * n << " ";

	}

}

int printDigits(int n)
{
	// 8342116
	if (n / 10 == 0)
	{
		if (n % 2 == 0) {
			cout << n; return n;
		}
		return 0;
	}
		int index = n % 10; // 6
		if (index % 2 == 0)
		{
			
			
			 printDigits(n / 10);
			cout << index;
		}
		else
		{
			printDigits(n / 10);
		}

	//if (n / 10 == 0) {
	//	if (n % 2 == 0)return n;
	//}

	//	int index = n % 10; // 5
	//	if (index % 2 == 0)
	//	{
	//		return index * 10 + sum(n / 10);
	//	}
}



//
//int main()
//{
//	Array<int> obj;
//	obj.insertAtHead(5);
//	obj.insertAtHead(15);
//	obj.insertAtHead(25);
//	obj.insertAtHead(35);
//	obj.print();
//}