#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int block_time = 10; //����ʱ��Ƭ�ĳ���Ϊ10��
const int MAXPCB = 100; //������������


//������̽ṹ�壬������ ����ʱ�� ����ʱ��	�������ʱ�� ���̵ȴ�ʱ��		
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

//��ʼ������
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

//�����ݺ���
int readData() 
{
	FILE *fp;
	char fname[20];
	int i;

	cout << "�������ȡ�ļ���:";
	cin >> fname;
	if ((fp = fopen(fname, "r")) == NULL) 
	{
		cout << "����,�ļ��򲻿�,�����ļ���" << endl;
	}
	else 
	{
		while (!feof(fp)) 
		{
			fscanf(fp, "%s %d %d", pcbs[quantity].name, &pcbs[quantity].time, &pcbs[quantity].arr_time);
			quantity++;
		}

		//��������������
		cout << "��������������" << endl<<endl<<endl;
		cout << "������ ����ʱ�� ����ʱ��" << endl;
		for (i = 0; i<quantity; i++) {
			cout << " " << pcbs[i].name << "        " << pcbs[i].arr_time << "       " << pcbs[i].time << endl;
		}
		return (1);
	}
	return (0);

}

//��������,�Թ���һ���㷨ʹ��
void init() 
{
	int i;

	for (i = 0; i < MAXPCB; i++)
	{

		pcbs[i].finished = 0;
		pcbs[i].wait_time = 0;
	}
}


//�Ƚ��ȳ��㷨
void FIFO() 
{
	int i, j;
	int total;

	//���FIFO�㷨ִ����
	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "FIFO�㷨ִ����:" << endl;
	cout << "������ �ȴ�ʱ��" << endl;
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
	cout << "�ܵȴ�ʱ��:" << total << " ƽ���ȴ�ʱ��:" << total / quantity << endl;

}



//����ҵ�����㷨
void privilege() 
{
	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "����ҵ�����㷨ִ����:" << endl;
	cout << "������ �ȴ�ʱ��" << endl;
	
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
	cout << "�ܵȴ�ʱ��:" << total << " ƽ���ȴ�ʱ��:" << total / quantity << endl;

}

//ʱ��Ƭ��ת�����㷨
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
	cout << "ʱ��Ƭ��ת������ҵ˳��:";
	for (i = 0; i < total; i++)
	{
		cout << pcbs[queue[i]].name << "  ";
	}
	cout << endl;
}



//������
int main() 
{
	while (true)
	{
	

		cout << endl << endl;
		cout << " **************************************************\n" << endl;
		cout << "  ������������ ���̵���ģ��       ��������������   \n" << endl;
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
		cout << "�����밴0�������������\n";
		char q;
		cin >> q;
		if (q == '0')
		{
			break;
		}
	}
	return 0;
	
	
}
