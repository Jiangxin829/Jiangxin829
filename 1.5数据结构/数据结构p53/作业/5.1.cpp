#include<iostream>
using namespace std;
int main()
{
	int A[10]={0,1,2,3,4,5,6,7,8,9},B[10]={0};//ѭ������ΪA[],��ʱ����B[]
	cout<<"��Ϊ����k��λ��k��ֵ��";
	int k,i,j;
	cin>>k;
	for(i=0;i<k;i++)
	{
		B[i]=A[i];                           //��ǰk�����ݴ�����ʱ����
	}									 
	for(i=0;i<10-k;i++)
	{
		A[i]=A[i+k];                         //����k������ǰ��
	}	
	i=0;
	for(j=0;j<k;j++)
	{
		A[10-k+i]=B[j];                      //����ʱ������ȡ������ԭ����
		i++;
	}
	cout<<"�ƶ��������Ϊ��"<<endl;
	for(j=0;j<10;j++)
		cout<<A[j]<<"\t";
	return 0;
}

