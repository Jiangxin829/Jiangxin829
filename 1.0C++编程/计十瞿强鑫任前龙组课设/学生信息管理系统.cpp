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
	
	void putin();                      //����ѧ����Ϣ 
	void search();                     //��ѯѧ����Ϣ 
	void increase();                   //����ѧ����Ϣ 
	void cancle();                     //ɾ��ѧ����Ϣ 
	void change();                     //�޸�ѧ����Ϣ 
	void turnlist();                   //ѧ��ƽ�������� 
	void statistics();                 //��������ͳ�� 				
	void save();                       //�洢ѧ����Ϣ���ļ� 
	void putout();                     //���ѧ����Ϣ�� 
	void menu();	                   //�˵������ڲ鿴 
};
void Systerm::menu()
{
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"|                          ѧ���ɼ�����ϵͳ                                  |"<<endl;
	cout<<"|                                                                            |"<<endl; 
	cout<<"|   ���********** 1.����ѧ����Ϣ/���ļ��ж�������**********���             |"<<endl;
	cout<<"|   ���********** 2.��ѯѧ����Ϣ                 **********���             |"<<endl;
	cout<<"|   ���********** 3.����ѧ����Ϣ                 **********���             |"<<endl;
	cout<<"|   ���********** 4.ɾ��ѧ����Ϣ                 **********���             |"<<endl;
	cout<<"|   ���********** 5.�޸�ѧ���ɼ�                 **********���             |"<<endl;
	cout<<"|   ���********** 6.ƽ���ɼ�����                 **********���             |"<<endl;
	cout<<"|   ���********** 7.���ֶ�����������������       **********���             |"<<endl;
    cout<<"|   ���********** 8.���ѧ����Ϣ                 **********���             |"<<endl;
    cout<<"|   ���********** 9.�������ļ�                   **********���             |"<<endl;
	cout<<"|   ���********** 10.�鿴�˵�                    **********���             |"<<endl;
	cout<<"|   ���********** 0.�˳�ϵͳ                     **********���             |"<<endl;
	cout<<"|____________________________________________________________________________|"<<endl;
	cout<<" ��ѡ��0~10ģ�飺"<<endl;
}
void Systerm::putin()
{
	cout<<"��ѡ��1.����ѧ���ɼ� 2.���ļ����� 3.���ز˵�"<<endl;
	int choose;
    cin>>choose;
    if(choose==1)
	{
		while(1)
		{ 				
            if(choose!=1)
            {
			 	cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
			   	break;
			}  
back4:      cout<<"���������룺ѧ�� ���� �Ա�"<<endl;	         
	        cin>>stu[i].number>>stu[i].name>>stu[i].sex; //����Ϣͨ����������
     		cout<<"����������ɼ�(�ٷ���0~100��"<<endl;	 //��������ɼ��Ϸ���         
		    cin>>stu[i].score[0];  
		    if(stu[i].score[0]<0||stu[i].score[0]>100) 
			{
			    cout<<"����������Ϸ��ɼ���"<<endl;
                cin>>stu[i].score[0]; 
			}	
			cout<<"������Ӣ��ɼ����ٷ���0~100��"<<endl;
			cin>>stu[i].score[1];
			if(stu[i].score[1]<0||stu[i].score[1]>100) 
			{
			    cout<<"����������Ϸ��ɼ���"<<endl;
				cin>>stu[i].score[1];
			}	
			cout<<"�����������ɼ����ٷ���0~100)"<<endl;
			cin>>stu[i].score[2];
			if(stu[i].score[2]<0||stu[i].score[2]>100) 
			{
			    cout<<"����������Ϸ��ɼ���"<<endl;
				cin>>stu[i].score[2];
			}				    
			stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;    //��ƽ����
		    for(int  n=0;n<i;n++)
			{
			    while(!strcmp(stu[n].number,stu[i].number)||!strcmp(stu[n].name,stu[i].name))
			    {
			    	cout<<"ѧ�Ż������ظ�����˶���Ϣ����������"<<endl;
			    	goto back4;
			    	break;
				}			
			}					                 		   
		    cout<<"������ɣ���ѡ��1��������,����0���ز˵�"<<endl;
		    cin>>choose;
			i++;
		}
		//cout<<"i="<<i<<endl;                     
	}
	if(choose==2)
	{
		ifstream read("ѧ���ɼ���.txt"); 
		if(!read.is_open())
		{
			cout<<"�ļ��򿪴���,������ѡ��0~10"<<endl;
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
			cout<<"����ѧ������Ϊ��"<<j-1<<endl;
			i=j-1;
			cout<<"��ȡ��ɣ�������8�鿴"<<endl;
		}
	} 
	if(choose==3) 
	{
		cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
	}                                    	
}
void Systerm::search()
{
		int m=0;
		int sign=0;
		char Snum[20]={0};
		cout<<"���������ѧ����ѧ�Ż�����,���롮���ء����˵�"<<endl;
 		cin>>Snum;
 		if(!strcmp(Snum,"����"))
 		{
 			goto back1;
 		}    
		for(;m<i;m++)
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
back1:	cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
}
void Systerm::increase()
{
	int choose=1;
	while(1)
		{ 				
            if(choose!=1)
			   break;
back4:      cout<<"���������룺ѧ�� ���� �Ա�"<<endl;	         
	        cin>>stu[i].number>>stu[i].name>>stu[i].sex; //����Ϣͨ����������
     		cout<<"����������ɼ�(�ٷ���0~100��"<<endl;	 //��������ɼ��Ϸ���         
		    cin>>stu[i].score[0];  
		    if(stu[i].score[0]<0||stu[i].score[0]>100) 
			{
			    cout<<"����������Ϸ��ɼ���"<<endl;
                cin>>stu[i].score[0]; 
			}	
			cout<<"������Ӣ��ɼ����ٷ���0~100��"<<endl;
			cin>>stu[i].score[1];
			if(stu[i].score[1]<0||stu[i].score[1]>100) 
			{
			    cout<<"����������Ϸ��ɼ���"<<endl;
				cin>>stu[i].score[1];
			}	
			cout<<"�����������ɼ����ٷ���0~100)"<<endl;
			cin>>stu[i].score[2];
			if(stu[i].score[2]<0||stu[i].score[2]>100) 
			{
			    cout<<"����������Ϸ��ɼ���"<<endl;
				cin>>stu[i].score[2];
			}				    
			stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;    //��ƽ����
		    for(int  n=0;n<i;n++)
			{
			    while(!strcmp(stu[n].number,stu[i].number)||!strcmp(stu[n].name,stu[i].name))
			    {
			    	cout<<"ѧ�Ż������ظ�����˶���Ϣ����������"<<endl;
			    	goto back4;
			    	break;
				}			
			}					                 		   
		    cout<<"������ɣ���ѡ��1��������,����0���ز˵�"<<endl;
		    cin>>choose;
			i++;
			//cout<<"i="<<i<<endl;
		}
		cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
}
void Systerm::cancle()
{
	 cout<<"������Ҫɾ����ѧ��ѧ�Ż�����������'����'���˵�"<<endl;
	 int sign=0;
	 int m=0;
	 char Snum[20]={0};
	 char decide[2];
	 cin>>Snum; 
	 if(!strcmp(Snum,"����"))
	 {
	 goto back2;	
	 }
         for(;m<i;m++)
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
					 for(int n=m;n<i;n++)
					 {
						 stu[n]=stu[n+1];
					 }
					 cout<<"ɾ����ϣ�������8�鿴,10���鿴�˵�"<<endl;
					 i=i-1;
				 }
				 else
				     cout<<"ɾ������ȡ����"<<endl;
			 }
		}
		if(sign!=1)
			   {
				   cout<<"δ�ҵ���ѧ����Ϣ��"<<endl;
			   }
