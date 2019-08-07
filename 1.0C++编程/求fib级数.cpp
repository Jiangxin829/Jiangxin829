#include<iostream>
using namespace std;
int fib(int n);
int main()
{
	int n,answer;
	n=4;
	answer=fib(n);
	cout<<answer<<"is the "<<n<<"th Fibnacci number  ";
	return 0;
}
int fib(int n)
{
	int answer;
	if (n<=2)
	{
		answer=1;
		return 1;
	}
	else
	{
		answer=fib(n-1)+fib(n-2);
		return answer;
	}
}