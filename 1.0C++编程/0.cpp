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
	cout<<"|                          ѧ���ɼ�����ϵͳ                                  |"<<endl;
	cout<<"|                                                                            |"<<endl; 
	cout<<"|    1.����ѧ����Ϣ�����Ѿ����룬����ļ��ж������ݣ�                        |"<<endl;
	cout<<"|    2.��ѯѧ����Ϣ                                                          |"<<endl;
	cout<<"|    3.����ѧ����Ϣ                                                          |"<<endl;
	cout<<"|    4.ɾ��ѧ����Ϣ                                                          |"<<endl;
	cout<<"|    5.�޸�ѧ���ɼ�                                                          |"<<endl;
	cout<<"|    6.ƽ���ɼ�����                                                          |"<<endl;
	cout<<"|    7.���ֶ�����������������                                                |"<<endl;
    cout<<"|    8.���ѧ����Ϣ                                                          |"<<endl;
	cout<<"|    9.�������ļ�                                                            |"<<endl;
	cout<<"|    0.�˳�ϵͳ                                                              |"<<endl;
	cout<<"|____________________________________________________________________________|"<<endl;
	cout<<" ��ѡ��1~9ģ��:"<<endl;
	struct Student                                         //����Ϣ�����Student�ṹ����
	{
        char number[20];                                   //ѧ��
		char name[20];                                     //����
		char sex[2];                                       //�Ա�
		double score[4];                                   //���Ƴɼ���ƽ����
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
			   cout<<"���������룺ѧ�� ���� �Ա� �����ɼ� Ӣ��ɼ� ������ɼ�"<<endl;	           
	           cin>>stu[i].number>>stu[i].name>>stu[i].sex;                              //����Ϣͨ����������
		       for(j=0;j<3;j++)
			   {
			       cin>>stu[i].score[j];
			   }
			   stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;    //��ƽ����
		       cout<<"��ѡ��1�������������ѡ��"<<endl;
			   i++;                                                                      //��i��¼ѧ������
			   break;
		   case 2:
			   	int m,sign;
				char Snum[20];
				sign=0;
	            cout<<"���������ѧ����ѧ�Ż�����"<<endl;
 	            cin>>Snum;
               	for(m=0;m<i;m++)
				{
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                 //����ѧ��������ѧ��
					{
		            	cout<<"��ѧ����ѧ����ϢΪ"<<endl;
			            cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		                    <<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
			            cout<<setw(10)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
					}
				}
				if(sign!=1)
				{
					cout<<"δ�ҵ���ѧ����Ϣ��"<<endl;
				}
				cout<<"��ѡ��2�������һ�����ѡ��"<<endl;
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
			   cout<<"                                   ѧ���ɼ���"<<endl;
	           cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		             <<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
			   for(k=0;k<i;k++)
			   {
				   cout<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				   for(l=0;l<4;l++)
				   {
					   cout<<setw(10)<<stu[k].score[l];
				   }
				   cout<<endl;
			   }
			   cout<<"�����ѡ��"<<endl;
			   break;
		   case 9:
			   cout<<"�������ļ�����0/1��";
			   int f;
			   cin>>f;
			   if(1)
			   {
				   ofstream input("input.txt",ios::app);                                //��������ļ�
				   input<<"                                   ѧ���ɼ���"<<endl;
	               input<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		                 <<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
				   for(k=0;k<i;k++)
				   {
				       input<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				       for(l=0;l<4;l++)
					   {
					       input<<setw(10)<<stu[k].score[l];
					   }
				       input<<endl;
				   }
				   cout<<"����ɹ���"<<endl;
			   }
			   cout<<"�����ѡ��"<<endl;
			   break;
		}
	}
   		  
	return 0;
}


/*1.ѧ���ɼ�����ϵͳ
(1)���˵�ģ�顣��ģ����Ҫ����ʵ������ϵͳ�����̡��������ṩ�û�ѡ�񲢵��ø�����ģ�顣
(2)����ģ�顣������ʹ��ϵͳʱ��ѧ����Ϣ��Ҫ�Ӽ���������롣��ѧ����Ϣ�Ѿ��������ļ���ʱ���򽫴��ļ��������ݡ�ѧ����Ϣ��ѧ����ѧ�š��������Ա�����ſγɼ�����Ϣ���ɡ�
(3)��ѯģ�顣�û����԰���ѧ����ѧ�Ż��������в��ҡ������ҵ���ѧ���������Ϣ��¼������������Ϣ��������ʾδ�ҵ���
(4)����ģ�顣��Ҫ��ɶ�ѧ����Ϣ��ά�����������Ӽ�¼��ɾ����¼���޸ĳɼ�������ɸ��¼�¼����Ҫ���޸ĵ����ݴ��������ļ��С�
(5)����ģ�顣���ݼ��������ѡ���ѧ����¼��������������򣬲���������Ľ����
(6)ͳ��ģ�顣ͳ�Ƹ��������ε�������������������
(7)���ģ�顣��ѧ����Ϣ��ʾ����Ļ�ϣ������ݼ��������ѡ���硰�Ƿ񱣴浽�ļ�����Y/N����,���Խ�ѧ����Ϣд���ļ��С�*/