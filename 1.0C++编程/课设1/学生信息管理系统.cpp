#include<iostream>
using namespace std;
#include<string.h> 
#include<fstream>
#include<iomanip>
struct Student                                         //����Ϣ�����Student�ṹ����
{
    char number[20];                                   //ѧ��
    char name[20];                                     //����
	char sex[20];                                       //�Ա�
	int score[4];                                   //���Ƴɼ���ƽ����
};
void menu()
{
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"|                          ѧ���ɼ�����ϵͳ                                  |"<<endl;
	cout<<"|                                                                            |"<<endl; 
	cout<<"|    1.����ѧ����Ϣ�����Ѿ����룬��ѡ����ļ��ж������ݣ�                    |"<<endl;
	cout<<"|    2.��ѯѧ����Ϣ                                                          |"<<endl;
	cout<<"|    3.����ѧ����Ϣ                                                          |"<<endl;
	cout<<"|    4.ɾ��ѧ����Ϣ                                                          |"<<endl;
	cout<<"|    5.�޸�ѧ���ɼ�                                                          |"<<endl;
	cout<<"|    6.ƽ���ɼ�����                                                          |"<<endl;
	cout<<"|    7.���ֶ�����������������                                                |"<<endl;
    cout<<"|    8.���ѧ����Ϣ                                                          |"<<endl;
    cout<<"|    9.�������ļ�                                                            |"<<endl;
	cout<<"|    10.�鿴�˵�                                                             |"<<endl;
	cout<<"|    0.�˳�ϵͳ                                                              |"<<endl;
	cout<<"|____________________________________________________________________________|"<<endl;
	cout<<" ��ѡ��0~10ģ��:"<<endl;
}
void average(Student stu[],int i)
{
	cout<<"��ѡ��1.�������� 2.�������� 3.���ز˵�"<<endl;
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
				stu[i]=stu[t];                     //�˴�stu[i]����ת������
				stu[t]=stu[k];
				stu[k]=stu[i];
			}
			t++;			
		}
		cout<<"��ѡ�������У�ѡ��8�ɲ鿴��"<<endl;
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
					stu[i]=stu[t];                     //�˴�stu[i]����ת������
					stu[t]=stu[k];
					stu[k]=stu[i];
				}
				t++;			
			}
			cout<<"��ѡ���������У�ѡ��8�ɲ鿴��"<<endl;
		}
		else
		    if(choose==3)	
			cout<<"�ѷ��ز˵�!��ѡ��0~10"<<endl; 
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
		   cout<<"��ѡ��1.����ѧ���ɼ� 2.���ļ����� 3.�������˵�"<<endl;
		   	   cin>>choose;
		   	   if(choose==3)
				  goto again; 
		   	   if (choose==1)
		   	   {
		   	   	    while(1)
		   	   	    { 		   	   	    	
                    	if(choose!=1)
			        	break;
add:           	   		cout<<"���������룺ѧ�� ���� �Ա� �����ɼ� Ӣ��ɼ� ������ɼ�"<<endl;	           
	           			cin>>stu[i].number>>stu[i].name>>stu[i].sex;                              //����Ϣͨ����������
		       			for(j=0;j<3;j++)
			   			{
			       			cin>>stu[i].score[j];
			   			}
			   			stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;    //��ƽ����			   
		       			cout<<"������ɣ���ѡ��1��������,����0�������˵�"<<endl;
						cin>>choose;
			   			i++;
					} 
					cout<<"�����ѡ��0~10ģ��"<<endl;                                                                  //��i��¼ѧ������
			    } 
				else
				    if(choose==2)
					{
						ifstream read("ѧ���ɼ���.txt"); 
						if(!read.is_open())
						{
							cout<<"�ļ��򿪴���"<<endl;
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
							cout<<"����ѧ������Ϊ��"<<j-1<<endl;
							i=j-1;
							cout<<"��ȡ��ɣ�������8�鿴"<<endl;
						}
					}                                                               
			    break;
		   case 2:
				sign=0;
	            cout<<"���������ѧ����ѧ�Ż����� ����'����'���˵�"<<endl;
 	            cin>>Snum;
 	            if(!strcmp(Snum,"����")) 
 	                goto again; 
               	for(m=0;m<i;m++)
				{
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                  //����ѧ��������ѧ��
					{
		            	cout<<"��ѧ����ѧ����ϢΪ:"<<endl;
			            cout<<setw(23)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		                    <<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
			            cout<<setw(23)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
						break;
					}					
				}
				if(sign!=1)
				{
					cout<<"δ�ҵ���ѧ����Ϣ��"<<endl;
				}
				cout<<"��ѡ��2�������һ�����ѡ��"<<endl;
			    break;
		   case 3:
			   goto add;
			   break;
		   case 4:
			   cout<<"������Ҫɾ����ѧ��ѧ�Ż�����������'����'���˵�"<<endl;
			   sign=0;
			   cin>>Snum;
			   if(!strcmp(Snum,"����")) 
 	                goto again; 
               for(m=0;m<i;m++)
			   {
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                 //����ѧ��������ѧ��
					{
		            	cout<<"�ҵ���ѧ����ѧ����ϢΪ:"<<endl;
			            cout<<setw(23)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		                    <<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
			            cout<<setw(23)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
						cout<<"��ȷ���Ƿ�ɾ����ѧ����Ϣ����/��"<<endl;
						cin>>decide;
						if(!strcmp(decide,"��"))
						{
							for(n=m;n<i;n++)
							{
								stu[n]=stu[n+1];
							}
						    cout<<"ɾ����ϣ�������8�鿴"<<endl;
							i=i-1;
						}
						else
							cout<<"ɾ������ȡ����"<<endl;						
						break;
					}
			   }
			   if(sign!=1)
			   {
				   cout<<"δ�ҵ���ѧ����Ϣ��"<<endl;
			   }
			   cout<<"�����ѡ��0~10ģ��"<<endl; 
			   break;
		   case 5:
			   cout<<"������Ҫ�޸ĵ�ѧ��ѧ�Ż�����������'����'���˵�"<<endl;
               sign=0;
			   cin>>Snum;
			   if(!strcmp(Snum,"����")) 
 	                goto again; 
               for(m=0;m<i;m++)
			   {
	            	if(!strcmp(Snum,stu[m].number)||!strcmp(Snum,stu[m].name))                 //����ѧ��������ѧ��
					{
		            	cout<<"�ҵ���ѧ����ѧ����ϢΪ:"<<endl;
			            cout<<setw(23)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		                    <<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
			            cout<<setw(23)<<stu[m].number<<setw(10)<<stu[m].name<<setw(10)<<stu[m].sex
			                <<setw(10)<<stu[m].score[0]<<setw(10)<<stu[m].score[1]<<setw(10)<<stu[m].score[2]<<setw(10)<<stu[m].score[3]<<endl;
					    sign=1;
						cout<<"��ѡ���޸����ݣ�1.ѧ�� 2.���� 3.�Ա� 4.�����ɼ� 5.Ӣ��ɼ� 6.������ɼ� 7.�������������Ϣ"<<endl;
						cin>>l;
						switch(l)
						{
						case 1:
							cout<<"�������������ѧ�ţ�"<<endl;
							cin>>stu[m].number;
							break;
						case 2:
							cout<<"�������������������"<<endl;
							cin>>stu[m].name;
							break;
						case 3:
							cout<<"��������������Ա�"<<endl;
							cin>>stu[m].sex;
							break;
						case 4:
							cout<<"������������������ɼ���"<<endl;
							cin>>stu[m].score[0];
							break;
						case 5:
							cout<<"�������������Ӣ��ɼ���"<<endl;
							cin>>stu[m].score[1];
							break;
						case 6:
							cout<<"�������������������ɼ���"<<endl;
							cin>>stu[m].score[2];
							break;
						case 7:
							cout<<"�����������ѧ�� ѧ�� ���� �Ա� �����ɼ� Ӣ��ɼ� ������ɼ���"<<endl;
                            cin>>stu[m].number>>stu[m].name>>stu[m].sex;
							for(j=0;j<3;j++)
							{
								cin>>stu[m].score[j];
							}
							break;
						}
						stu[m].score[3]=(stu[m].score[0]+stu[m].score[1]+stu[m].score[2])/3;  
						cout<<"�޸���ϣ�������8�鿴"<<endl;
						break;
					}
			   }
			   if(sign!=1)
			   {
				   cout<<"δ�ҵ���ѧ����Ϣ�������ѡ��0~10ģ��"<<endl;
			   }
		   	   break;
		   case 6:
			   average(stu,i);
			   break;
		   case 7:
		   	while(1)
			   {
			   	cout<<"��ѡ���ѯ��Ŀ 1.���� 2.Ӣ�� 3.����� 4.���ز˵�"<<endl; 
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
					 	cout<<"��������������Ϊ"<<accout<<endl;
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
                         cout<<"��������0~9����Ϊ"<<S11<<endl;
                         cout<<"��������10~19����Ϊ"<<S2<<endl;
                         cout<<"��������20~29����Ϊ"<<S3<<endl;
                         cout<<"��������30~39����Ϊ"<<S4<<endl;
                    	 cout<<"��������40~49����Ϊ"<<S5<<endl;
                    	 cout<<"��������50~59����Ϊ"<<S6<<endl;
                    	 cout<<"��������60~69����Ϊ"<<S7<<endl;
                    	 cout<<"��������70~79����Ϊ"<<S8<<endl;
                    	 cout<<"��������80~89����Ϊ"<<S9<<endl;
                    	 cout<<"��������90~100����Ϊ"<<S10<<endl;
                    	 cout<<"������0���ز˵�"<<endl;
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
					 	cout<<"Ӣ�ﲻ��������Ϊ"<<accout<<endl;
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
                    	 cout<<"Ӣ�����0~9����Ϊ"<<S11<<endl;
                    	 cout<<"Ӣ�����10~19����Ϊ"<<S2<<endl;
                    	 cout<<"Ӣ�����20~29����Ϊ"<<S3<<endl;
                    	 cout<<"Ӣ�����30~39����Ϊ"<<S4<<endl;
                    	 cout<<"Ӣ�����40~49����Ϊ"<<S5<<endl;
                    	 cout<<"Ӣ�����50~59����Ϊ"<<S6<<endl;
                    	 cout<<"Ӣ�����60~69����Ϊ"<<S7<<endl;
                    	 cout<<"Ӣ�����70~79����Ϊ"<<S8<<endl;
                    	 cout<<"Ӣ�����80~89����Ϊ"<<S9<<endl;
                    	 cout<<"Ӣ�����90~100����Ϊ"<<S10<<endl;
                    	 cout<<"������0���ز˵�"<<endl;
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
					    cout<<"���������������Ϊ"<<accout<<endl;
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
                    	cout<<"���������0~9����Ϊ"<<S11<<endl;
                    	cout<<"���������10~19����Ϊ"<<S2<<endl;
                    	cout<<"���������20~29����Ϊ"<<S3<<endl;
                    	cout<<"���������30~39����Ϊ"<<S4<<endl;
                    	cout<<"���������40~49����Ϊ"<<S5<<endl;
                    	cout<<"���������50~59����Ϊ"<<S6<<endl;
                    	cout<<"���������60~69����Ϊ"<<S7<<endl;
                    	cout<<"���������70~79����Ϊ"<<S8<<endl;
                    	cout<<"���������80~89����Ϊ"<<S9<<endl;
                    	cout<<"���������90~100����Ϊ"<<S10<<endl;
						cout<<"������0���ز˵�"<<endl;
						break;
				   }
			   }
			   cout<<"�����ѡ��0~10ģ��"<<endl;	   
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
			   cout<<"�����ѡ��0~10ģ��"<<endl;
			   break;
		   case 9:
			   cout<<"�������ļ�������/��"<<endl;
			   cin>>decide;
			   if(!strcmp(decide,"��"))
			   {
				   ofstream input("ѧ���ɼ���.txt",ios::out);                                //��������ļ�
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
			   else
			       {
			       	cout<<"�������ȡ����";
				   }
			   cout<<"�����ѡ��0~10ģ��"<<endl;
			   break;
		   case 10: 
		       menu();
		       break;
		}
	}
   	cout<<"�Ƿ��˳�ϵͳ��(��/��)"<<endl;
	cin>>decide;
	if(!strcmp(decide,"��"))
		goto again;	  
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
