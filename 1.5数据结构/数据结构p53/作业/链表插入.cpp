#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE *next;
};
int main()
{
	NODE *head=new NODE;                         //ͷָ��
	NODE *S1=new NODE;
	head->next=S1;
	S1->data=101;
    NODE *S2=new NODE;
	S1->next=S2;
	S2->data=103;
	S2->next=NULL;
	NODE *p=new NODE;                           //����ָ��
    p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}                                          //����ԭ���� 
	cout<<endl;
	cout<<"********************"<<endl;
	NODE *S0=new NODE;
	S0->data=102;
	S0->next=S2;S1->next=S0;                   //����S0��S1��S2֮��
	p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}                                          //�������������

    return 0;
}