#include <iostream>
using namespace std;

#include <cstdlib>
#define NULL 0
#define LEN sizeof(struct student)   //�ṹ�峤�ȣ����������ڴ�ռ�
struct student
{
	int num;
	float score;
	struct student *next;   //���������ָ�룬�ǳ���Ҫ
};
int n;

int main()
{
/*�鿴�������͵ĳ���
	cout << LEN <<endl;
	cout << sizeof(float)<<endl;
	cout << sizeof(int) <<endl;
*/
	struct student *head,*p1, *p2;     //�ṹ��ָ�룬�ֱ�Ϊͷָ�롢�½�㡢�����
	n=0;
	p1 = p2 = (struct student *)malloc(LEN);   //��ʹ�ýṹ��ָ��(���)֮ǰ����Ҫ����ռ�
	cout << "������ѧ�š��ɼ���ѧ��Ϊ0ʱ����������" << endl;
	cin >> p1->num >> p1->score;  
	head = NULL;         //ͷָ���ʼ��
	while(p1->num!=0)
	{
		n = n+1;
		if(n ==1)
			head = p1;     //�½����Ϊ��һ�����
		else
			p2->next = p1;  //  ���½�����ӵ������ĺ���
		p2 = p1;   //�½����Ϊ���һ�����
		cout << p1->num<<", "<< p1->score << endl;
		p1 = (struct student *)malloc(LEN);
		cin >> p1->num>> p1->score;
	}
	p2->next = NULL;

	return 0;
}
