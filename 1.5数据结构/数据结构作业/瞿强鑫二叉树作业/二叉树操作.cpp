/*实验目的：1.掌握二叉树的逻辑结构
          2.掌握二叉链表存储结构
	      3.验证二叉树的二叉链表存储和遍历操作
实验内容：
	      1.建立一棵含有n个结点的树，采用二叉链表结构
	      2.输出前序、中序、后序、层序遍历结果*/
#include<iostream>
using namespace std;
template<class DataType>
struct BiNode
{
	DataType data;
	BiNode<DataType> * lchild,* rchild;
};
template<class DataType>
class BiTree
{
public:
	BiTree(){root=Creat(root);}
	~BiTree(){Release(root);}
	void PreOrder(){PreOrder(root);}
	void InOrder(){InOrder(root);}
	void PostOrder(){PostOrder(root);}
	void LeverOrder();
private:
	BiNode<DataType> * root;
	BiNode<DataType> * Creat(BiNode<DataType> * bt);
	void Release(BiNode<DataType> * bt);
	void PreOrder(BiNode<DataType> * bt);
	void InOrder(BiNode<DataType> * bt);
	void PostOrder(BiNode<DataType> * bt);
};
int main()
{
	BiTree<char> t1;
	cout<<"前序遍历为：";
	t1.PreOrder();
	cout<<endl;
	cout<<"中序遍历为：";
	t1.InOrder();
	cout<<endl;
	cout<<"后序遍历为：";
	t1.PostOrder();
	cout<<endl;
	cout<<"层序遍历为：";
	t1.LeverOrder();
	cout<<endl;
	return 0;
}

template<class DataType>
BiNode<DataType> *BiTree<DataType>::Creat(BiNode<DataType> * bt)//建立二叉链表
{
	char ch;
	cout<<"请输入结点信息(输入#结束)：";
	cin>>ch;
	if(ch=='#') bt=NULL;
	else{
		bt=new BiNode<DataType>;bt->data=ch;//!!!!错误纠正
		bt->lchild=Creat(bt->lchild);
		bt->rchild=Creat(bt->rchild);
	}
	return bt;
}
template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType> * bt)           //释放二叉链表
{
	if(bt!=NULL) {
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}
template<class DataType>                                     //前序遍历
void BiTree<DataType>::PreOrder(BiNode<DataType> * bt)
{
	if(bt==NULL) return;
	else {
		cout<<bt->data<<" ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
template<class DataType>                                     //中序遍历
void BiTree<DataType>::InOrder(BiNode<DataType> * bt)
{
	if(bt==NULL) return;
	else {
		InOrder(bt->lchild);
		cout<<bt->data<<" ";
		InOrder(bt->rchild);
	}
}
template<class DataType>                                     //后序遍历
void BiTree<DataType>::PostOrder(BiNode<DataType> * bt)
{
	if(bt==NULL) return;
	else {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data<<" ";
	}
}
template<class DataType>                                       //层序遍历
void BiTree<DataType>::LeverOrder()
{
	BiNode<DataType> * Q[20];       //!!!错误纠正
	int front,rear;
	front=rear=-1;
	if(root==NULL) return;
	Q[++rear]=root;
    BiNode<DataType> * q;
	while(front!=rear)
	{
		q=Q[++front];
		cout<<q->data;
		if(q->lchild!=NULL) Q[++rear]=q->lchild;
		if(q->rchild!=NULL) Q[++rear]=q->rchild;
	}
}
