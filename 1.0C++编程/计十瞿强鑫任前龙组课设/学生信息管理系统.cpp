 #include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
struct student
{
	char number[20];
	char name[20];
	char sex[4];
	int score[4];
};
student stu[]={0};
class Systerm
{
	int i;
public:
	Systerm()
	{i=0;}
	
	void putin();                      //输入学生信息 
	void search();                     //查询学生信息 
	void increase();                   //增加学生信息 
	void cancle();                     //删除学生信息 
	void change();                     //修改学生信息 
	void turnlist();                   //学生平均分排序 
	void statistics();                 //各分数段统计 				
	void save();                       //存储学生信息至文件 
	void putout();                     //输出学生信息表 
	void menu();	                   //菜单，用于查看 
};
void Systerm::menu()
{
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"|                          学生成绩管理系统                                  |"<<endl;
	cout<<"|                                                                            |"<<endl; 
	cout<<"|   ★★********** 1.输入学生信息/从文件中读入数据**********★★             |"<<endl;
	cout<<"|   ★★********** 2.查询学生信息                 **********★★             |"<<endl;
	cout<<"|   ★★********** 3.增加学生信息                 **********★★             |"<<endl;
	cout<<"|   ★★********** 4.删除学生信息                 **********★★             |"<<endl;
	cout<<"|   ★★********** 5.修改学生成绩                 **********★★             |"<<endl;
	cout<<"|   ★★********** 6.平均成绩排序                 **********★★             |"<<endl;
	cout<<"|   ★★********** 7.各分段人数及不及格人数       **********★★             |"<<endl;
    cout<<"|   ★★********** 8.输出学生信息                 **********★★             |"<<endl;
    cout<<"|   ★★********** 9.保存至文件                   **********★★             |"<<endl;
	cout<<"|   ★★********** 10.查看菜单                    **********★★             |"<<endl;
	cout<<"|   ★★********** 0.退出系统                     **********★★             |"<<endl;
	cout<<"|____________________________________________________________________________|"<<endl;
	cout<<" 请选择0~10模块："<<endl;
}
void Systerm::putin()
{
	cout<<"请选择1.输入学生成绩 2.从文件读入 3.返回菜单"<<endl;
	int choose;
    cin>>choose;
    if(choose==1)
	{
		while(1)
		{ 				
            if(choose!=1)
            {
			 	cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
			   	break;
			}  
back4:      cout<<"请依次输入：学号 姓名 性别"<<endl;	         
	        cin>>stu[i].number>>stu[i].name>>stu[i].sex; //将信息通过键盘输入
     		cout<<"请输入高数成绩(百分制0~100）"<<endl;	 //检验输入成绩合法性         
		    cin>>stu[i].score[0];  
		    if(stu[i].score[0]<0||stu[i].score[0]>100) 
			{
			    cout<<"请重新输入合法成绩！"<<endl;
                cin>>stu[i].score[0]; 
			}	
			cout<<"请输入英语成绩（百分制0~100）"<<endl;
			cin>>stu[i].score[1];
			if(stu[i].score[1]<0||stu[i].score[1]>100) 
			{
			    cout<<"请重新输入合法成绩！"<<endl;
				cin>>stu[i].score[1];
			}	
			cout<<"请输入计算机成绩（百分制0~100)"<<endl;
			cin>>stu[i].score[2];
			if(stu[i].score[2]<0||stu[i].score[2]>100) 
			{
			    cout<<"请重新输入合法成绩！"<<endl;
				cin>>stu[i].score[2];
			}				    
			stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;    //求平均分
		    for(int  n=0;n<i;n++)
			{
			    while(!strcmp(stu[n].number,stu[i].number)||!strcmp(stu[n].name,stu[i].name))
			    {
			    	cout<<"学号或姓名重复，请核对信息后重新输入"<<endl;
			    	goto back4;
			    	break;
				}			
			}					                 		   
		    cout<<"输入完成，请选择1继续输入,输入0返回菜单"<<endl;
		    cin>>choose;
			i++;
		}
		//cout<<"i="<<i<<endl;                     
	}
	if(choose==2)
	{
		ifstream read("学生成绩表.txt"); 
		if(!read.is_open())
		{
			cout<<"文件打开错误,请重新选择0~10"<<endl;
		}
		if(read.is_open())
		{
			read>>stu[i+2].number;
			read>>stu[i+3].number>>stu[i+3].name>>stu[i+3].sex>>stu[i+2].number>>stu[i+2].name>>stu[i+2].sex>>stu[i+4].number;
			int j=0;			
			do{
				read>>stu[j].number>>stu[j].name>>stu[j].sex>>stu[j].score[0]>>stu[j].score[1]>>stu[j].score[2]>>stu[j].score[3];							
				j++;													
			}while(!read.eof());
			cout<<"读入学生个数为："<<j-1<<endl;
			i=j-1;
			cout<<"读取完成，可输入8查看"<<endl;
		}
	} 
	if(choose==3) 
	{
		cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
	}                                    	
}
void Systerm::search()
{
		int m=0;
		int sign=0;
		char Snum[20]={0};
		cout<<"请输入查找学生的学号或名字,输入‘返回’至菜单"<<endl;
 		cin>>Snum;
 		if(!strcmp(Snum,"返回"))
 		{
 			goto back1;
 		}    
		for(;m<i;m++)
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
back1:	cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
}
void Systerm::increase()
{
	int choose=1;
	while(1)
		{ 				
            if(choose!=1)
			   break;
back4:      cout<<"请依次输入：学号 姓名 性别"<<endl;	         
	        cin>>stu[i].number>>stu[i].name>>stu[i].sex; //将信息通过键盘输入
     		cout<<"请输入高数成绩(百分制0~100）"<<endl;	 //检验输入成绩合法性         
		    cin>>stu[i].score[0];  
		    if(stu[i].score[0]<0||stu[i].score[0]>100) 
			{
			    cout<<"请重新输入合法成绩！"<<endl;
                cin>>stu[i].score[0]; 
			}	
			cout<<"请输入英语成绩（百分制0~100）"<<endl;
			cin>>stu[i].score[1];
			if(stu[i].score[1]<0||stu[i].score[1]>100) 
			{
			    cout<<"请重新输入合法成绩！"<<endl;
				cin>>stu[i].score[1];
			}	
			cout<<"请输入计算机成绩（百分制0~100)"<<endl;
			cin>>stu[i].score[2];
			if(stu[i].score[2]<0||stu[i].score[2]>100) 
			{
			    cout<<"请重新输入合法成绩！"<<endl;
				cin>>stu[i].score[2];
			}				    
			stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;    //求平均分
		    for(int  n=0;n<i;n++)
			{
			    while(!strcmp(stu[n].number,stu[i].number)||!strcmp(stu[n].name,stu[i].name))
			    {
			    	cout<<"学号或姓名重复，请核对信息后重新输入"<<endl;
			    	goto back4;
			    	break;
				}			
			}					                 		   
		    cout<<"输入完成，请选择1继续输入,输入0返回菜单"<<endl;
		    cin>>choose;
			i++;
			//cout<<"i="<<i<<endl;
		}
		cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
}
void Systerm::cancle()
{
	 cout<<"请输入要删除的学生学号或姓名，输入'返回'至菜单"<<endl;
	 int sign=0;
	 int m=0;
	 char Snum[20]={0};
	 char decide[2];
	 cin>>Snum; 
	 if(!strcmp(Snum,"返回"))
	 {
	 goto back2;	
	 }
         for(;m<i;m++)
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
					 for(int n=m;n<i;n++)
					 {
						 stu[n]=stu[n+1];
					 }
					 cout<<"删除完毕！可输入8查看,10即查看菜单"<<endl;
					 i=i-1;
				 }
				 else
				     cout<<"删除操作取消！"<<endl;
			 }
		}
		if(sign!=1)
			   {
				   cout<<"未找到该学生信息！"<<endl;
			   }
