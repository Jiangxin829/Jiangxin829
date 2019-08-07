#include<iostream>
#include<cstring>                //字符串操作
#include<iomanip>               //setw()
#include<stdlib.h>              //system()头文件
#include<fstream>               //文件输入流类ifstream和输出流类ofstream
using namespace std;
template <class DataType>
struct Station
{
    char stations[20];
    char arrivetime[20];
    char leavetime[20];
    char length[20];
    Station<DataType>* next;
};
template <class DataType>
struct Train
{
	char beginstation[20];
	char endstation[20];
	int sumstations;
	char begintime[20];
	char endtime[20];
	char trainnumber[20];
	Train<DataType>* next;
	Station<DataType>* line;
};
template <class DataType>
class System
{
public:
	System();
	~System();
	void passenger(){menu2();};
	void manager(){menu1();}
	void input();                     //录入列车信息
	void add();                       //增添列车信息
	void alter();                     //修改列车信息
	void cancle();                    //删除列车信息
	void browse();                    //浏览全部列车信息
	void save();                      //存储数据于文件
	void read();                      //从文件读入列车信息
    void see();                        //浏览全部列车信息
	void find();                       //查询列车
private:
    int account;
	void menu1();
	void menu2();
	Train<DataType> *first;
};
int main()
{
menu:int choose,choice;
    System<char*> S1;
	cout<<" 请选择1~2：";
	while(1)
		{
rechoose:   cin>>choice;
		    if(choice==1)
			{
                S1.passenger();
                S1.read();
                cout<<"   请选择1~3模块："<<endl;
                while(1)
                {
x1:                 cin>>choose;
                    system("cls");
                    if(choose==1) S1.find();
                    if(choose==2) S1.see();
                    if(choose==3)
                    {
                        system("cls");
                        goto menu;
                    }
                    if(choose<1||choose>3)
                    {
                        cout<<"输入不合法！请重新输入：";
                        goto x1;
                    }
                }
			}
            if(choice==2)
            {
                S1.manager();
                while(1)
                {
                    cin>>choose;
                    if(choose<1||choose>7)
                    {
                        cout<<"输入不合法！请重新输入：";
                        goto rechoose;
                    }
                    switch(choose)
                    {
                        case 1:
                            S1.input();
                            break;
                        case 2:
                            S1.add();
                            break;
                        case 3:
                            S1.alter();
                            break;
                        case 4:
                            S1.cancle();
                            break;
                        case 5:
                            S1.browse();
                            break;
                        case 6:
                            S1.save();
                            break;
                        case 7:
                        {
                            system("cls");
                            goto menu;
                        }
                    }

                }
			}
			if(choice<1&&choose>2)
            {
                cout<<"输入不合法！请重新输入：";
                goto menu;
            }
		}
	return 0;
}
template <class DataType>
System<DataType>::System()
{

	cout<<"                       列车查询系统                                         "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"   ★★**********       1.乘客功能               **********★★                 "<<endl;
	cout<<endl;
	cout<<"   ★★**********       2.管理员功能             **********★★                 "<<endl;
 	cout<<"                                                                            "<<endl;
 	account=0;                                          //初始化全局变量：列车数量
}

template <class DataType>
System<DataType>::~System()                         //析构函数 释放空间
{
    while(first!=NULL)
    {
        Train<DataType> *q=first;
        first=first->next;
        delete q;
    }
}

