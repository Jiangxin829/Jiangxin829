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
	LinkList();                             //�޲ι��캯��������ֻ��ͷ���Ŀ�����
	LinkList(Data a[],int n);               //�вι��캯��������n��Ԫ�صĵ�����
	~LinkList(){}							//��������
	int Length();							//��������
	Data Get(int i);						//���ҵ�i��Ԫ��
	int Locate(Data x);						//����ֵΪx��λ��
	void Insert(int i,Data x);              //��λ��i����x
	Data Delete(int i);                     //ɾ����i��Ԫ��
	void PrintList();                       //����
private:
	Node<Data>*first;
};
int main()
{
	int num,i;int a[10];
	cout<<"����������Ԫ�ظ�����";
	cin>>num;
	cout<<"���������Ԫ�أ�";
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
	 }
	 LinkList<int> l1(a,num);
	 cout<<"��������Ϊ��"<<l1.Length()<<endl;
	 cout<<"���������Ϊ��";
	 l1.PrintList();
	 cout<<"��������ҵ�i��Ԫ�أ�";
	 cin>>num;
	 cout<<"�ҵ���Ԫ��Ϊ:"<<l1.Get(num)<<endl;
	 cout<<"���������Ԫ��x��ֵ��";
	 cin>>num;
	 cout<<"�ҵ���Ԫ��λ��Ϊ�� "<<l1.Locate(num)<<" λ"<<endl;
	 cout<<"���������Ԫ��λ��i��ֵx��";
	 cin>>i>>num;
	 l1.Insert(i,num);
	 cout<<"��������Ϊ��";
	 l1.PrintList();
	 cout<<"������ɾ��Ԫ��λ��i:";
	 cin>>i;
	 l1.Delete(i);
	 cout<<"ɾ�������Ϊ��";
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
    if(p==NULL) throw"λ��";
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
    if(p==NULL) throw"λ��";
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
        throw "λ��";
    else
    {
        Node<Data> *q=p->next;x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}
