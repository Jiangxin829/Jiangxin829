
#include <iostream>
using namespace std;
#include <cstdlib>
#define NULL 0
#define LEN sizeof(struct student)
struct student
{ int num;
  float score;
  struct student *next;
};
int n;

struct student *creat(void) ;   //����������������ͷָ�룬��˺�������Ϊ�ṹ��
void my_printf(struct student *head);  //�������������Ϊͷָ��

int main()
{
	struct student *head;
	head = creat();  //ͨ���ú�������������������ͷָ��
	my_printf(head);  //ͨ��ͷָ�룬�������
	return 0;

}

 struct student *creat(void)  
{  
	 struct student *head,*p1, *p2;  
	 n=0;
	 p1 = p2 = (struct student *)malloc(LEN);   //������ռ�
	 cout <<"Please input num and score(if num is 0, then end input):\n ";
	 cin >> p1->num >> p1->score;
	 head = NULL;        //��ͷ����ʼ��
	 while(p1->num!=0)
	 { 
		 n = n+1;
		 //�۰��½����뵽����
		 if(n ==1)
			 head = p1;        //ͷ��㸳ֵ
		 else p2->next = p1;   //���½��p1���ӵ�p2���� 
		 p2 = p1;              //�½��p1��Ϊ���Ľ��
		 p1 = (struct student *)malloc(LEN);  
		 cin >> p1->num >> p1->score;
	 }
	 p2->next = NULL;    	 //���������

	 return(head);    //����ͷָ��, �ǽṹ������
 }

 void my_printf(struct student *head)
{
  struct student *p;
  cout <<"\n Now,These are " << n <<" records  :\n";
  //���
  p = head;         //�ٴ�ͷָ�뿪ʼ
  while(p!= NULL)
  {
    cout << p->num<<", " << p->score<< endl;
    p = p->next;   //��ָ���ƶ�����һ�����
   } 
}


