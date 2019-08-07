#include<iostream>
using namespace std;
int main()
{
	int i,j,sum;
    i=1,sum=0;
	while(i<=1000)
	{
		j=1;
		while(j<i)
		{
			if(i%j==0)
				sum=sum+j;
			j++;
		}
		if(sum==i)
			cout<<"一千内完数"<<sum<<endl;
	i++;
	sum=0;
	}
	return 0;
}