back2:		cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
}
void Systerm::change()
{
	cout<<"请先查找要修改的学生学号或姓名,输入'返回'至菜单"<<endl;
    int sign=0;
	int m=0;
    char Snum[20]={0};
	cin>>Snum;
	if(!strcmp(Snum,"返回"))
	 {
	 	 cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
	     goto back3;	
	 }
    for(;m<i;m++)
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
			int l; 
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
				if(stu[m].score[0]<0||stu[m].score[0]>100) 
				{
			    	cout<<"请重新输入合法成绩！"<<endl;
                	cin>>stu[m].score[0]; 
				}	
				break;
			case 5:
				cout<<"请重新输入该生英语成绩："<<endl;
				cin>>stu[m].score[1];
				if(stu[m].score[1]<0||stu[m].score[1]>100) 
				{
			    	cout<<"请重新输入合法成绩！"<<endl;
                	cin>>stu[m].score[1]; 
				}	
				break;
			case 6:
				cout<<"请重新输入该生计算机成绩："<<endl;
				cin>>stu[m].score[2];
				if(stu[m].score[2]<0||stu[m].score[2]>100) 
				{
			   		cout<<"请重新输入合法成绩！"<<endl;
                	cin>>stu[m].score[2]; 
				}	
				break;
			case 7:
				cout<<"请重新输入该学生 学号 姓名 性别 高数成绩 英语成绩 计算机成绩："<<endl;
                cin>>stu[m].number>>stu[m].name>>stu[m].sex;
					for(int j=0;j<3;j++)
				{
					cin>>stu[m].score[j];
				} 
				break;
			}
			stu[m].score[3]=(stu[m].score[0]+stu[m].score[1]+stu[m].score[2])/3;  
			cout<<"修改完毕！可输入8查看,10即查看菜单"<<endl;
			break;
		}
	}
