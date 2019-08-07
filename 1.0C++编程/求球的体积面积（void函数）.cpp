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
	cout<<"输入球的半径:";
	cin>>r;
	sphere(a,v,r);     //函数调用
	cout<<"球的体积为："<<v<<endl;
	cout<<"球的表面积为："<<a<<endl;
	return 0;
}

