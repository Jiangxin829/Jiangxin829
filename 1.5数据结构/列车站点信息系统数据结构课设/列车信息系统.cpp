#include<iostream>
#include<cstring>                //�ַ�������
#include<iomanip>               //setw()
#include<stdlib.h>              //system()ͷ�ļ�
#include<fstream>               //�ļ���������ifstream���������ofstream
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
	void input();                     //¼���г���Ϣ
	void add();                       //�����г���Ϣ
	void alter();                     //�޸��г���Ϣ
	void cancle();                    //ɾ���г���Ϣ
	void browse();                    //���ȫ���г���Ϣ
	void save();                      //�洢�������ļ�
	void read();                      //���ļ������г���Ϣ
    void see();                        //���ȫ���г���Ϣ
	void find();                       //��ѯ�г�
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
	cout<<" ��ѡ��1~2��";
	while(1)
		{
rechoose:   cin>>choice;
		    if(choice==1)
			{
                S1.passenger();
                S1.read();
                cout<<"   ��ѡ��1~3ģ�飺"<<endl;
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
                        cout<<"���벻�Ϸ������������룺";
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
                        cout<<"���벻�Ϸ������������룺";
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
                cout<<"���벻�Ϸ������������룺";
                goto menu;
            }
		}
	return 0;
}
template <class DataType>
System<DataType>::System()
{

	cout<<"                       �г���ѯϵͳ                                         "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"   ���**********       1.�˿͹���               **********���                 "<<endl;
	cout<<endl;
	cout<<"   ���**********       2.����Ա����             **********���                 "<<endl;
 	cout<<"                                                                            "<<endl;
 	account=0;                                          //��ʼ��ȫ�ֱ������г�����
}