template <class DataType>
void System<DataType>::menu1()
{
    system("cls");
	cout<<"                     列车查询管理员系统                                     "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"   ★★**********      1.录入列车信息             **********★★                "<<endl;
	cout<<endl;
	cout<<"   ★★**********      2.增加列车信息             **********★★                "<<endl;
	cout<<endl;
	cout<<"   ★★**********      3.修改列车信息             **********★★                "<<endl;
	cout<<endl;
	cout<<"   ★★**********      4.删除列车信息             **********★★                "<<endl;
	cout<<endl;
	cout<<"   ★★**********      5.浏览所有列车信息         **********★★                "<<endl;
	cout<<endl;
	cout<<"   ★★**********      6.保存信息至文件           **********★★                "<<endl;
	cout<<endl;
	cout<<"   ★★**********      7.返回上级                 **********★★                "<<endl;
 	cout<<"                                                                            "<<endl;
	cout<<"   请选择1~7："<<endl;
}
template <class DataType>
void System<DataType>::menu2()
{
    system("cls");
	cout<<"                          乘客系统                                          "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"   ★★**********      1.查询列车信息            **********★★                 "<<endl;
	cout<<endl;
	cout<<"   ★★**********      2.浏览所有列车信息        **********★★                 "<<endl;
	cout<<endl;
	cout<<"   ★★**********      3.返回上级                **********★★                 "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<endl;
}
template <class DataType>
void System<DataType>::read()                                      //读取文件中列车信息
{
    int j,k,l;
    char sfile[20];
    int num;
    ifstream read("列车信息表.txt");
    if(!read.is_open())
    {
        cout<<"未找到列车信息文件，请手动输入："<<endl;
        return;
    }
    if(read.is_open())
    {
        read>>num;
        cout<<"读取到"<<num<<"辆列车信息！"<<endl;
        cout<<endl;
        for(j=0;j<8;j++)
        {
            read>>sfile;
        }
        first=new Train<DataType>;
        first->next=NULL;
        Train<DataType> *r=first;
        for(j=0;j<num;j++)
        {
            Train<DataType> *t=new Train<DataType>;                     //工作指针
            read>>account>>t->trainnumber>>t->begintime>>t->endtime>>t->sumstations>>t->beginstation>>t->endstation;
            r->next=t;r=t;
        }
        r->next=NULL;
        Train<DataType> *t;
        t=first->next;
        for(j=0;j<num;j++)
        {
            t->line=new Station<DataType>;
            Station<DataType> *s=t->line;                                  //头指针
            s->next=NULL;
            Station<DataType> *rear=s;                                    //尾指针
            for(l=0;l<5;l++)
                {
                    read>>sfile;
                }
            for(k=0;k<t->sumstations;k++)
            {
                Station<DataType> *p=new Station<DataType>;
                read>>p->stations>>p->arrivetime>>p->leavetime>>p->length;
                rear->next=p;rear=p;
            }
            rear->next=NULL;
            t=t->next;
        }
        read.close();
    }
    system("pause");
}

template <class DataType>
void System<DataType>::input()                                     //录入列车车次信息
{
	int i,choose;
	char sta[10];
	cout<<"请选择 1.手动输入，2.从文件导入：";
put:cin>>choose;
    cout<<endl;
	if(choose!=1&&choose!=2)
    {
        cout<<"输入不合法，请重新输入：";
        cout<<endl;
        goto put;
    }
    if(choose==2)
    {
        read();
        manager();
        return;
    }
	first=new Train<DataType>;
    first->next=NULL;
con:cout<<"   请输入列车信息，列车车次、发车时刻、到达时刻、起始站、终点站："<<endl;
	while(1)
	{
	    Train<DataType> *t=new Train<DataType>;                     //工作指针
        t->line=new Station<DataType>;
        t->sumstations=0;
        Station<DataType> *s=t->line;
		cin>>t->trainnumber>>t->begintime>>t->endtime>>t->beginstation>>t->endstation;
		cout<<endl;
		account++;
		Station<DataType> *rear=s;
		cout<<"   请输入一个途经站点名(输入#结束）：";
		while(1)
        {
            Station<DataType> *p=new Station<DataType>;             //工作指针
            cin>>sta;
            if(!strcmp(sta,"#")) break;
            strcpy(p->stations,sta);
            cout<<"   本站到站时间、发车时间、上个站到本站运行里程："<<endl;//！！！！改为尾插法
            cin>>p->arrivetime>>p->leavetime>>p->length;
            cout<<endl;
            rear->next=p;rear=p;
            t->sumstations++;
            cout<<"   请选择继续输入途经站点或输入#结束：";
        }
		rear->next=NULL;
a5:		cout<<"   输入1继续输入列车信息，输入0返回至菜单：";
	    cin>>i;
	    cout<<endl;
        t->next=first->next;
        first->next=t;
		if(i==0)
        {
            manager();
            break;
        }
        if(i!=0&&i!=1)
        {
        	cout<<"输入不合法，请重新输入：";
        	goto a5;
		}
		if(i==1)
        {
            goto con;
        }
	}
}
template<class DataType>
void System<DataType>::add()                             //修改列车信息
{
	int i;
	char sta[10];
c6:	cout<<"   请输入列车信息，列车车次、发车时刻、到达时刻、起始站、终点站："<<endl;
	while(1)
	{
	    Train<DataType> *t=new Train<DataType>;                     //工作指针
        t->line=new Station<DataType>;
        Station<DataType> *s=t->line;
		cin>>t->trainnumber>>t->begintime>>t->endtime>>t->beginstation>>t->endstation;
		account++;
		Station<DataType> *rear=s;
		cout<<"   请输入一个途经站点名(输入#结束）：";
		while(1)
        {
            Station<DataType> *p=new Station<DataType>;             //工作指针
            t->sumstations=0;
            cin>>sta;
            if(!strcmp(sta,"#")) break;
            strcpy(p->stations,sta);
            cout<<"   本站到站时间、发车时间、上个站到本站运行里程："<<endl;//！！！！改为尾插法
            cin>>p->arrivetime>>p->leavetime>>p->length;
            rear->next=p;rear=p;
            t->sumstations++;
            cout<<"   请选择继续输入途经站点或输入#结束：";
        }
		rear->next=NULL;
a1:		cout<<"   输入1继续输入列车信息，输入0返回至菜单：";
	    cin>>i;
        t->next=first->next;
        first->next=t;
		if(i==0)
        {
            manager();
            break;
        }
        if(i!=0&&i!=1)
        {
        	cout<<"输入不合法，请重新输入：";
        	goto a1;
		}
		if(i==1)
        {
            goto c6;
        }
	}
}

