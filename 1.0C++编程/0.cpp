#include<iostream>
using namespace std;

#include<fstream>
#include<iomanip>
/*void search();
void add();
void cancle();
void change();
void average();
void num();
*/
int main()
{ 
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"|                          学生成绩管理系统                                  |"<<endl;
	cout<<"|                                                                            |"<<endl; 
	cout<<"|    1.输入学生信息（若已经输入，则从文件中读入数据）                        |"<<endl;
	cout<<"|    2.查询学生信息                                                          |"<<endl;
	cout<<"|    3.增加学生信息                                                          |"<<endl;
	cout<<"|    4.删除学生信息                                                          |"<<endl;
	cout<<"|    5.修改学生成绩                                                          |"<<endl;
	cout<<"|    6.平均成绩排序                                                          |"<<endl;
	cout<<"|    7.各分段人数及不及格人数                                                |"<<endl;
    cout<<"|    8.输出学生信息                                                          |"<<endl;
	cout<<"|    9.保存至文件                                                            |"<<endl;
	cout<<"|    0.退出系统                                                              |"<<endl;
	cout<<"|____________________________________________________________________________|"<<endl;
	cout<<" 请选择1~9模块:"<<endl;
	struct Student                                         //将信息存放于Student结构体中
	{
        char number[20];                                   //学号
		char name[20];                                     //姓名
		char sex[2];                                       //性别
		double score[4];                                   //三科成绩及平均分
	};
    int i=0,j,k,l;
    Student stu[4]={0};
	while(1)
	{
        int choose;
		cin>>choose;
        if(choose<1||choose>9)
			break;
	    switch(choose)
		{
		   case 1:
			   cout<<"请依次输入：学号 姓名 性别 高数成绩 英语成绩 计算机成绩"<<endl;	           
	           cin>>stu[i].number>>stu[i].name>>stu[i].sex;                              //将信息通过键盘输入
		       for(j=0;j<3;j++)
			   {
			       cin>>stu[i].score[j];
			   }
			   stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;    //求平均分
		       cout<<"请选择1继续输入或其他选项"<<endl;
			   i++;                                                                      //用i记录学生人数
			   break;
		   case 2:
			   	int m,sign;
				char Snum[20];
				sign=0;
	            cout<<"请输入查找学生的学号或名字"<<endl;
 	            cin>>Snum;
               	for(m=0;m<i;m++)
				{
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                 //查找学生姓名或学号
					{
		            	cout<<"该学生的学生信息为"<<endl;
			            cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		                    <<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
			            cout<<setw(10)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
					}
				}
				if(sign!=1)
				{
					cout<<"未找到该学生信息！"<<endl;
				}
				cout<<"请选择2继续查找或其他选项"<<endl;
			    break;
		   case 3:0;//add();
			   break;
		   case 4:0;//cancle();
			   break;
		   case 5:0;//change();
		   	   break;
		   case 6:0;//average();
			   break;
		   case 7:
			   
		       break;
		   case 8:
			   cout<<"                                   学生成绩表"<<endl;
	           cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		             <<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
			   for(k=0;k<i;k++)
			   {
				   cout<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				   for(l=0;l<4;l++)
				   {
					   cout<<setw(10)<<stu[k].score[l];
				   }
				   cout<<endl;
			   }
			   cout<<"请继续选择"<<endl;
			   break;
		   case 9:
			   cout<<"保存至文件？（0/1）";
			   int f;
			   cin>>f;
			   if(1)
			   {
				   ofstream input("input.txt",ios::app);                                //建立或打开文件
				   input<<"                                   学生成绩表"<<endl;
	               input<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		                 <<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
				   for(k=0;k<i;k++)
				   {
				       input<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				       for(l=0;l<4;l++)
					   {
					       input<<setw(10)<<stu[k].score[l];
					   }
				       input<<endl;
				   }
				   cout<<"保存成功！"<<endl;
			   }
			   cout<<"请继续选择"<<endl;
			   break;
		}
	}
   		  
	return 0;
}


/*1.学生成绩管理系统
(1)主菜单模块。该模块主要用来实现整个系统的流程。主界面提供用户选择并调用各个子模块。
(2)输入模块。当初次使用系统时，学生信息需要从键盘逐个输入。当学生信息已经保存在文件中时，则将从文件读入数据。学生信息由学生的学号、姓名、性别和三门课成绩等信息构成。
(3)查询模块。用户可以按照学生的学号或姓名进行查找。若查找到该学生的相关信息记录，则输出相关信息，否则提示未找到。
(4)更新模块。主要完成对学生信息的维护。包括增加记录、删除记录、修改成绩。当完成更新记录后，需要将修改的数据存入数据文件中。
(5)排序模块。根据键盘输入的选择对学生记录进行升序或降序排序，并输出排序后的结果。
(6)统计模块。统计各个分数段的人数及不及格人数。
(7)输出模块。将学生信息显示在屏幕上，并根据键盘输入的选择，如“是否保存到文件？（Y/N）”,可以将学生信息写入文件中。*/