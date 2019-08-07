#include<iostream>
using namespace std;
const int MaxSize=20;
template<class Data>
class SeqList
{
public:
	SeqList(){length=0;}							//�����յ�˳����޲ι��캯����
	SeqList(Data a[],int n);                        //��������Ϊn��˳����вι��캯����
    ~SeqList(){}
	int Length(){return length;}                    //��˳�����
	Data Get(int i);                                //���ҵ�i��Ԫ��
	int Locate(Data x);								//��ֵ����
	void Insert(int i,Data x);                      //��λ��i����x����
	Data Delete(int i);                             //ɾ����i��Ԫ��
	void PrintList();                               //����
private:
	Data data[MaxSize];
	int length;
};
int main()

{
	int a[5]={8,10,12,14,16},i,locate,num,denum;
	SeqList<int> d1(a,5);
	cout<<"���Ա����Ϊ��";
	d1.PrintList();
	cout<<"���Ա���Ϊ:"<<d1.Length()<<endl;
	cout<<"��������ҵ�i��Ԫ�أ�";
	cin>>i;
	cout<<"���ҽ����"<<d1.Get(i)<<endl;
	cout<<"���������ֵΪ��";
	cin>>i;
	cout<<"�ҵ���ֵλ�ڵ� "<<d1.Locate(i)<<" λ"<<endl;
	cout<<"����������λ�ú���ֵ��";
	cin>>locate>>num;
	d1.Insert(locate,num);
	cout<<"��������Ϊ��";
	d1.PrintList();
	cout<<"������ɾ��Ԫ��λ�ã�";
	cin>>denum;
	d1.Delete(denum);
    cout<<"ɾ�������Ϊ��";
    d1.PrintList();
	cout<<"************************************"<<endl;
	return 0;
}
template<class Data>
SeqList<Data>::SeqList(Data a[],int n)
{
	if(n>MaxSize) throw "�����Ƿ�";
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
	if(i<1||i>length) throw "����λ�÷Ƿ�";
	else return data[i-1];
}
template<class Data>
int SeqList<Data>::Locate(Data x)
{
	for(int i=0;i<length;i++)
	{
		if (data[i]==x)
			return i+1;          //�ҵ���ֵ������λ��
	}
	return 0;                               //����ʧ��
}
template<class Data>
void SeqList<Data>::Insert(int i,Data x)
{
	if(length>=MaxSize) throw"����";
	if(i<1||i>length+1) throw"λ��";
	for(int j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;                               //Ԫ������
}
template<class Data>
Data SeqList<Data>::Delete(int i)
{
	int denum;
	if(length==0) throw"����";
	if(i<1||i>length+1) throw"λ��";
	denum=data[i-1];                        //ȡ��ɾ����Ԫ��
	for(int j=i;j<length;j++)
		data[j-1]=data[j];
	length--;
	return denum;
}

