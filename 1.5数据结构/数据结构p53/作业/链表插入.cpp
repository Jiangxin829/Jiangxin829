#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE *next;
};
int main()
{
	NODE *head=new NODE;                         //头指针
	NODE *S1=new NODE;
	head->next=S1;
	S1->data=101;
    NODE *S2=new NODE;
	S1->next=S2;
	S2->data=103;
	S2->next=NULL;
	NODE *p=new NODE;                           //工作指针
    p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}                                          //遍历原链表 
	cout<<endl;
	cout<<"********************"<<endl;
	NODE *S0=new NODE;
	S0->data=102;
	S0->next=S2;S1->next=S0;                   //插入S0于S1和S2之间
	p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}                                          //遍历插入后链表

    return 0;
}