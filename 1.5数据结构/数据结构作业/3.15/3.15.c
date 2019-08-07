#include<iostream>
using namespace std;
int getpower(int x,int y);
double getpower(double x,double y);
int main()
{
    int a,m;
    double b;
    cout<<"请输入一个整数，一个实数：";
    cin>>a>>m;
    cout<<"请输入一个整型指数：";
    cin>>b;
    cout<<a<<"^"<<m<<"="<<getpower(a,m);
    cout<<b<<"^"<<m<<"="<<getpower(b,m);
    return 0;
}
int getpower(int x,int y)
{
    unsigned f;
    if(y==0)
        f=1;
    else
        f=x*getpower(x,y-1)
    return f;

}
double getpower(double x,double y)
{
    unsigned f;
    if(y==0)
        f=1;
    else
        f=x*getpower(x,y-1)
    return f;

}
