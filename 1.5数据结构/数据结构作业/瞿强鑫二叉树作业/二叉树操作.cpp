/*ʵ��Ŀ�ģ�1.���ն��������߼��ṹ
          2.���ն�������洢�ṹ
	      3.��֤�������Ķ�������洢�ͱ�������
ʵ�����ݣ�
	      1.����һ�ú���n�������������ö�������ṹ
	      2.���ǰ�����򡢺��򡢲���������*/
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
	cout<<"ǰ�����Ϊ��";
	t1.PreOrder();
	cout<<endl;
	cout<<"�������Ϊ��";
	t1.InOrder();
	cout<<endl;
	cout<<"�������Ϊ��";
	t1.PostOrder();
	cout<<endl;
	cout<<"�������Ϊ��";
	t1.LeverOrder();
	cout<<endl;
	return 0;
}

template<class DataType>
BiNode<DataType> *BiTree<DataType>::Creat(BiNode<DataType> * bt)//������������
{
	char ch;
	cout<<"����������Ϣ(����#����)��";
	cin>>ch;
	if(ch=='#') bt=NULL;
	else{
		bt=new BiNode<DataType>;bt->data=ch;//!!!!�������
		bt->lchild=Creat(bt->lchild);
		bt->rchild=Creat(bt->rchild);
	}
	return bt;
}
template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType> * bt)           //�ͷŶ�������
{
	if(bt!=NULL) {
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}
template<class DataType>                                     //ǰ�����
void BiTree<DataType>::PreOrder(BiNode<DataType> * bt)
{
	if(bt==NULL) return;
	else {
		cout<<bt->data<<" ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
template<class DataType>                                     //�������
void BiTree<DataType>::InOrder(BiNode<DataType> * bt)
{
	if(bt==NULL) return;
	else {
		InOrder(bt->lchild);
		cout<<bt->data<<" ";
		InOrder(bt->rchild);
	}
}
template<class DataType>                                     //�������
void BiTree<DataType>::PostOrder(BiNode<DataType> * bt)
{
	if(bt==NULL) return;
	else {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data<<" ";
	}
}
template<class DataType>                                       //�������
void BiTree<DataType>::LeverOrder()
{
	BiNode<DataType> * Q[20];       //!!!�������
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
