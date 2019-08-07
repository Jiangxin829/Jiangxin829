/*ʵ��Ŀ�ģ� 1.����ͼ���߼��ṹ
             2.��֤ͼ���ڽӱ�洢�ṹ
		     3.��֤�ڽӱ�Ĵ洢����������
  ʵ�����ݣ� 1.����һ������ͼ�ڽӱ�洢�ṹ
             2.�Խ���������ͼ����������ȱ���
             3.�Խ���������ͼ���й�����ȱ���*/
#include<iostream>
using namespace std;
template<class DataType>
struct ArcNode
{
	int adjvex;
	ArcNode <DataType> * next;
};
template<class DataType>
struct VertexNode
{
	DataType vertex;
	ArcNode <DataType> * firstedge;
};
const int MaxSize=5;
template <class DataType>
class ALGraph
{
public:
	ALGraph(DataType a[],int n,int e);
	~ALGraph(){};
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	void newv();
private:
	VertexNode <DataType> adjlist[MaxSize];
	int vertexNum,arcNum;
	int visited[MaxSize];
};
int main()
{
	int n,e,b;
	cout<<"�����붥�����ͱ�����";
	cin>>n>>e;
	int a[10];
	cout<<"������"<<n<<"������Ԫ�أ�";
	for(int i=0;i<n;i++)
		cin>>a[i];
	ALGraph <int> g1(a,n,e);
	g1.newv();
	cout<<"��ѡ��������ȱ�����ʼλ�ã�";
	cin>>b;
	cout<<"������ȱ���Ϊ��";
	g1.DFSTraverse(b);
	cout<<endl;
	cout<<"��ѡ�������ȱ�����ʼλ�ã�";
	cin>>b;
	g1.newv();
	cout<<"������ȱ���Ϊ��";
	g1.BFSTraverse(b);
	return 0;
}
template<class DataType>                                //�ڽӱ��캯��
ALGraph<DataType>::ALGraph(DataType a[],int n,int e)
{
	vertexNum=n;arcNum=e;
	for(int i=0;i<vertexNum;i++)
	{
		adjlist[i].vertex=a[i];
		adjlist[i].firstedge=NULL;
	}
	int m,b;
	ArcNode <DataType> * s;
	for(int k=0;k<arcNum;k++)
	{
		cout<<"����������������ţ�";
		cin>>m>>b;
		s=new ArcNode<DataType>;s->adjvex=b;
		s->next=adjlist[m].firstedge;
		adjlist[m].firstedge=s;
	}
}
template <class DataType>                                    //������ȱ���
void ALGraph<DataType>::DFSTraverse(int v)
{
	cout<<adjlist[v].vertex<<" ";
	visited[v]=1;
	ArcNode<DataType> * p;
	p=new ArcNode<DataType>;
	p=adjlist[v].firstedge;
	int j;
	while(p!=NULL)
    {
        j=p->adjvex;
        if(visited[j]==0) DFSTraverse(j);
        p=p->next;
    }
}

template <class DataType>
void ALGraph<DataType>::newv()
{
	for(int i=0;i<MaxSize;i++)
		visited[i]=0;
}
template <class DataType>
void ALGraph<DataType>::BFSTraverse(int v)                         //������ȱ���
{
    int front=-1;
    int rear=-1;
    int Q[MaxSize];
    int j;
    ArcNode <DataType> * p;
    p=new ArcNode<DataType>;
    cout<<adjlist[v].vertex<<" ";visited[v]=1;Q[++rear]=v;
    while(front!=rear)
    {
        v=Q[++front];
        p=adjlist[v].firstedge;
        while(p!=NULL)
        {
            j=p->adjvex;
            if(visited[j]==0)                            //!!!visited[]���о�����
            {
                cout<<adjlist[j].vertex<<" ";
                visited[j]=1;
                Q[++rear]=j;
            }
            p=p->next;
        }
    }
}


