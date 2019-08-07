#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int block_time = 10; //定义时间片的长度为10秒
const int MAXPCB = 100; //定义最大进程数


//定义进程结构体，进程名 所需时间 到达时间	进程完成时间 进程等待时间		
typedef struct node  
{
	char name[20];
	int time;
	int arr_time;

	int finished;   
	int wait_time;  
} pcb;

pcb pcbs[MAXPCB];
int quantity;

//初始化函数
void initial() 
{
	int i;

	for (i = 0; i<MAXPCB; i++) 
	{
		strcpy(pcbs[i].name, "");
		pcbs[i].time = 0;
		pcbs[i].arr_time = 0;

		pcbs[i].finished = 0;
		pcbs[i].wait_time = 0;
	}

	quantity = 0;
}

//读数据函数
int readData() 
{
	FILE *fp;
	char fname[20];
	int i;

	cout << "请输入读取文件名:";
	cin >> fname;
	if ((fp = fopen(fname, "r")) == NULL) 
	{
		cout << "错误,文件打不开,请检查文件名" << endl;
	}
	else 
	{
		while (!feof(fp)) 
		{
			fscanf(fp, "%s %d %d", pcbs[quantity].name, &pcbs[quantity].time, &pcbs[quantity].arr_time);
			quantity++;
		}

		//输出所读入的数据
		cout << "输出所读入的数据" << endl<<endl<<endl;
		cout << "进程名 到达时间 所需时间" << endl;
		for (i = 0; i<quantity; i++) {
			cout << " " << pcbs[i].name << "        " << pcbs[i].arr_time << "       " << pcbs[i].time << endl;
		}
		return (1);
	}
	return (0);

}

//重置数据,以供另一个算法使用
void init() 
{
	int i;

	for (i = 0; i < MAXPCB; i++)
	{

		pcbs[i].finished = 0;
		pcbs[i].wait_time = 0;
	}
}


//先进先出算法
void FIFO() 
{
	int i, j;
	int total;

	//输出FIFO算法执行流
	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "FIFO算法执行流:" << endl;
	cout << "进程名 等待时间" << endl;
	for (i = 0; i<quantity; i++) 
	{
		cout << " " << pcbs[i].name << "       " <<  pcbs[i].wait_time << endl;

		for (j = i + 1; j<quantity; j++) 
		{
			pcbs[j].wait_time += pcbs[i].time;
		}
	}
	total = 0;
	for (i = 0; i < quantity; i++)
	{
		total += pcbs[i].wait_time;
	}
	cout << "总等待时间:" << total << " 平均等待时间:" << total / quantity << endl;

}



//短作业优先算法
void privilege() 
{
	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "短作业优先算法执行流:" << endl;
	cout << "进程名 等待时间" << endl;
	
	pcb sort[MAXPCB];
	for (int i = 0; i<MAXPCB; i++)
	{
		strcpy(sort[i].name, "");
		sort[i].time = 0;
		sort[i].arr_time = 0;

		sort[i].finished = 0;
		sort[i].wait_time = 0;
	}

	for (int i = 0; i < quantity-1; i++)
	{
		char *k = pcbs[i+1].name;
		strcpy(sort[i].name, k);
		sort[i].time = pcbs[i+1].time;
	}

	for (int i = 1; i <quantity-1; i++)
	{
		int j, v;
		char *k;
		for (v = sort[i].time,k=pcbs[i+1].name, j = i - 1; j >= 0 && v < sort[j].time; j--)
		{
			sort[j + 1].time = sort[j].time;

			strcpy(sort[j + 1].name, sort[j].name);

		}
			
		sort[j + 1].time = v;
		strcpy(sort[j + 1].name, k);
	}

	cout << " " << pcbs[0].name << "       " << pcbs[0].wait_time << endl;
	for (int i = 0; i<quantity-1; i++)
	{
		cout << " " << sort[i].name << "       " << sort[i].wait_time << endl;

		for (int j = i + 1; j<quantity; j++)
		{
			sort[j].wait_time += sort[i].time;
		}
	}
	int total = 0;
	for (int i = 0; i < quantity; i++)
	{
		total += sort[i].wait_time;
	}
	cout << "总等待时间:" << total << " 平均等待时间:" << total / quantity << endl;

}

//时间片轮转调度算法
void timer() 
{
	int i, j, number, flag = 1;
	int passed_time = 0;
	int max_time = 0;
	int round = 0;

	int queue[1000];
	int total = 0;

	while (flag == 1) 
	{
		flag = 0;
		number = 0;

		for (i = 0; i < quantity; i++)
		{
			if (pcbs[i].finished == 0) 
			{
				number++;
				j = i;
			}
		}

		/*if (number == 1)
		{
			queue[total] = j;
			total++;
			pcbs[j].finished = 1;
		}*/

		if (number>0) 
		{
			for (i = 0; i < quantity; i++)
			{
				if (pcbs[i].finished == 0) 
				{
					flag = 1;
					queue[total] = i;
					total++;
					if (pcbs[i].time <= block_time* (round + 1))
					{
						pcbs[i].finished = 1;
					}
				}
			}
		}
		round++;
	}

	/*if (queue[total - 1] == queue[total - 2]) 
	{
		total--;
	}
	*/

	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "时间片轮转调度作业顺序：:";
	for (i = 0; i < total; i++)
	{
		cout << pcbs[queue[i]].name << "  ";
	}
	cout << endl;
}



//主函数
int main() 
{
	while (true)
	{
	

		cout << endl << endl;
		cout << " **************************************************\n" << endl;
		cout << "  　　　　　　 进程调度模拟       　　　　　　　   \n" << endl;
		cout << " **************************************************" << endl;
		cout << endl << endl;

		initial();
		int flag;
		flag = readData();

		if (flag == 1) 
		{
			init();
			FIFO();
			init();

			privilege();
			init();

			timer();
			
		}

		cout << endl << endl;
		cout << "结束请按0，按任意键继续\n";
		char q;
		cin >> q;
		if (q == '0')
		{
			break;
		}
	}
	return 0;
	
	
}
