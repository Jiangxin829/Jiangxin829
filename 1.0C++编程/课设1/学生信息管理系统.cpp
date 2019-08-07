#include<iostream>
using namespace std;
#include<string.h> 
#include<fstream>
#include<iomanip>
struct Student                                         //将信息存放于Student结构体中
{
    char number[20];                                   //学号
    char name[20];                                     //姓名
	char sex[20];                                       //性别
	int score[4];                                   //三科成绩及平均分
};
void menu()
{
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"|                          学生成绩管理系统                                  |"<<endl;
	cout<<"|                                                                            |"<<endl; 
	cout<<"|    1.输入学生信息（若已经输入，可选择从文件中读入数据）                    |"<<endl;
	cout<<"|    2.查询学生信息                                                          |"<<endl;
	cout<<"|    3.增加学生信息                                                          |"<<endl;
	cout<<"|    4.删除学生信息                                                          |"<<endl;
	cout<<"|    5.修改学生成绩                                                          |"<<endl;
	cout<<"|    6.平均成绩排序                                                          |"<<endl;
	cout<<"|    7.各分段人数及不及格人数                                                |"<<endl;
    cout<<"|    8.输出学生信息                                                          |"<<endl;
    cout<<"|    9.保存至文件                                                            |"<<endl;
	cout<<"|    10.查看菜单                                                             |"<<endl;
	cout<<"|    0.退出系统                                                              |"<<endl;
	cout<<"|____________________________________________________________________________|"<<endl;
	cout<<" 请选择0~10模块:"<<endl;
}
void average(Student stu[],int i)
{
	cout<<"请选择1.降序排列 2.升序排列 3.返回菜单"<<endl;
	int n,j,t,k,choose;
	cin>>choose;
	if(choose==1)
	{
		t=0;
        for(n=0;n<i-1;n++)
		{
			k=n;
			for(j=n+1;j<i;j++)
				if(stu[j].score[3]>stu[k].score[3]) k=j;
			if(k!=n)
			{
				stu[i]=stu[t];                     //此处stu[i]仅起转换作用
				stu[t]=stu[k];
				stu[k]=stu[i];
			}
			t++;			
		}
		cout<<"已选择降序排列，选择8可查看！"<<endl;
	}
	else
		if(choose==2)
		{
			t=0;
			for(n=0;n<i-1;n++)
			{
				k=n;
				for(j=n+1;j<i;j++)
					if(stu[j].score[3]<stu[k].score[3]) k=j;
				if(k!=n)
				{
					stu[i]=stu[t];                     //此处stu[i]仅起转换作用
					stu[t]=stu[k];
					stu[k]=stu[i];
				}
				t++;			
			}
			cout<<"已选择升序排列，选择8可查看！"<<endl;
		}
		else
		    if(choose==3)	
			cout<<"已返回菜单!请选择0~10"<<endl; 
}
int main()
{ 
    
    int i=0,j,k,l,m,n,sign;
	char Snum[20]={0};
	char decide[2];
    Student stu[4]={0};
again:
    menu();
	while(1)
	{		
        int choose;
		cin>>choose;
        if(choose<1||choose>10)
			break;
	    switch(choose)
		{
		   case 1:
		   cout<<"请选择1.输入学生成绩 2.从文件读入 3.返回主菜单"<<endl;
		   	   cin>>choose;
		   	   if(choose==3)
				  goto again; 
		   	   if (choose==1)
		   	   {
		   	   	    while(1)
		   	   	    { 		   	   	    	
                    	if(choose!=1)
			        	break;
add:           	   		cout<<"请依次输入：学号 姓名 性别 高数成绩 英语成绩 计算机成绩"<<endl;	           
	           			cin>>stu[i].number>>stu[i].name>>stu[i].sex;                              //将信息通过键盘输入
		       			for(j=0;j<3;j++)
			   			{
			       			cin>>stu[i].score[j];
			   			}
			   			stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;    //求平均分			   
		       			cout<<"输入完成，请选择1继续输入,输入0返回至菜单"<<endl;
						cin>>choose;
			   			i++;
					} 
					cout<<"请继续选择0~10模块"<<endl;                                                                  //用i记录学生人数
			    } 
				else
				    if(choose==2)
					{
						ifstream read("学生成绩表.txt"); 
						if(!read.is_open())
						{
							cout<<"文件打开错误"<<endl;
						}
						if(read.is_open())
						{
						 	read>>stu[i+2].number;
						 	//cout<<stu[i+2].number<<endl;
							read>>stu[i+3].number>>stu[i+3].name>>stu[i+3].sex>>stu[i+2].number>>stu[i+2].name>>stu[i+2].sex>>stu[i+4].number;
							//cout<<stu[i+3].number<<stu[i+3].name<<stu[i+3].sex<<stu[i+2].number<<stu[i+2].name<<stu[i+2].sex<<stu[i+4].number<<endl;
							j=0;
							do{
								read>>stu[j].number>>stu[j].name>>stu[j].sex>>stu[j].score[0]>>stu[j].score[1]>>stu[j].score[2]>>stu[j].score[3];
								//cout<<setw(10)<<stu[j].number<<setw(10)<<stu[j].name<<setw(10)<<stu[j].sex<<setw(10)
								    //<<stu[j].score[0]<<setw(10)<<stu[j].score[1]<<setw(10)<<stu[j].score[2]<<setw(10)<<stu[j].score[3]<<endl;
								j++;												
							}while(!read.eof());
							cout<<"读入学生个数为："<<j-1<<endl;
							i=j-1;
							cout<<"读取完成，可输入8查看"<<endl;
						}
					}                                                               
			    break;
		   case 2:
				sign=0;
	            cout<<"请输入查找学生的学号或名字 输入'返回'至菜单"<<endl;
 	            cin>>Snum;
 	            if(!strcmp(Snum,"返回")) 
 	                goto again; 
               	for(m=0;m<i;m++)
				{
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                  //查找学生姓名或学号
					{
		            	cout<<"该学生的学生信息为:"<<endl;
			            cout<<setw(23)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		                    <<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
			            cout<<setw(23)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
						break;
					}					
				}
				if(sign!=1)
				{
					cout<<"未找到该学生信息！"<<endl;
				}
				cout<<"请选择2继续查找或其他选项"<<endl;
			    break;
		   case 3:
			   goto add;
			   break;
		   case 4:
			   cout<<"请输入要删除的学生学号或姓名，输入'返回'至菜单"<<endl;
			   sign=0;
			   cin>>Snum;
			   if(!strcmp(Snum,"返回")) 
 	                goto again; 
               for(m=0;m<i;m++)
			   {
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                 //查找学生姓名或学号
					{
		            	cout<<"找到该学生的学生信息为:"<<endl;
			            cout<<setw(23)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		                    <<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
			            cout<<setw(23)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
						cout<<"请确认是否删除该学生信息（是/否）"<<endl;
						cin>>decide;
						if(!strcmp(decide,"是"))
						{
							for(n=m;n<i;n++)
							{
								stu[n]=stu[n+1];
							}
						    cout<<"删除完毕！可输入8查看"<<endl;
							i=i-1;
						}
						else
							cout<<"删除操作取消！"<<endl;						
						break;
					}
			   }
			   if(sign!=1)
			   {
				   cout<<"未找到该学生信息！"<<endl;
			   }
			   cout<<"请继续选择0~10模块"<<endl; 
			   break;
		   case 5:
			   cout<<"请输入要修改的学生学号或姓名，输入'返回'至菜单"<<endl;
               sign=0;
			   cin>>Snum;
			   if(!strcmp(Snum,"返回")) 
 	                goto again; 
               for(m=0;m<i;m++)
			   {
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                 //查找学生姓名或学号
					{
		            	cout<<"找到该学生的学生信息为:"<<endl;
			            cout<<setw(23)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		                    <<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
			            cout<<setw(23)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
						cout<<"请选择修改内容：1.学号 2.姓名 3.性别 4.高数成绩 5.英语成绩 6.计算机成绩 7.重新输入该生信息"<<endl;
						cin>>l;
						switch(l)
						{
						case 1:
							cout<<"请重新输入该生学号："<<endl;
							cin>>stu[m].number;
							break;
						case 2:
							cout<<"请重新输入该生姓名："<<endl;
							cin>>stu[m].name;
							break;
						case 3:
							cout<<"请重新输入该生性别："<<endl;
							cin>>stu[m].sex;
							break;
						case 4:
							cout<<"请重新输入该生高数成绩："<<endl;
							cin>>stu[m].score[0];
							break;
						case 5:
							cout<<"请重新输入该生英语成绩："<<endl;
							cin>>stu[m].score[1];
							break;
						case 6:
							cout<<"请重新输入该生计算机成绩："<<endl;
							cin>>stu[m].score[2];
							break;
						case 7:
							cout<<"请重新输入该学生 学号 姓名 性别 高数成绩 英语成绩 计算机成绩："<<endl;
                            cin>>stu[m].number>>stu[m].name>>stu[m].sex;
							for(j=0;j<3;j++)
							{
								cin>>stu[m].score[j];
							}
							break;
						}
						stu[m].score[3]=(stu[m].score[0]+stu[m].score[1]+stu[m].score[2])/3;  
						cout<<"修改完毕！可输入8查看"<<endl;
						break;
					}
			   }
			   if(sign!=1)
			   {
				   cout<<"未找到该学生信息！请继续选择0~10模块"<<endl;
			   }
		   	   break;
		   case 6:
			   average(stu,i);
			   break;
		   case 7:
		   	while(1)
			   {
			   	cout<<"请选择查询科目 1.高数 2.英语 3.计算机 4.返回菜单"<<endl; 
			   	cin>>choose;
        		if(choose<1||choose>3)
				break;		   
		   	    int accout,S11,S2,S3,S4,S5,S6,S7,S8,S9,S10;
		   	    switch(choose)
		   	    {
		   	    	case 1:	
			        	S11=0;
                    	S2=0;
                    	S3=0;
                    	S4=0;
                    	S5=0;
                    	S6=0;
                    	S7=0;
                    	S8=0;
                    	S9=0;
                    	S10=0;
			       		accout=0; 
				   		l=0;
                   		for(m=0;m<i;m++)
				   		{
					 		if(stu[m].score[l]<60)
					 		{
					 			accout++;
					 	     }
					 	     
				   		}
					 	cout<<"高数不及格人数为"<<accout<<endl;
						 for(m=0;m<i;m++)
					 	{
                      		 if(0<=stu[m].score[l]&&stu[m].score[l]<10)
                          		S11++;
                       		 if(9<stu[m].score[l]&&stu[m].score[l]<20)
                          		S2++;
                       		 if(19<stu[m].score[l]&&stu[m].score[l]<30)
                          	 S3++;
                      		 if(29<stu[m].score[l]&&stu[m].score[l]<40)
                          	 S4++;
                             if(39<stu[m].score[l]&&stu[m].score[l]<50)
                             S5++;
                             if(49<stu[m].score[l]&&stu[m].score[l]<60)                             
                             S6++;
                             if(59<stu[m].score[l]&&stu[m].score[l]<70)
                             S7++;
                             if(69<stu[m].score[l]&&stu[m].score[l]<80)
                             S8++;
                             if(79<stu[m].score[l]&&stu[m].score[l]<90)
                             S9++;
                             if(89<stu[m].score[l]&&stu[m].score[l]<=100)
                             S10++;
					  	 }
                         cout<<"高数分数0~9人数为"<<S11<<endl;
                         cout<<"高数分数10~19人数为"<<S2<<endl;
                         cout<<"高数分数20~29人数为"<<S3<<endl;
                         cout<<"高数分数30~39人数为"<<S4<<endl;
                    	 cout<<"高数分数40~49人数为"<<S5<<endl;
                    	 cout<<"高数分数50~59人数为"<<S6<<endl;
                    	 cout<<"高数分数60~69人数为"<<S7<<endl;
                    	 cout<<"高数分数70~79人数为"<<S8<<endl;
                    	 cout<<"高数分数80~89人数为"<<S9<<endl;
                    	 cout<<"高数分数90~100人数为"<<S10<<endl;
                    	 cout<<"可输入0返回菜单"<<endl;
                    	 break;
                    case 2: 
                    	S11=0;
                    	S2=0;
                    	S3=0;
                    	S4=0;
                    	S5=0;
                    	S6=0;
                    	S7=0;
                    	S8=0;
                    	S9=0;
                    	S10=0;
				     	accout=0;
					 	l=1;
					  	for(m=0;m<i;m++)
				   		{
					 		if(stu[m].score[l]<60)
                       		accout++;
				   		}
					 	cout<<"英语不及格人数为"<<accout<<endl;
					 	for(m=0;m<i;m++)
					 	{
                       		if(0<=stu[m].score[l]&&stu[m].score[l]<10)
                          	S11++;
                       		if(9<stu[m].score[l]&&stu[m].score[l]<20)
                          	S2++;
                       		if(19<stu[m].score[l]&&stu[m].score[l]<30)
                            S3++;
                       		if(29<stu[m].score[l]&&stu[m].score[l]<40)
                          	S4++;
                       		if(39<stu[m].score[l]&&stu[m].score[l]<50)
                          	S5++;
                       		if(49<stu[m].score[l]&&stu[m].score[l]<60)                             
                          	S6++;
                       		if(59<stu[m].score[l]&&stu[m].score[l]<70)
                          	S7++;
                       		if(69<stu[m].score[l]&&stu[m].score[l]<80)
                          	S8++;
                       		if(79<stu[m].score[l]&&stu[m].score[l]<90)
                          	S9++;
                       		if(89<stu[m].score[l]&&stu[m].score[l]<=100)
                            S10++;
					 	 }
                    	 cout<<"英语分数0~9人数为"<<S11<<endl;
                    	 cout<<"英语分数10~19人数为"<<S2<<endl;
                    	 cout<<"英语分数20~29人数为"<<S3<<endl;
                    	 cout<<"英语分数30~39人数为"<<S4<<endl;
                    	 cout<<"英语分数40~49人数为"<<S5<<endl;
                    	 cout<<"英语分数50~59人数为"<<S6<<endl;
                    	 cout<<"英语分数60~69人数为"<<S7<<endl;
                    	 cout<<"英语分数70~79人数为"<<S8<<endl;
                    	 cout<<"英语分数80~89人数为"<<S9<<endl;
                    	 cout<<"英语分数90~100人数为"<<S10<<endl;
                    	 cout<<"可输入0返回菜单"<<endl;
                    	 break;
                    case 3:
                    	 S11=0;
                    	 S2=0;
                    	 S3=0;
                    	 S4=0;
                    	 S5=0;
                    	 S6=0;
                    	 S7=0;
                    	 S8=0;
                    	 S9=0;
                    	 S10=0;
					 	 accout=0;
					 	 l=2;
					 	 for(m=0;m<i;m++)
				   	 	 {	
					 		if(stu[m].score[l]<60)
                       		accout++;
				   		}	
					    cout<<"计算机不及格人数为"<<accout<<endl;
					    for(m=0;m<i;m++)
					    {
                            if(0<=stu[m].score[l]&&stu[m].score[l]<10)
                          	S11++;
                        	if(9<stu[m].score[l]&&stu[m].score[l]<20)
                          	S2++;
                       		if(19<stu[m].score[l]&&stu[m].score[l]<30)
                          	S3++;
                       		if(29<stu[m].score[l]&&stu[m].score[l]<40)
                          	S4++;
                       		if(39<stu[m].score[l]&&stu[m].score[l]<50)
                          	S5++;
                       		if(49<stu[m].score[l]&&stu[m].score[l]<60)                             
                          	S6++;
                       		if(59<stu[m].score[l]&&stu[m].score[l]<70)
                          	S7++;
                       		if(69<stu[m].score[l]&&stu[m].score[l]<80)
                          	S8++;
                       		if(79<stu[m].score[l]&&stu[m].score[l]<90)
                          	S9++;
                       		if(89<stu[m].score[l]&&stu[m].score[l]<=100)
                            S10++;
					 	}	
                    	cout<<"计算机分数0~9人数为"<<S11<<endl;
                    	cout<<"计算机分数10~19人数为"<<S2<<endl;
                    	cout<<"计算机分数20~29人数为"<<S3<<endl;
                    	cout<<"计算机分数30~39人数为"<<S4<<endl;
                    	cout<<"计算机分数40~49人数为"<<S5<<endl;
                    	cout<<"计算机分数50~59人数为"<<S6<<endl;
                    	cout<<"计算机分数60~69人数为"<<S7<<endl;
                    	cout<<"计算机分数70~79人数为"<<S8<<endl;
                    	cout<<"计算机分数80~89人数为"<<S9<<endl;
                    	cout<<"计算机分数90~100人数为"<<S10<<endl;
						cout<<"可输入0返回菜单"<<endl;
						break;
				   }
			   }
			   cout<<"请继续选择0~10模块"<<endl;	   
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
			   cout<<"请继续选择0~10模块"<<endl;
			   break;
		   case 9:
			   cout<<"保存至文件？（是/否）"<<endl;
			   cin>>decide;
			   if(!strcmp(decide,"是"))
			   {
				   ofstream input("学生成绩表.txt",ios::out);                                //建立或打开文件
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
			   else
			       {
			       	cout<<"保存操作取消！";
				   }
			   cout<<"请继续选择0~10模块"<<endl;
			   break;
		   case 10: 
		       menu();
		       break;
		}
	}
   	cout<<"是否退出系统？(是/否)"<<endl;
	cin>>decide;
	if(!strcmp(decide,"否"))
		goto again;	  
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
