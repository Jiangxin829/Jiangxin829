// ����ƽ����

#include <iostream>
using namespace std;
#include <cstdlib>
#define NULL 0
#define LEN sizeof(struct student)
struct student
{
	int num;
	float score;
	struct student *next;
};
int n;
float aver;   // ƽ���ֱ���
 struct student *creat(void);   //��������
 void my_printf(struct student *head);   //�������

void main()
{
	struct student *head;
	head = creat();
	my_printf(head);
	cout <<"ƽ����Ϊ��" << aver << endl;
}

 struct student *creat(void)   //��������
{  
	 struct student *head,*p1, *p2;
	 float sum = 0;
	 n=0;
	 p1 = p2 = (struct student *)malloc(LEN);
	 cout <<"Please input num and score(if num is 0, then end input):\n ";
	 cin >> p1->num >> p1->score;
	 head = NULL;
	 while(p1->num!=0)   //��ѧ��Ϊ0ʱ����������
	 { 
		 n = n+1;
		 sum += p1->score;           // �ۼӷ���
		 if(n ==1)
			 head = p1;
		 else p2->next = p1;
		 p2 = p1;
		 p1 = (struct student *)malloc(LEN);
		 cin >> p1->num >> p1->score;	 }
	 p2->next = NULL;
	 aver = sum/n;  //����ƽ����
	 return(head);
 }

 void my_printf(struct student *head)   //�������
{
  struct student *p;
   cout <<"\n Now,These are " << n <<" records  :\n";
  p = head;
  if(head != NULL)
  do
  {
   cout << p->num<<", " << p->score<< endl;
      p = p->next;
   } while(p!= NULL);
}


