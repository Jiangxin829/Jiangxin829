#include<iostream>
using namespace std;
template<class Data>
struct Node
{
	Data data;
	Node<Data>*next;
};
template<class Data>
class LinkList
{
public:
	LinkList();                             //无参构造函数，建立只有头结点的空链表
	LinkList(Data a[],int n);               //有参构造函数，建立n个元素的单链表
	~LinkList(){}							//析构函数
	int Length();							//求链表长度
	Data Get(int i);						//查找第i个元素
	int Locate(Data x);						//查找值为x的位置
	void Insert(int i,Data x);              //在位置i插入x
	Data Delete(int i);                     //删除第i个元素
	void PrintList();                       //遍历
private:
	Node<Data>*first;
};
int main()
{
	int num,i;int a[10];
	cout<<"请输入链表元素个数：";
	cin>>num;
	cout<<"请输入各个元素：";
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
	 }
	 LinkList<int> l1(a,num);
	 cout<<"该链表长度为："<<l1.Length()<<endl;
	 cout<<"该链表遍历为：";
	 l1.PrintList();
	 cout<<"请输入查找第i个元素：";
	 cin>>num;
	 cout<<"找到该元素为:"<<l1.Get(num)<<endl;
	 cout<<"请输入查找元素x的值：";
	 cin>>num;
	 cout<<"找到该元素位置为第 "<<l1.Locate(num)<<" 位"<<endl;
	 cout<<"请输入插入元素位置i和值x：";
	 cin>>i>>num;
	 l1.Insert(i,num);
	 cout<<"插入后遍历为：";
	 l1.PrintList();
	 cout<<"请输入删除元素位置i:";
	 cin>>i;
	 l1.Delete(i);
	 cout<<"删除后遍历为：";
	 l1.PrintList();
     return 0;
}
template<class Data>
LinkList<Data>::LinkList()
{
	Node<Data> *first=new Node<Data>;
	first->next=NULL;
}
template<class Data>
LinkList<Data>::LinkList(Data a[],int n)
{
	first=new Node<Data>;
	Node<Data> *r=first;
	Node<Data> *s;
	for(int i=0;i<n;i++)
	{
		s=new Node<Data>;s->data=a[i];
        r->next=s;r=s;
	}
	r->next=NULL;
}
template<class Data>
void LinkList<Data>::PrintList()
{
    Node<Data> *p=first->next;
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
}
template<class Data>
int LinkList<Data>::Length()
{
    int count=0;
    Node<Data> *p=first->next;
    while(p!=NULL)
    {

        p=p->next;
        count++;
    }
    return count;
}
template<class Data>
Data LinkList<Data>::Get(int i)
{
    int count=1;
    Node<Data> *p=first->next;
    while(p!=NULL&&count<i)
    {
        p=p->next;
        count++;
    }
    if(p==NULL) throw"位置";
    else return p->data;
}
template<class Data>
int LinkList<Data>::Locate(Data x)
{
    int count=1;
    Node<Data> *p=first->next;
    while(p!=NULL)
    {
        if(p->data==x) return count;
        p=p->next;
        count++;
    }
    return 0;
}
template<class Data>
void LinkList<Data>::Insert(int i,Data x)
{
    int count=0;
    Node<Data> *p=first;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL) throw"位置";
    else
    {
        Node<Data> *s=new Node<Data>;s->data=x;
        s->next=p->next;p->next=s;
    }
}
template<class Data>
Data LinkList<Data>::Delete(int i)
{
    int count=0,x;
    Node<Data> *p=first;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL||p->next==NULL)
        throw "位置";
    else
    {
        Node<Data> *q=p->next;x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}
