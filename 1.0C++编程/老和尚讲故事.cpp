#include<iostream>
using namespace std;
void story(int num);
int main()
{
	int num;
	cout<<"���Ĵ���Ϊ��";
	cin>>num;
	story(num);
	return 0;
}
void story(int num)
{
	cout<<"��ǰ�и�ɽ��ɽ���и��������и��Ϻ��и�С���н����¡�"<<endl;
	if(num>1)
		story(num-1);
}