template <class DataType>
void System<DataType>::alter()                                //修改列车信息
{
    int choose;
    char sta[10];
    Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;
as: cout<<"   请输入修改列车车次(输入#返回上级)：";
res:cin>>sta;
	int flag=0;
    if(!strcmp(sta,"#"))
        return;
    while(t!=NULL)
    {
        if(!strcmp(t->trainnumber,sta))
        {
            cout<<"   找到该车次："<<endl;
            cout<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"始末站点"<<endl;
            cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<endl;
            cout<<setw(20)<<"途经站点名称"<<setw(20)<<"到站时间"<<setw(20)<<"发车时间"<<setw(20)<<"运行里程"<<endl;
			p=t->line->next;
			while(p!=NULL)
        	{
            	cout<<setw(20)<<p->stations<<setw(20)<<p->arrivetime<<setw(20)<<p->leavetime<<setw(20)<<p->length<<endl;
            	p=p->next;
        	}
			cout<<"请选择修改该列车 1.大略信息，2.途经站点信息,0.返回至菜单：";
            cin>>choose;
            if(choose==0)
            {
                manager();
                break;
            }
            if(choose==1)
            {
            	p=t->line->next;                  //注意错误
                cout<<"请重新输入该车次信息：列车车次、发车时刻、到达时刻、起始站、终点站："<<endl;
                cin>>t->trainnumber>>t->begintime>>t->endtime>>t->beginstation>>t->endstation;
                cout<<"输入1/0选择是/否继续修改途经站点信息:";
                cin>>choose;
                if(choose==1)
                {
                    t->sumstations=0;
                	while(p!=NULL)
                	{
                		cout<<"请重新输入途经站点信息：本站名称、到站时间、发车时间、运行里程："<<endl;
						cin>>p->stations>>p->arrivetime>>p->leavetime>>p->length;
						t->sumstations++;
						p=p->next;

					}
                }
            }
            if(choose==2)
            {
                t->sumstations=0;
            	p=t->line->next;
                cout<<"请重新输入途经站点信息：本站名称、到站时间、发车时间、运行里程："<<endl;
                while(p!=NULL)
                {
                	cin>>p->stations>>p->arrivetime>>p->leavetime>>p->length;
                	t->sumstations++;
                	p=p->next;
				}
            }
            flag=1;
            cout<<"修改完成，选择 1.继续查询修改列车、0.返回至菜单：";
            cin>>choose;
            if(choose==1) goto as;
            if(choose==0)
			{
				manager();
				return;
			}
        }
        t=t->next;
    }
    if(flag==0)
    {
        cout<<"未找到该车次！输入可再次查找或输入#退出";
        goto res;
    }
}
template <class DataType>
void System<DataType>::cancle()                            //删除操作（不足：输入错误提示未达成导致报错）
{
    int i;
re: Train<DataType> *t=first;
    char sta[10];
    cout<<"请输入要删除的列车车次,输入0返回至菜单：";
    int flag=0;
    cin>>sta;
    if(!strcmp("0",sta))
    {
        manager();
        return;
    }
    while(t!=NULL)
    {
        Train<DataType> *p=t->next;
        if(!strcmp(p->trainnumber,sta))
        {
            cout<<"   找到该车次："<<endl;
            cout<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"始末站点"<<endl;
            cout<<setw(20)<<p->trainnumber<<setw(20)<<p->begintime<<setw(20)<<p->endtime<<setw(15)<<p->beginstation<<"-"<<p->endstation<<endl;
            cout<<"请选择是/否1/0删除:";
            cin>>i;
            if(i==1)
            {
                t->next=p->next;
                delete p;
                cout<<"删除成功！";
                flag=1;
                account--;
            }
            if(i==0)
            {
                cout<<"删除操作取消！"<<endl;
                flag=1;
            }
            break;
        }
        t=t->next;
    }
    if(flag==0)
    {
        cout<<"未找到该车次，请选择 1.继续删除、0.返回至菜单:";
        cin>>i;
        if(i==1)
            goto re;
        if(i==0)
        {
            manager();
            return;
        }
    }
    if(flag==1)
    {
        cout<<"请选择是否继续 1.继续 、0.返回菜单：";
    }
    cin>>i;
    if(i==1)
        goto re;
    if(i==0)
    {
        manager();
        return;
    }
}
template <class DataType>
void System<DataType>::browse()                               //浏览全部车次信息
{
    cout<<"   查询到的列车数量为："<<account<<endl;
    int m;
    int i=1,n=1;
    Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;

    cout<<setw(65)<<"列车全部查询结果"<<endl;
    cout<<endl;
	cout<<setw(20)<<"序号"<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"站点个数"<<setw(10)<<"起始站"<<setw(10)<<"终止站"<<endl;
	while(t!=NULL)
    {
        cout<<setw(20)<<i<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(20)<<t->sumstations<<setw(10)<<t->beginstation<<setw(10)<<t->endstation<<endl;
        t=t->next;
        i++;
    }
    cout<<"可选择序号查看火车途经站点，输入0返回至菜单："<<endl;
rev:cin>>m;
//  cout<<"出错点!";
	if(m==0)
    {
        manager();
        return;
    }
    if(m!=0)
    {
        t=first->next;
        while(n<m)
        {
            t=t->next;
            n++;
        }
		p=t->line->next;
        cout<<setw(40)<<"第 "<<t->trainnumber<<" 次列车途经站点"<<endl;
		cout<<endl;
        cout<<setw(20)<<"站点名称"<<setw(20)<<"到站时间"<<setw(20)<<"发车时间"<<setw(20)<<"运行里程"<<endl;
        while(p!=NULL)
        {
            cout<<setw(20)<<p->stations<<setw(20)<<p->arrivetime<<setw(20)<<p->leavetime<<setw(20)<<p->length<<endl;
            p=p->next;
        }
        cout<<"输入序号可继续查看火车途经点，输入0返回菜单：";
    }
    goto rev;
}
template<class DataType>
void System<DataType>::save()                     //保存信息至文件
{
	int decide;
	int i=1;
	cout<<"保存至文件？（是/否 1/0）"<<endl;
	cin>>decide;
	Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;
	if(decide==1)
	{

			ofstream input("列车信息表.txt",ios::out);
			input<<setw(63)<<account<<setw(1)<<"辆列车信息大略表"<<endl;
			input<<endl;
			input<<setw(20)<<"序号"<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"站点个数"<<setw(10)<<"起始站"<<setw(10)<<"终止站"<<endl;
			while(t!=NULL)
            {
                input<<setw(20)<<i<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(20)<<t->sumstations<<setw(10)<<t->beginstation<<setw(10)<<t->endstation<<endl;
                i++;
                t=t->next;
            }
            t=first->next;
            while(t!=NULL)
            {
                p=t->line->next;
                input<<setw(40)<<"第"<<setw(1)<<t->trainnumber<<setw(1)<<"次列车途经站点"<<endl;
                input<<endl;
                input<<setw(20)<<"站点名称"<<setw(20)<<"到站时间"<<setw(20)<<"发车时间"<<setw(20)<<"运行里程"<<endl;
                while(p!=NULL)
                {
                    input<<setw(20)<<p->stations<<setw(20)<<p->arrivetime<<setw(20)<<p->leavetime<<setw(20)<<p->length<<endl;
                    input<<endl;
                    p=p->next;
                }
                t=t->next;
                input<<endl;
            }

			t=first->next;
			cout<<"保存成功！"<<endl;
	}
	else
	{
		cout<<"保存操作取消！";
	}
	cout<<"\t"<<"\t"<<"可返回菜单"<<endl;
	system("pause");
	manager();
	return;
}

