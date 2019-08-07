#include<iostream>
using namespace std;
const int MaxSize=20;
template<class Data>
class SeqList
{
public:
	SeqList(){length=0;}							//建立空的顺序表（无参构造函数）
	SeqList(Data a[],int n);                        //建立长度为n的顺序表（有参构造函数）
    ~SeqList(){}
	int Length(){return length;}                    //求顺序表长度
	Data Get(int i);                                //查找第i个元素
	int Locate(Data x);								//按值查找
	void Insert(int i,Data x);                      //在位置i插入x操作
	Data Delete(int i);                             //删除第i个元素
	void PrintList();                               //遍历
private:
	Data data[MaxSize];
	int length;
};
int main()

{
	int a[5]={8,10,12,14,16},i,locate,num,denum;
	SeqList<int> d1(a,5);
	cout<<"线性表遍历为：";
	d1.PrintList();
	cout<<"线性表长度为:"<<d1.Length()<<endl;
	cout<<"请输入查找第i个元素：";
	cin>>i;
	cout<<"查找结果："<<d1.Get(i)<<endl;
	cout<<"请输入查找值为：";
	cin>>i;
	cout<<"找到该值位于第 "<<d1.Locate(i)<<" 位"<<endl;
	cout<<"请输入插入的位置和数值：";
	cin>>locate>>num;
	d1.Insert(locate,num);
	cout<<"插入后遍历为：";
	d1.PrintList();
	cout<<"请输入删除元素位置：";
	cin>>denum;
	d1.Delete(denum);
    cout<<"删除后遍历为：";
    d1.PrintList();
	cout<<"************************************"<<endl;
	return 0;
}
template<class Data>
SeqList<Data>::SeqList(Data a[],int n)
{
	if(n>MaxSize) throw "参数非法";
	for(int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}
template<class Data>
void SeqList<Data>::PrintList()
{
	for(int i=0;i<length;i++)
	{
		cout<<data[i]<<"  ";
	}
	cout<<endl;
}
template<class Data>
Data SeqList<Data>::Get(int i)
{
	if(i<1||i>length) throw "查找位置非法";
	else return data[i-1];
}
template<class Data>
int SeqList<Data>::Locate(Data x)
{
	for(int i=0;i<length;i++)
	{
		if (data[i]==x)
			return i+1;          //找到该值并返回位置
	}
	return 0;                               //查找失败
}
template<class Data>
void SeqList<Data>::Insert(int i,Data x)
{
	if(length>=MaxSize) throw"上溢";
	if(i<1||i>length+1) throw"位置";
	for(int j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;                               //元素增加
}
template<class Data>
Data SeqList<Data>::Delete(int i)
{
	int denum;
	if(length==0) throw"下溢";
	if(i<1||i>length+1) throw"位置";
	denum=data[i-1];                        //取出删除的元素
	for(int j=i;j<length;j++)
		data[j-1]=data[j];
	length--;
	return denum;
}

