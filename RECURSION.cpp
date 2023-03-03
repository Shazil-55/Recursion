#include <iostream>
using namespace std;


// sum of an array
int f2(int* p, int n)
{
	if (n <= 0)return 0;
	if (n == 1)return p[0];
	return p[n - 1] + f2(p, n - 1);
}



// question home work
int f(int n) 
{
	if (n <= 1)return n;
	int s = 0;
	n = n - 1;
	for (int i = 1; i <= n; i++)
	{
		s += f(n);
		cout << " s " << s;
	}
	cout << " n : " << n<<endl;
	return s + 1;
}

int o(int n)
{
	int s = 0;
	if (n <= 1)
		return s;
	for (int i = 1; i <= n; i++)
	{
		s = s + o(n - i) + 1;
	}
	n = n - 2;
	return s;
}

int fun1(int a , int b)
{
	if (a > b)return a;
	return b;
}

int fun(int a, int b)
{
	if (a==0)return b;
	return fun1(fun(a-1,2*b),fun(a - 1, 2 * b-1));
}

int foo(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
	{
		return n - foo(n - 1);
	}
}

//int main()
//{
//	//cout << " f(4) is " << f(4);
//	int a[] = { 10,20,30,40 };
//	//cout << f2(a, 4);
//	cout << foo(5)<<endl;
//	
//
// }