#include<iostream>
using namespace std;
int main()
{
	int i,j,sum;
	sum=0;
    for(i=1;i<=1000;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				sum=sum+j;
		}
		if(sum==i)
			cout<<"һǧ������������:"<<sum<<endl;
        sum=0;
	}
	return 0;
}

			



