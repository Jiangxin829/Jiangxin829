#include<iostream>
using namespace std;

double average(double *point,int N)
{
	double sum=0,m;
	for(m=0;m<6;m++)
	{
		sum+=*point;
		point++;
	}
	return sum/6;
}
void order(double ipoint[],int N)
{
	int i,j,t,p;
	double *k=ipoint;
	for(i=0;i<5;i++)
	{
		p=i;
		for(j=i+1;j<6;j++)
		{
			if(*(k+p)<*(k+j)) p=j;
		}
		if(p!=i)
		{
			t=*(k+i);
			*(k+i)=*(k+p);
			*(k+p)=t;
		}
	}
}

int main()
{
	int c;
	cout<<"����������ѧ���ĳɼ�:"<<endl;
	double score[6];
	for(int n=0;n<6;n++)
	{
		cin>>c;
		score[n]=c;
	}
	average(score,6);
    cout<<"ƽ����Ϊ:"<<average(score,6)<<endl;
	order(score,6);
    cout<<"��߷�Ϊ:"<<score[0]<<endl;

	return 0;
}