back2:		cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
}
void Systerm::change()
{
	cout<<"���Ȳ���Ҫ�޸ĵ�ѧ��ѧ�Ż�����,����'����'���˵�"<<endl;
    int sign=0;
	int m=0;
    char Snum[20]={0};
	cin>>Snum;
	if(!strcmp(Snum,"����"))
	 {
	 	 cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
	     goto back3;	
	 }
    for(;m<i;m++)
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
			int l; 
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
				if(stu[m].score[0]<0||stu[m].score[0]>100) 
				{
			    	cout<<"����������Ϸ��ɼ���"<<endl;
                	cin>>stu[m].score[0]; 
				}	
				break;
			case 5:
				cout<<"�������������Ӣ��ɼ���"<<endl;
				cin>>stu[m].score[1];
				if(stu[m].score[1]<0||stu[m].score[1]>100) 
				{
			    	cout<<"����������Ϸ��ɼ���"<<endl;
                	cin>>stu[m].score[1]; 
				}	
				break;
			case 6:
				cout<<"�������������������ɼ���"<<endl;
				cin>>stu[m].score[2];
				if(stu[m].score[2]<0||stu[m].score[2]>100) 
				{
			   		cout<<"����������Ϸ��ɼ���"<<endl;
                	cin>>stu[m].score[2]; 
				}	
				break;
			case 7:
				cout<<"�����������ѧ�� ѧ�� ���� �Ա� �����ɼ� Ӣ��ɼ� ������ɼ���"<<endl;
                cin>>stu[m].number>>stu[m].name>>stu[m].sex;
					for(int j=0;j<3;j++)
				{
					cin>>stu[m].score[j];
				} 
				break;
			}
			stu[m].score[3]=(stu[m].score[0]+stu[m].score[1]+stu[m].score[2])/3;  
			cout<<"�޸���ϣ�������8�鿴,10���鿴�˵�"<<endl;
			break;
		}
	}
