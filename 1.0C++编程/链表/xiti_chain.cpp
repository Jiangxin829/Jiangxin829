// 计算平均分

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
float aver;   // 平均分变量
 struct student *creat(void);   //创建链表
 void my_printf(struct student *head);   //输出链表

void main()
{
	struct student *head;
	head = creat();
	my_printf(head);
	cout <<"平均分为：" << aver << endl;
}

 struct student *creat(void)   //创建链表
{  
	 struct student *head,*p1, *p2;
	 float sum = 0;
	 n=0;
	 p1 = p2 = (struct student *)malloc(LEN);
	 cout <<"Please input num and score(if num is 0, then end input):\n ";
	 cin >> p1->num >> p1->score;
	 head = NULL;
	 while(p1->num!=0)   //当学号为0时，结束输入
	 { 
		 n = n+1;
		 sum += p1->score;           // 累加分数
		 if(n ==1)
			 head = p1;
		 else p2->next = p1;
		 p2 = p1;
		 p1 = (struct student *)malloc(LEN);
		 cin >> p1->num >> p1->score;	 }
	 p2->next = NULL;
	 aver = sum/n;  //计算平均分
	 return(head);
 }

 void my_printf(struct student *head)   //输出链表
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


