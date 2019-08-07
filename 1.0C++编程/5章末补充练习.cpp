//编程(补充)：一个班级有3个学生，每个学生有2门功课，求每个学生的平均分，输出其平均分，并按平均分从高到低排序
//设学生数据为：student [3][2]= {{70,75}; {84, 88}; {92, 91}};
#include<iostream>
using namespace std;
void turn(double a[],int m);                                           //数组名为a！
const int N=3;
int main()
{
	double student[3][3]=
	{
		{70.00,75.00},
		{92.00,91.00},
		{84.00,88.00}
	};
	int i;
	for(i=0;i<3;i++)
	{
		student[i][2]=(student[i][0]+student[i][1])/2.00;
		cout<<"学生"<<i+1<<"的平均成绩为："<<student[i][2]<<endl;
	}
	double average[N]={student[0][2],student[1][2],student[2][2]};
	turn(average,N);                                                  //调用函数使用了数组名 ，（也可用形参）      
	cout<<"三人平均成绩排序为：";
	for(int a=0;a<3;a++)
		cout<<average[a]<<"\t";
	return 0;
}
void turn(double a[],int m)                                          //定义时用形参，且运算时必须用形参
{
	int b,c,t,flag;
	for(b=0;b<m;b++)
	{
		flag=0;
	    for(c=0;c<m-b-1;c++)
			if(a[c]<a[c+1])
			{
				t=a[c];
				a[c]=a[c+1];
				a[c+1]=t;
				flag=1;
			}
			if(flag==0) break;
	}
}





