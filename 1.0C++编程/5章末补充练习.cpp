//���(����)��һ���༶��3��ѧ����ÿ��ѧ����2�Ź��Σ���ÿ��ѧ����ƽ���֣������ƽ���֣�����ƽ���ִӸߵ�������
//��ѧ������Ϊ��student [3][2]= {{70,75}; {84, 88}; {92, 91}};
#include<iostream>
using namespace std;
void turn(double a[],int m);                                           //������Ϊa��
const int N=3;
int main()
{
	double student[3][3]=
	{
		{70.00,75.00},
		{92.00,91.00},
		{84.00,88.00}
	};
	int i;
	for(i=0;i<3;i++)
	{
		student[i][2]=(student[i][0]+student[i][1])/2.00;
		cout<<"ѧ��"<<i+1<<"��ƽ���ɼ�Ϊ��"<<student[i][2]<<endl;
	}
	double average[N]={student[0][2],student[1][2],student[2][2]};
	turn(average,N);                                                  //���ú���ʹ���������� ����Ҳ�����βΣ�      
	cout<<"����ƽ���ɼ�����Ϊ��";
	for(int a=0;a<3;a++)
		cout<<average[a]<<"\t";
	return 0;
}
void turn(double a[],int m)                                          //����ʱ���βΣ�������ʱ�������β�
{
	int b,c,t,flag;
	for(b=0;b<m;b++)
	{
		flag=0;
	    for(c=0;c<m-b-1;c++)
			if(a[c]<a[c+1])
			{
				t=a[c];
				a[c]=a[c+1];
				a[c+1]=t;
				flag=1;
			}
			if(flag==0) break;
	}
}





