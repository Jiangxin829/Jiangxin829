#include<iostream>
using namespace std;
int main()
{
	int A[10]={0,1,2,3,4,5,6,7,8,9},B[10]={0},C[10]={0};//A[n]Ϊ�Ѵ����飬B[n]��C[n]�ֱ���ż��������
	int i,m=0,n=0;
	for(i=0;i<10;i++)
	{
		if(A[i]%2==0)                                   //ͨ����2ȡ���ж�����ż��
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
	cout<<"��������Ϊ��"<<n<<endl;
	cout<<"ż������Ϊ��"<<m<<endl;
	for(i=0;i<n;i++)                                   //�������Ż�ԭ����
		A[i]=C[i];
	for(i=0;i<m;i++)                                   //��ż���Ż�ԭ����
		A[n+i]=B[i];
	cout<<"������������Ϊ��"<<endl;
	for(i=0;i<10;i++)
		cout<<A[i]<<"\t";
	return 0;
}
