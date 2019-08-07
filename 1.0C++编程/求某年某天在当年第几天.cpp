#include<iostream>
using namespace std;
int main()
{
	int day,a,b,c,num;
	cout<<"请输入某天的日期，如（20151226）:"<<endl;
	cin>>day;
	num=0;
    a=day/10000;                  //取出年份 
	b=(day%10000)/100;            //取出月份1 3 5 7 8 10 12大月,4 6 9 11小月,2平月.
	c=day%100;                    //取出日期
	switch(b)
	{
	case 1:
		num=c;
		break;
	case 2:
		num=31+c;
		break;
	case 3:
        num=31+28+c;
		break;
	case 4:
		num=31*2+28+c;
		break;
	case 5:
		num=31*2+28+30+c;
		break;
	case 6:
		num=31*3+28+30+c;
		break;
	case 7:
		num=31*3+28+30*2+c;
		break;
	case 8:
		num=31*4+28+30*2+c;
		break;
	case 9:
		num=31*5+28+30*2+c;
		break;
	case 10:
		num=31*5+28+30*3+c;
	    break;
	case 11:
		num=31*6+28+30*3+c;
		break;
	case 12:
		num=31*6+28+30*4+c;
		break;
	default:
		cout<<"输入日期有误，请重新输入"<<endl;
	}
	if(b>=3)
		if((a%4==0&&a%100!=0)||(a%400==0))
	     num=num+1;
	cout<<"该日期是当年第"<<num<<"天"<<endl;
	return 0;
}


	




    

