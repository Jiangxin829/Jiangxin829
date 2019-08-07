#include<iostream>
using namespace std;
int main()
{
	int A[10]={0,1,2,3,4,5,6,7,8,9},B[10]={0},C[10]={0};//A[n]为已存数组，B[n]、C[n]分别存放偶数和奇数
	int i,m=0,n=0;
	for(i=0;i<10;i++)
	{
		if(A[i]%2==0)                                   //通过除2取余判断奇数偶数
		{
			B[m]=A[i];
			m++;
		}
		else
		{
			C[n]=A[i];
			n++;
		}
	}
	cout<<"奇数个数为："<<n<<endl;
	cout<<"偶数个数为："<<m<<endl;
	for(i=0;i<n;i++)                                   //将奇数放回原数组
		A[i]=C[i];
	for(i=0;i<m;i++)                                   //将偶数放回原数组
		A[n+i]=B[i];
	cout<<"调整过的数组为："<<endl;
	for(i=0;i<10;i++)
		cout<<A[i]<<"\t";
	return 0;
}