back3:  if(sign!=1)
		{
			cout<<"δ�ҵ���ѧ����Ϣ�������ѡ��0~10ģ��,10���鿴�˵�"<<endl;
		}	
}
void Systerm::turnlist()
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
		cout<<"��ѡ�������У�ѡ��8�ɲ鿴��10���鿴�˵�"<<endl;
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
			cout<<"��ѡ���������У�ѡ��8�ɲ鿴��10���鿴�˵�"<<endl;
		}
		else
		    if(choose==3)	
			cout<<"�ѷ��ز˵�!��ѡ��0~10,10���鿴�˵�"<<endl; 
}
void Systerm::statistics()
{
	    	   while(1)
			   {
			   	cout<<"��ѡ���ѯ��Ŀ 1.���� 2.Ӣ�� 3.����� 4.���ز˵�"<<endl;
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
					 	cout<<"��������������Ϊ  "<<accout<<endl;
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
                         cout<<"����   0~9�ֵ�����Ϊ"<<S11<<endl;
                    	cout<<"     10~19�ֵ�����Ϊ"<<S2<<endl;
                    	cout<<"     20~29�ֵ�����Ϊ"<<S3<<endl;
                    	cout<<"     30~39�ֵ�����Ϊ"<<S4<<endl;
                    	cout<<"     40~49�ֵ�����Ϊ"<<S5<<endl;
                    	cout<<"     50~59�ֵ�����Ϊ"<<S6<<endl;
                    	cout<<"     60~69�ֵ�����Ϊ"<<S7<<endl;
                    	cout<<"     70~79�ֵ�����Ϊ"<<S8<<endl;
                    	cout<<"     80~89�ֵ�����Ϊ"<<S9<<endl;
                    	cout<<"     90~100�ֵ�����Ϊ"<<S10<<endl;
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
					 	cout<<"Ӣ�ﲻ��������Ϊ  "<<accout<<endl;
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
                    	 cout<<"Ӣ��   0~9�ֵ�����Ϊ"<<S11<<endl;
                    	cout<<"     10~19�ֵ�����Ϊ"<<S2<<endl;
                    	cout<<"     20~29�ֵ�����Ϊ"<<S3<<endl;
                    	cout<<"     30~39�ֵ�����Ϊ"<<S4<<endl;
                    	cout<<"     40~49�ֵ�����Ϊ"<<S5<<endl;
                    	cout<<"     50~59�ֵ�����Ϊ"<<S6<<endl;
                    	cout<<"     60~69�ֵ�����Ϊ"<<S7<<endl;
                    	cout<<"     70~79�ֵ�����Ϊ"<<S8<<endl;
                    	cout<<"     80~89�ֵ�����Ϊ"<<S9<<endl;
                    	cout<<"     90~100�ֵ�����Ϊ"<<S10<<endl;
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
					    cout<<"���������������Ϊ  "<<accout<<endl;
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
                    	cout<<"�����   0~9�ֵ�����Ϊ"<<S11<<endl;
                    	cout<<"     10~19�ֵ�����Ϊ"<<S2<<endl;
                    	cout<<"     20~29�ֵ�����Ϊ"<<S3<<endl;
                    	cout<<"     30~39�ֵ�����Ϊ"<<S4<<endl;
                    	cout<<"     40~49�ֵ�����Ϊ"<<S5<<endl;
                    	cout<<"     50~59�ֵ�����Ϊ"<<S6<<endl;
                    	cout<<"     60~69�ֵ�����Ϊ"<<S7<<endl;
                    	cout<<"     70~79�ֵ�����Ϊ"<<S8<<endl;
                    	cout<<"     80~89�ֵ�����Ϊ"<<S9<<endl;
                    	cout<<"     90~100�ֵ�����Ϊ"<<S10<<endl;
						break;
				   }
			   }
			   cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
	
}
void Systerm::save()
{
			   char decide[2];		   
	           cout<<"�������ļ�������/��"<<endl;
			   cin>>decide;		   
			   if(!strcmp(decide,"��"))
			   {
			   	   cout<<"��ѡ���Ƿ���ԭ�ļ����ݣ�����/��"<<endl; 
	           	   cin>>decide;
	           	   if(!strcmp(decide,"��"))
	           	   {	
	           	   	   ofstream input("ѧ���ɼ���.txt",ios::app);
	           	   	   for(int k=0;k<i;k++)
				   		{
				       		input<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				       		for(int l=0;l<4;l++)
					   		{
					       		input<<setw(10)<<stu[k].score[l];
					   		}
				       		input<<endl;
				   		}
				   		cout<<"����ɹ���"<<endl;
					}
					else
					{
						ofstream input("ѧ���ɼ���.txt",ios::out);                                
				   		input<<"                                   ѧ���ɼ���"<<endl;
	               		input<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		                 		<<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
				   		for(int k=0;k<i;k++)
				   		{
				       		input<<setw(10)<<stu[k].number<<setw(10)<<stu[k].name<<setw(10)<<stu[k].sex;
				       		for(int l=0;l<4;l++)
					   		{
					       		input<<setw(10)<<stu[k].score[l];
					   		}
				       		input<<endl;
				   		}
				   		cout<<"����ɹ���"<<endl;
				   }
			   }
			   else
			       {
			       	cout<<"�������ȡ����";
				   }
			   cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
} 
void Systerm::putout()
{
	cout<<"                                   ѧ���ɼ���"<<endl;
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�Ա�"
		<<setw(10)<<"����"<<setw(10)<<"Ӣ��"<<setw(10)<<"�����"<<setw(10)<<"ƽ����"<<endl;
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
	cout<<"�����ѡ��0~10ģ��,10���鿴�˵�"<<endl;
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
	    cout<<"�Ƿ��˳�ϵͳ��(��/��)"<<endl;
	    cin>>decide;
	    if(!strcmp(decide,"��"))
		    goto again;
		cout<<"ллʹ�ã��ټ���" <<endl; 
	    return 0;
}



 





