#include<iostream>
using namespace std;
int sphere(float &a,float &v,float r);
int main()
{
	const double PI=3.14;
	float a,v,r;
	cout<<"����Բ�İ뾶��";
	cin>>r;
	sphere(a,v,r);                 //��������
	cout<<"������Ϊ��"<<v<<endl;
	cout<<"��ı����Ϊ��"<<a<<endl;
	return 0;
}
int sphere(float &a,float &v,float r)
{
	const double PI=3.14;
    v=(4.0/3)*PI*(r*r*r);         //ע�⾫��
	a=4*PI*r*r;
	return (a,v,r);
}