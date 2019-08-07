#include <iostream>
using namespace std;
const int StackSize=5;
template <class DataType>
class SeqStack
{
public:
    SeqStack(){top=-1;}                          //构造函数，初始化一个空栈
    ~SeqStack(){}                                //析构函数为空
    void Push(DataType x);                       //入栈操作
    DataType Pop();                              //出栈操作
    void PrintStack();                           //遍历栈
    DataType GetTop(){return data[top];}//取栈顶元素
    int Empty(){if(top==-1) return 1;
                  else return 0;}                //判断栈是否为空
private:
    DataType data[StackSize];                    //存放栈元素的数组
    int top;                                     //栈顶指针
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
    LinkQueue();                                 //构造函数，初始化一个空队列
    ~LinkQueue(){}                               //析构函数，释放各结点空间
    void EnQueue(DataType x);                    //入队操作
    DataType DeQueue();                          //出队操作
    DataType GetQueue();                         //取链队列的队头元素
    int Empty() {if(rear==front) return 1;
                else return 0;}                  //判断链队列是否为空
    void PrintQueue();                           //遍历队列
private:
    Node<DataType> *front,*rear;                 //队头和队尾指针
};
int main()
{
    int i;
    SeqStack<int> s1;
    int x;
    cout<<"请依次插入五个栈元素：";
    for(i=0;i<StackSize;i++)
    {
        cin>>x;
        s1.Push(x);
    }
    s1.PrintStack();
    cout<<endl;
    cout<<"出栈删除元素为："<<s1.Pop()<<endl;
    cout<<"再次遍历：";
    s1.PrintStack();
    cout<<endl;
    cout<<"取栈顶元素："<<s1.GetTop()<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**************************************"<<endl;
    LinkQueue<int> l1;
    cout<<"请依次插入五个队列元素：";
    for(i=0;i<5;i++)
    {
        cin>>x;
        l1.EnQueue(x);
    }
    l1.PrintQueue();
    cout<<"删除队头元素后，";
    l1.DeQueue();
    l1.PrintQueue();
    cout<<"取队头元素为："<<l1.GetQueue()<<endl;
    cout<<"**************************************"<<endl;
    return 0;
}
template <class DataType>
void SeqStack<DataType>::Push(DataType x)
{
    if(top==StackSize-1) throw"上溢";
    data[++top]=x;
}
template <class DataType>
DataType SeqStack<DataType>::Pop()
{
    if(top==-1) throw"上溢";
    int x=data[top--];
    return x;
}
template <class DataType>
void SeqStack<DataType>::PrintStack()
{
    cout<<"栈遍历为:";
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
    cout<<"遍历为：";
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
    if(rear==front) throw "下溢";
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