template <class DataType>
System<DataType>::~System()                         //�������� �ͷſռ�
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
	cout<<"                     �г���ѯ����Աϵͳ                                     "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"   ���**********      1.¼���г���Ϣ             **********���                "<<endl;
	cout<<endl;
	cout<<"   ���**********      2.�����г���Ϣ             **********���                "<<endl;
	cout<<endl;
	cout<<"   ���**********      3.�޸��г���Ϣ             **********���                "<<endl;
	cout<<endl;
	cout<<"   ���**********      4.ɾ���г���Ϣ             **********���                "<<endl;
	cout<<endl;
	cout<<"   ���**********      5.��������г���Ϣ         **********���                "<<endl;
	cout<<endl;
	cout<<"   ���**********      6.������Ϣ���ļ�           **********���                "<<endl;
	cout<<endl;
	cout<<"   ���**********      7.�����ϼ�                 **********���                "<<endl;
 	cout<<"                                                                            "<<endl;
	cout<<"   ��ѡ��1~7��"<<endl;
}
template <class DataType>
void System<DataType>::menu2()
{
    system("cls");
	cout<<"                          �˿�ϵͳ                                          "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"   ���**********      1.��ѯ�г���Ϣ            **********���                 "<<endl;
	cout<<endl;
	cout<<"   ���**********      2.��������г���Ϣ        **********���                 "<<endl;
	cout<<endl;
	cout<<"   ���**********      3.�����ϼ�                **********���                 "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<endl;
}
template <class DataType>
void System<DataType>::read()                                      //��ȡ�ļ����г���Ϣ
{
    int j,k,l;
    char sfile[20];
    int num;
    ifstream read("�г���Ϣ��.txt");
    if(!read.is_open())
    {
        cout<<"δ�ҵ��г���Ϣ�ļ������ֶ����룺"<<endl;
        return;
    }
    if(read.is_open())
    {
        read>>num;
        cout<<"��ȡ��"<<num<<"���г���Ϣ��"<<endl;
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
            Train<DataType> *t=new Train<DataType>;                     //����ָ��
            read>>account>>t->trainnumber>>t->begintime>>t->endtime>>t->sumstations>>t->beginstation>>t->endstation;
            r->next=t;r=t;
        }
        r->next=NULL;
        Train<DataType> *t;
        t=first->next;
        for(j=0;j<num;j++)
        {
            t->line=new Station<DataType>;
            Station<DataType> *s=t->line;                                  //ͷָ��
            s->next=NULL;
            Station<DataType> *rear=s;                                    //βָ��
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
void System<DataType>::input()                                     //¼���г�������Ϣ
{
	int i,choose;
	char sta[10];
	cout<<"��ѡ�� 1.�ֶ����룬2.���ļ����룺";
put:cin>>choose;
    cout<<endl;
	if(choose!=1&&choose!=2)
    {
        cout<<"���벻�Ϸ������������룺";
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
con:cout<<"   �������г���Ϣ���г����Ρ�����ʱ�̡�����ʱ�̡���ʼվ���յ�վ��"<<endl;
	while(1)
	{
	    Train<DataType> *t=new Train<DataType>;                     //����ָ��
        t->line=new Station<DataType>;
        t->sumstations=0;
        Station<DataType> *s=t->line;
		cin>>t->trainnumber>>t->begintime>>t->endtime>>t->beginstation>>t->endstation;
		cout<<endl;
		account++;
		Station<DataType> *rear=s;
		cout<<"   ������һ��;��վ����(����#��������";
		while(1)
        {
            Station<DataType> *p=new Station<DataType>;             //����ָ��
            cin>>sta;
            if(!strcmp(sta,"#")) break;
            strcpy(p->stations,sta);
            cout<<"   ��վ��վʱ�䡢����ʱ�䡢�ϸ�վ����վ������̣�"<<endl;//����������Ϊβ�巨
            cin>>p->arrivetime>>p->leavetime>>p->length;
            cout<<endl;
            rear->next=p;rear=p;
            t->sumstations++;
            cout<<"   ��ѡ���������;��վ�������#������";
        }
		rear->next=NULL;
a5:		cout<<"   ����1���������г���Ϣ������0�������˵���";
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
        	cout<<"���벻�Ϸ������������룺";
        	goto a5;
		}
		if(i==1)
        {
            goto con;
        }
	}
}
template<class DataType>
void System<DataType>::add()                             //�޸��г���Ϣ
{
	int i;
	char sta[10];
c6:	cout<<"   �������г���Ϣ���г����Ρ�����ʱ�̡�����ʱ�̡���ʼվ���յ�վ��"<<endl;
	while(1)
	{
	    Train<DataType> *t=new Train<DataType>;                     //����ָ��
        t->line=new Station<DataType>;
        Station<DataType> *s=t->line;
		cin>>t->trainnumber>>t->begintime>>t->endtime>>t->beginstation>>t->endstation;
		account++;
		Station<DataType> *rear=s;
		cout<<"   ������һ��;��վ����(����#��������";
		while(1)
        {
            Station<DataType> *p=new Station<DataType>;             //����ָ��
            t->sumstations=0;
            cin>>sta;
            if(!strcmp(sta,"#")) break;
            strcpy(p->stations,sta);
            cout<<"   ��վ��վʱ�䡢����ʱ�䡢�ϸ�վ����վ������̣�"<<endl;//����������Ϊβ�巨
            cin>>p->arrivetime>>p->leavetime>>p->length;
            rear->next=p;rear=p;
            t->sumstations++;
            cout<<"   ��ѡ���������;��վ�������#������";
        }
		rear->next=NULL;
a1:		cout<<"   ����1���������г���Ϣ������0�������˵���";
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
        	cout<<"���벻�Ϸ������������룺";
        	goto a1;
		}
		if(i==1)
        {
            goto c6;
        }
	}
}

template <class DataType>
void System<DataType>::alter()                                //�޸��г���Ϣ
{
    int choose;
    char sta[10];
    Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;
as: cout<<"   �������޸��г�����(����#�����ϼ�)��";
res:cin>>sta;
	int flag=0;
    if(!strcmp(sta,"#"))
        return;
    while(t!=NULL)
    {
        if(!strcmp(t->trainnumber,sta))
        {
            cout<<"   �ҵ��ó��Σ�"<<endl;
            cout<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"ʼĩվ��"<<endl;
            cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<endl;
            cout<<setw(20)<<";��վ������"<<setw(20)<<"��վʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"�������"<<endl;
			p=t->line->next;
			while(p!=NULL)
        	{
            	cout<<setw(20)<<p->stations<<setw(20)<<p->arrivetime<<setw(20)<<p->leavetime<<setw(20)<<p->length<<endl;
            	p=p->next;
        	}
			cout<<"��ѡ���޸ĸ��г� 1.������Ϣ��2.;��վ����Ϣ,0.�������˵���";
            cin>>choose;
            if(choose==0)
            {
                manager();
                break;
            }
            if(choose==1)
            {
            	p=t->line->next;                  //ע�����
                cout<<"����������ó�����Ϣ���г����Ρ�����ʱ�̡�����ʱ�̡���ʼվ���յ�վ��"<<endl;
                cin>>t->trainnumber>>t->begintime>>t->endtime>>t->beginstation>>t->endstation;
                cout<<"����1/0ѡ����/������޸�;��վ����Ϣ:";
                cin>>choose;
                if(choose==1)
                {
                    t->sumstations=0;
                	while(p!=NULL)
                	{
                		cout<<"����������;��վ����Ϣ����վ���ơ���վʱ�䡢����ʱ�䡢������̣�"<<endl;
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
                cout<<"����������;��վ����Ϣ����վ���ơ���վʱ�䡢����ʱ�䡢������̣�"<<endl;
                while(p!=NULL)
                {
                	cin>>p->stations>>p->arrivetime>>p->leavetime>>p->length;
                	t->sumstations++;
                	p=p->next;
				}
            }
            flag=1;
            cout<<"�޸���ɣ�ѡ�� 1.������ѯ�޸��г���0.�������˵���";
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
        cout<<"δ�ҵ��ó��Σ�������ٴβ��һ�����#�˳�";
        goto res;
    }
}
template <class DataType>
void System<DataType>::cancle()                            //ɾ�����������㣺���������ʾδ��ɵ��±���
{
    int i;
re: Train<DataType> *t=first;
    char sta[10];
    cout<<"������Ҫɾ�����г�����,����0�������˵���";
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
            cout<<"   �ҵ��ó��Σ�"<<endl;
            cout<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"ʼĩվ��"<<endl;
            cout<<setw(20)<<p->trainnumber<<setw(20)<<p->begintime<<setw(20)<<p->endtime<<setw(15)<<p->beginstation<<"-"<<p->endstation<<endl;
            cout<<"��ѡ����/��1/0ɾ��:";
            cin>>i;
            if(i==1)
            {
                t->next=p->next;
                delete p;
                cout<<"ɾ���ɹ���";
                flag=1;
                account--;
            }
            if(i==0)
            {
                cout<<"ɾ������ȡ����"<<endl;
                flag=1;
            }
            break;
        }
        t=t->next;
    }
    if(flag==0)
    {
        cout<<"δ�ҵ��ó��Σ���ѡ�� 1.����ɾ����0.�������˵�:";
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
        cout<<"��ѡ���Ƿ���� 1.���� ��0.���ز˵���";
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
void System<DataType>::browse()                               //���ȫ��������Ϣ
{
    cout<<"   ��ѯ�����г�����Ϊ��"<<account<<endl;
    int m;
    int i=1,n=1;
    Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;

    cout<<setw(65)<<"�г�ȫ����ѯ���"<<endl;
    cout<<endl;
	cout<<setw(20)<<"���"<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"վ�����"<<setw(10)<<"��ʼվ"<<setw(10)<<"��ֹվ"<<endl;
	while(t!=NULL)
    {
        cout<<setw(20)<<i<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(20)<<t->sumstations<<setw(10)<<t->beginstation<<setw(10)<<t->endstation<<endl;
        t=t->next;
        i++;
    }
    cout<<"��ѡ����Ų鿴��;��վ�㣬����0�������˵���"<<endl;
rev:cin>>m;
//  cout<<"�����!";
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
        cout<<setw(40)<<"�� "<<t->trainnumber<<" ���г�;��վ��"<<endl;
		cout<<endl;
        cout<<setw(20)<<"վ������"<<setw(20)<<"��վʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"�������"<<endl;
        while(p!=NULL)
        {
            cout<<setw(20)<<p->stations<<setw(20)<<p->arrivetime<<setw(20)<<p->leavetime<<setw(20)<<p->length<<endl;
            p=p->next;
        }
        cout<<"������ſɼ����鿴��;���㣬����0���ز˵���";
    }
    goto rev;
}
template<class DataType>
void System<DataType>::save()                     //������Ϣ���ļ�
{
	int decide;
	int i=1;
	cout<<"�������ļ�������/�� 1/0��"<<endl;
	cin>>decide;
	Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;
	if(decide==1)
	{

			ofstream input("�г���Ϣ��.txt",ios::out);
			input<<setw(63)<<account<<setw(1)<<"���г���Ϣ���Ա�"<<endl;
			input<<endl;
			input<<setw(20)<<"���"<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"վ�����"<<setw(10)<<"��ʼվ"<<setw(10)<<"��ֹվ"<<endl;
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
                input<<setw(40)<<"��"<<setw(1)<<t->trainnumber<<setw(1)<<"���г�;��վ��"<<endl;
                input<<endl;
                input<<setw(20)<<"վ������"<<setw(20)<<"��վʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"�������"<<endl;
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
			cout<<"����ɹ���"<<endl;
	}
	else
	{
		cout<<"�������ȡ����";
	}
	cout<<"\t"<<"\t"<<"�ɷ��ز˵�"<<endl;
	system("pause");
	manager();
	return;
}

template <class DataType>
void System<DataType>::see()             //���ȫ��������Ϣ
{
    int n=1;
	int i;
    Train<DataType> *t;
    Station<DataType> *p;
    t=first->next;
	cout<<endl<<endl<<endl;
    cout<<setw(55)<<"�г�ȫ����ѯ���"<<endl;
    cout<<endl;
	while(t!=NULL)
    {
		cout<<endl;
		cout<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"ʼĩվ��"<<endl;
        cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<" "<<endl;
		p=t->line->next;
		cout<<endl<<endl<<endl;
        cout<<setw(40)<<"��"<<t->trainnumber<<"���г�;��վ��"<<endl<<endl;
		cout<<endl;
        cout<<setw(20)<<"վ������"<<setw(20)<<"��վʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"�������"<<endl;
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

template <class DataType>        //����
void System<DataType>::find()
{
    int p;
	cout<<endl<<endl<<endl;
	cout<<"   ��������ҵķ�ʽ��1.�����г����β�ѯ      "<<endl;
	cout<<"                     2.ͨ��վ���ѯ          "<<endl;
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
		    cout<<"   ��������ҵ��г�����(����#�����ϼ�)��";cout<<" ";
            cin>>sta;
            if(!strcmp(sta,"#"))
				break;
            while(t!=NULL)
			{
                if(!strcmp(t->trainnumber,sta))
				{
				    system("cls");
				    cout<<endl<<endl<<endl;
					cout<<"   �ҵ��ó��Σ�"<<endl;
					cout<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<";��վ��"<<endl;
					cout<<setw(20)<<t->trainnumber<<setw(20)<<t->begintime<<setw(20)<<t->endtime<<setw(15)<<t->beginstation<<"-"<<t->endstation<<endl;
			        p=1;
				}
                t=t->next;
			}
            if(p==0)
            {
                system("cls");
                cout<<endl<<endl<<endl;
                cout<<setw(40)<<"δ�ҵ��ó��Σ�"<<endl;
            }
            cout<<setw(40)<<"����1������ѯ�г���Ϣ,����0���ز˵�:";
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
		cout<<"      ����������ʼ��վ��   ";cout<<" ";
		cin>>sta;
		cout<<endl;
		cout<<"      ����������Ŀ�ĵأ�   ";cout<<" ";
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
                            cout<<"��ѯ���г�:"<<endl;
                            cout<<setw(20)<<"�г�����"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"ʼĩվ��"<<endl;
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
			cout<<setw(40)<<"δ�ҵ��ó��Σ�"<<endl;
		}
p1:	    cout<<setw(40)<<"����1/0ѡ���Ƿ������ѯ�г���Ϣ:";
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