back3:  if(sign!=1)
		{
			cout<<"未找到该学生信息！请继续选择0~10模块,10即查看菜单"<<endl;
		}	
}
void Systerm::turnlist()
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
		cout<<"已选择降序排列，选择8可查看！10即查看菜单"<<endl;
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
			cout<<"已选择升序排列，选择8可查看！10即查看菜单"<<endl;
		}
		else
		    if(choose==3)	
			cout<<"已返回菜单!请选择0~10,10即查看菜单"<<endl; 
}
void Systerm::statistics()
{
	    	   while(1)
			   {
			   	cout<<"请选择查询科目 1.高数 2.英语 3.计算机 4.返回菜单"<<endl;
			    int choose;
			   	cin>>choose;
        		if(choose<1||choose>3)
				break;		   
		   	    int accout,S11,S2,S3,S4,S5,S6,S7,S8,S9,S10,m,l;
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
					 	cout<<"高数不及格人数为  "<<accout<<endl;
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
                         cout<<"高数   0~9分的人数为"<<S11<<endl;
                    	cout<<"     10~19分的人数为"<<S2<<endl;
                    	cout<<"     20~29分的人数为"<<S3<<endl;
                    	cout<<"     30~39分的人数为"<<S4<<endl;
                    	cout<<"     40~49分的人数为"<<S5<<endl;
                    	cout<<"     50~59分的人数为"<<S6<<endl;
                    	cout<<"     60~69分的人数为"<<S7<<endl;
                    	cout<<"     70~79分的人数为"<<S8<<endl;
                    	cout<<"     80~89分的人数为"<<S9<<endl;
                    	cout<<"     90~100分的人数为"<<S10<<endl;
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
					 	cout<<"英语不及格人数为  "<<accout<<endl;
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
                    	 cout<<"英语   0~9分的人数为"<<S11<<endl;
                    	cout<<"     10~19分的人数为"<<S2<<endl;
                    	cout<<"     20~29分的人数为"<<S3<<endl;
                    	cout<<"     30~39分的人数为"<<S4<<endl;
                    	cout<<"     40~49分的人数为"<<S5<<endl;
                    	cout<<"     50~59分的人数为"<<S6<<endl;
                    	cout<<"     60~69分的人数为"<<S7<<endl;
                    	cout<<"     70~79分的人数为"<<S8<<endl;
                    	cout<<"     80~89分的人数为"<<S9<<endl;
                    	cout<<"     90~100分的人数为"<<S10<<endl;
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
					    cout<<"计算机不及格人数为  "<<accout<<endl;
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
                    	cout<<"计算机   0~9分的人数为"<<S11<<endl;
                    	cout<<"     10~19分的人数为"<<S2<<endl;
                    	cout<<"     20~29分的人数为"<<S3<<endl;
                    	cout<<"     30~39分的人数为"<<S4<<endl;
                    	cout<<"     40~49分的人数为"<<S5<<endl;
                    	cout<<"     50~59分的人数为"<<S6<<endl;
                    	cout<<"     60~69分的人数为"<<S7<<endl;
                    	cout<<"     70~79分的人数为"<<S8<<endl;
                    	cout<<"     80~89分的人数为"<<S9<<endl;
                    	cout<<"     90~100分的人数为"<<S10<<endl;
						break;
				   }
			   }
			   cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
	
}
void Systerm::save()
{
			   char decide[2];		   
	           cout<<"保存至文件？（是/否）"<<endl;
			   cin>>decide;		   
			   if(!strcmp(decide,"是"))
			   {
			   	   cout<<"请选择是否保留原文件内容？（是/否）"<<endl; 
	           	   cin>>decide;
	           	   if(!strcmp(decide,"是"))
	           	   {	
	           	   	   ofstream input("学生成绩表.txt",ios::app);
	           	   	   for(int k=0;k<i;k++)
				   		{
				       		input<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				       		for(int l=0;l<4;l++)
					   		{
					       		input<<setw(10)<<stu[k].score[l];
					   		}
				       		input<<endl;
				   		}
				   		cout<<"保存成功！"<<endl;
					}
					else
					{
						ofstream input("学生成绩表.txt",ios::out);                                
				   		input<<"                                   学生成绩表"<<endl;
	               		input<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		                 		<<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
				   		for(int k=0;k<i;k++)
				   		{
				       		input<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				       		for(int l=0;l<4;l++)
					   		{
					       		input<<setw(10)<<stu[k].score[l];
					   		}
				       		input<<endl;
				   		}
				   		cout<<"保存成功！"<<endl;
				   }
			   }
			   else
			       {
			       	cout<<"保存操作取消！";
				   }
			   cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
} 
void Systerm::putout()
{
	cout<<"                                   学生成绩表"<<endl;
	cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"
		<<setw(10)<<"高数"<<setw(10)<<"英语"<<setw(10)<<"计算机"<<setw(10)<<"平均分"<<endl;
	//cout<<"i="<<i<<endl;	
	for(int k=0;k<i;k++)
	{
		cout<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
		for(int l=0;l<4;l++)
		{
			cout<<setw(10)<<stu[k].score[l];
		}
		cout<<endl;
	}
	cout<<"请继续选择0~10模块,10即查看菜单"<<endl;
}
int main()
{
	    Systerm S1;
again:	S1.menu();
	    char decide[2];
	    while(1)
		{     
		    int choose;
		    cin>>choose;
		    if(choose<1||choose>10)
		   	    break;
		    switch(choose)
			{
		    case 1: 
                  S1.putin();   
			    break;
		    case 2:
			      S1.search();
			    break;
		    case 3:
			    S1.increase();
			    break;
            case 4:
			    S1.cancle();
			    break;
		    case 5:
			    S1.change();
			    break;
		    case 6:
			    S1.turnlist();
			    break;
		    case 7:
			    S1.statistics();
				break;
		    case 8: 
		       S1.putout();
				break;
		    case 9:
			    S1.save();
				break;
		    case 10:
			    S1.menu();
				break;
			}
		}
	    cout<<"是否退出系统？(是/否)"<<endl;
	    cin>>decide;
	    if(!strcmp(decide,"否"))
		    goto again;
		cout<<"谢谢使用，再见！" <<endl; 
	    return 0;
}



 





