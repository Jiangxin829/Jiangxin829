#include<iostream>
using namespace std;
void story(int num);
int main()
{
	int num;
	cout<<"讲的次数为：";
	cin>>num;
	story(num);
	return 0;
}
void story(int num)
{
	cout<<"从前有个山，山里有个庙，庙里有个老和尚给小和尚讲故事。"<<endl;
	if(num>1)
		story(num-1);
}
