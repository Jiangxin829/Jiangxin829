#include<iostream>
using namespace std;
int main()
{
	int A[10]={0,1,2,3,4,5,6,7,8,9},B[10]={0};//循环数组为A[],临时数组B[]
	cout<<"请为左移k个位置k赋值：";
	int k,i,j;
	cin>>k;
	for(i=0;i<k;i++)
	{
		B[i]=A[i];                           //将前k个数据存入临时数组
	}									 
	for(i=0;i<10-k;i++)
	{
		A[i]=A[i+k];                         //将后k个数据前移
	}	
	i=0;
	for(j=0;j<k;j++)
	{
		A[10-k+i]=B[j];                      //从临时数组提取并放入原数组
		i++;
	}
	cout<<"移动后的数组为："<<endl;
	for(j=0;j<10;j++)
		cout<<A[j]<<"\t";
	return 0;
}

