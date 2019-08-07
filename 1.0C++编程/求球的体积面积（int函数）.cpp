#include<iostream>
using namespace std;
int sphere(float &a,float &v,float r);
int main()
{
	const double PI=3.14;
	float a,v,r;
	cout<<"输入圆的半径：";
	cin>>r;
	sphere(a,v,r);                 //函数调用
	cout<<"球的体积为："<<v<<endl;
	cout<<"球的表面积为："<<a<<endl;
	return 0;
}
int sphere(float &a,float &v,float r)
{
	const double PI=3.14;
    v=(4.0/3)*PI*(r*r*r);         //注意精度
	a=4*PI*r*r;
	return (a,v,r);
}