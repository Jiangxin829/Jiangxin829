#include<iostream>
using namespace std;
void sphere(float &a,float &v,float r)
{
	const double PI=3.14;
	v=(4.0/3)*PI*r*r*r;
	a=4*PI*r*r;
}
int main()
{
	float a,v,r;
	cout<<"������İ뾶:";
	cin>>r;
	sphere(a,v,r);     //��������
	cout<<"������Ϊ��"<<v<<endl;
	cout<<"��ı����Ϊ��"<<a<<endl;
	return 0;
}

