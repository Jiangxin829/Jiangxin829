
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

struct student *creat(void) ;   //建立链表函数，返回头指针，因此函数类型为结构体
void my_printf(struct student *head);  //输出函数，参数为头指针

int main()
{
	struct student *head;
	head = creat();  //通过该函数，建立链表，并生成头指针
	my_printf(head);  //通过头指针，输出链表
	return 0;

}

 struct student *creat(void)  
{  
	 struct student *head,*p1, *p2;  
	 n=0;
	 p1 = p2 = (struct student *)malloc(LEN);   //①申请空间
	 cout <<"Please input num and score(if num is 0, then end input):\n ";
	 cin >> p1->num >> p1->score;
	 head = NULL;        //②头结点初始化
	 while(p1->num!=0)
	 { 
		 n = n+1;
		 //③把新结点插入到链表
		 if(n ==1)
			 head = p1;        //头结点赋值
		 else p2->next = p1;   //把新结点p1链接到p2后面 
		 p2 = p1;              //新结点p1作为最后的结点
		 p1 = (struct student *)malloc(LEN);  
		 cin >> p1->num >> p1->score;
	 }
	 p2->next = NULL;    	 //④链表结束

	 return(head);    //返回头指针, 是结构体类型
 }

 void my_printf(struct student *head)
{
  struct student *p;
  cout <<"\n Now,These are " << n <<" records  :\n";
  //输出
  p = head;         //①从头指针开始
  while(p!= NULL)
  {
    cout << p->num<<", " << p->score<< endl;
    p = p->next;   //②指针移动到下一个结点
   } 
}


