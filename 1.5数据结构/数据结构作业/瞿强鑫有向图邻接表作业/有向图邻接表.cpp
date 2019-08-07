/*实验目的： 1.掌握图的逻辑结构
             2.验证图的邻接表存储结构
		     3.验证邻接表的存储及遍历操作
  实验内容： 1.建立一个有向图邻接表存储结构
             2.对建立的有向图进行深度优先遍历
             3.对建立的有向图进行广度优先遍历*/
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
	cout<<"请输入顶点数和边数：";
	cin>>n>>e;
	int a[10];
	cout<<"请输入"<<n<<"个顶点元素：";
	for(int i=0;i<n;i++)
		cin>>a[i];
	ALGraph <int> g1(a,n,e);
	g1.newv();
	cout<<"请选择深度优先遍历开始位置：";
	cin>>b;
	cout<<"深度优先遍历为：";
	g1.DFSTraverse(b);
	cout<<endl;
	cout<<"请选择广度优先遍历开始位置：";
	cin>>b;
	g1.newv();
	cout<<"广度优先遍历为：";
	g1.BFSTraverse(b);
	return 0;
}
template<class DataType>                                //邻接表构造函数
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
		cout<<"输入边依附两顶点编号：";
		cin>>m>>b;
		s=new ArcNode<DataType>;s->adjvex=b;
		s->next=adjlist[m].firstedge;
		adjlist[m].firstedge=s;
	}
}
template <class DataType>                                    //深度优先遍历
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
void ALGraph<DataType>::BFSTraverse(int v)                         //广度优先遍历
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
            if(visited[j]==0)                            //!!!visited[]具有局限性
            {
                cout<<adjlist[j].vertex<<" ";
                visited[j]=1;
                Q[++rear]=j;
            }
            p=p->next;
        }
    }
}


