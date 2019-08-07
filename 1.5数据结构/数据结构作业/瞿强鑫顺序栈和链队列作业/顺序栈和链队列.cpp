#include <iostream>
using namespace std;
const int StackSize=5;
template <class DataType>
class SeqStack
{
public:
    SeqStack(){top=-1;}                          //���캯������ʼ��һ����ջ
    ~SeqStack(){}                                //��������Ϊ��
    void Push(DataType x);                       //��ջ����
    DataType Pop();                              //��ջ����
    void PrintStack();                           //����ջ
    DataType GetTop(){return data[top];}//ȡջ��Ԫ��
    int Empty(){if(top==-1) return 1;
                  else return 0;}                //�ж�ջ�Ƿ�Ϊ��
private:
    DataType data[StackSize];                    //���ջԪ�ص�����
    int top;                                     //ջ��ָ��
};
template <class DataType>
struct Node
{
    DataType data;
	Node<DataType>*next;
};
template <class DataType>
class LinkQueue
{
public:
    LinkQueue();                                 //���캯������ʼ��һ���ն���
    ~LinkQueue(){}                               //�����������ͷŸ����ռ�
    void EnQueue(DataType x);                    //��Ӳ���
    DataType DeQueue();                          //���Ӳ���
    DataType GetQueue();                         //ȡ�����еĶ�ͷԪ��
    int Empty() {if(rear==front) return 1;
                else return 0;}                  //�ж��������Ƿ�Ϊ��
    void PrintQueue();                           //��������
private:
    Node<DataType> *front,*rear;                 //��ͷ�Ͷ�βָ��
};
int main()
{
    int i;
    SeqStack<int> s1;
    int x;
    cout<<"�����β������ջԪ�أ�";
    for(i=0;i<StackSize;i++)
    {
        cin>>x;
        s1.Push(x);
    }
    s1.PrintStack();
    cout<<endl;
    cout<<"��ջɾ��Ԫ��Ϊ��"<<s1.Pop()<<endl;
    cout<<"�ٴα�����";
    s1.PrintStack();
    cout<<endl;
    cout<<"ȡջ��Ԫ�أ�"<<s1.GetTop()<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**************************************"<<endl;
    LinkQueue<int> l1;
    cout<<"�����β����������Ԫ�أ�";
    for(i=0;i<5;i++)
    {
        cin>>x;
        l1.EnQueue(x);
    }
    l1.PrintQueue();
    cout<<"ɾ����ͷԪ�غ�";
    l1.DeQueue();
    l1.PrintQueue();
    cout<<"ȡ��ͷԪ��Ϊ��"<<l1.GetQueue()<<endl;
    cout<<"**************************************"<<endl;
    return 0;
}
template <class DataType>
void SeqStack<DataType>::Push(DataType x)
{
    if(top==StackSize-1) throw"����";
    data[++top]=x;
}
template <class DataType>
DataType SeqStack<DataType>::Pop()
{
    if(top==-1) throw"����";
    int x=data[top--];
    return x;
}
template <class DataType>
void SeqStack<DataType>::PrintStack()
{
    cout<<"ջ����Ϊ:";
    for(int i=top;i>-1;i--)
    {
        cout<<data[i]<<"  ";
    }
}
//********************************************
template <class DataType>
LinkQueue<DataType>::LinkQueue()
{
  Node<DataType> *s=new Node<DataType>;s->next=NULL;
  front=rear=s;
}
template <class DataType>
void LinkQueue<DataType>::EnQueue(DataType x)
{
    Node<DataType> *s=new Node<DataType>;s->data=x;
    s->next=NULL;
    rear->next=s;
    rear=s;
}
template <class DataType>
void LinkQueue<DataType>::PrintQueue()
{
    cout<<"����Ϊ��";
    Node<DataType> *p=front->next;
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
    cout<<endl;
}
template <class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
    if(rear==front) throw "����";
    Node<DataType> *p=front->next;int x=p->data;
    front->next=p->next;
    if(p->next==NULL) rear=front;
    delete p;
    return x;
}
template <class DataType>
DataType LinkQueue<DataType>::GetQueue()
{
    return front->next->data;
}