template <class DataType>
void System<DataType>::see()             //浏览全部车次信息
{
    int n=1;
	int i;
    Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;
	cout<<endl<<endl<<endl;
    cout<<setw(55)<<"列车全部查询结果"<<endl;
    cout<<endl;
	while(t!=NULL)
    {
		cout<<endl;
		cout<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"始末站点"<<endl;
        cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<" "<<endl;
		p=t->line->next;
		cout<<endl<<endl<<endl;
        cout<<setw(40)<<"第"<<t->trainnumber<<"次列车途经站点"<<endl<<endl;
		cout<<endl;
        cout<<setw(20)<<"站点名称"<<setw(20)<<"到站时间"<<setw(20)<<"发车时间"<<setw(20)<<"运行里程"<<endl;
        while(p!=NULL)
        {
            cout<<setw(20)<<p->stations<<setw(20)<<p->arrivetime<<setw(20)<<p->leavetime<<setw(20)<<p->length<<" "<<endl;
			cout<<endl;
            p=p->next;
        }
		t=t->next;
		system("pause");
		system("cls");
		cout<<endl;
	}
    passenger();
}

template <class DataType>        //查找
void System<DataType>::find()
{
    int p;
	cout<<endl<<endl<<endl;
	cout<<"   请输入查找的方式：1.按照列车车次查询      "<<endl;
	cout<<"                     2.通过站点查询          "<<endl;
    char sta[20];
	char sta2[20];
	Train<DataType> *t;
	t=first->next;
	Station<DataType> *s;
	int choose;
	cin>>choose;
	switch(choose)
	{
	case 1:
            p=0;
		    cout<<"   请输入查找的列车车次(输入#返回上级)：";cout<<" ";
            cin>>sta;
            if(!strcmp(sta,"#"))
				break;
            while(t!=NULL)
			{
                if(!strcmp(t->trainnumber,sta))
				{
				    system("cls");
				    cout<<endl<<endl<<endl;
					cout<<"   找到该车次："<<endl;
					cout<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"途经站点"<<endl;
					cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<endl;
			        p=1;
				}
                t=t->next;
			}
            if(p==0)
            {
                system("cls");
                cout<<endl<<endl<<endl;
                cout<<setw(40)<<"未找到该车次！"<<endl;
            }
            cout<<setw(40)<<"输入1继续查询列车信息,输入0返回菜单:";
            cin>>choose;
            if(choose==1)
            {
                system("cls");
                find();
            }
            if(choose==0)
            {
                passenger();
            }
            break;
	case 2:
		cout<<"      请输入您的始发站：   ";cout<<" ";
		cin>>sta;
		cout<<endl;
		cout<<"      请输入您的目的地：   ";cout<<" ";
		cin>>sta2;
		cout<<endl;
		p=0;
		t=first->next;
        while(t!=NULL)
		{
			s=t->line->next;
			while(s!=NULL)
            {
                if(!strcmp(s->stations,sta))
                {
                    while(s!=NULL)
                    {
                        if(!strcmp(s->stations,sta2))
                        {
                            system("cls");
                            cout<<endl<<endl;
                            cout<<"查询到列车:"<<endl;
                            cout<<setw(20)<<"列车车次"<<setw(20)<<"发车时刻"<<setw(20)<<"到达时刻"<<setw(20)<<"始末站点"<<endl;
                            cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<endl;
                            p=1;
                            goto p1;
                        }
                        s=s->next;
                    }
                }
                s=s->next;
            }
			t=t->next;
		}
		if(p==0)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<setw(40)<<"未找到该车次！"<<endl;
		}
p1:	    cout<<setw(40)<<"输入1/0选择是否继续查询列车信息:";
        cin>>choose;
        if(choose==1)
		{
			system("cls");
			find();
		}
		if(choose==0)
		{
			passenger();
		}
		break;
	}
}

