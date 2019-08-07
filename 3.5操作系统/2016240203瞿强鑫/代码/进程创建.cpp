#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
int mark=1;
int process1()
{
	int pid1,pid2;     
        pid1=fork();
	if(pid1==-1)
	  printf("error!!!\n");
	if(pid1 ==0)
	printf("b");
	else    //father
	{
                pid2=fork();
		if(pid2==-1)
		  printf("error!!!\n");
		if(pid2 ==0)
		  printf("c");
                else
                  printf("a"); 
         }
         exit(0);
        
}
int process2()
{
	int pid1,pid2;
        pid1=fork();
	if(pid1==-1)
	  printf("error!!!\n");  
	if(pid1 ==0)
	printf("I am first child:%d\n",getpid());     
	else    //father
	{ 		
                pid2=fork();          
		if(pid2==-1)		
		  printf("error!!!\n");		
		if(pid2 ==0)		
		  printf("I am second child:%d\n",getpid());		
                else
                  printf("I am parent:%d\n",getpid());		
         }    
         exit(0); 
}
void process3()
{
	int p1,p2; 
	p1=fork();
	if(p1==0) 
	{ 
		
		for(int i=0;i<5;++i)
		{ 
		lockf(1,1,0); 
		printf("I am first child:%d\n",getpid()); 
		lockf(1,0,0); 
		sleep(1); 
		} 
	} 
	else
	{ 
		p2=fork(); 
		if(p2==0) 
		{ 
		
		for(int j=0;j<5;++j) 
		{ 
			lockf(1,1,0);  
			printf("I am second child:%d\n",getpid()); 
			lockf(1,0,0); 
			sleep(1); 
		} 
		
		} 
		else 
		{
		lockf(1,1,0); 
		printf("I am parent:%d\n",getpid()); 
		lockf(1,0,0); 
		}
	} 
}
int process4()
{
	int p1,p2; 
	p1=fork();
	if(p1==0) 
	{ 
		lockf(1,1,0); 
		for(int i=0;i<5;++i)
		{ 
		printf("I am first child:%d\n",getpid()); 
		sleep(1); 
		} 
		lockf(1,0,0); 
	} 
	else
	{ 
		p2=fork(); 
		if(p2==0) 
		{ 
		lockf(1,1,0);  
		for(int j=0;j<5;++j) 
		{ 
			
			printf("I am second child:%d\n",getpid()); 
			
			sleep(1); 
		} 
		lockf(1,0,0); 
		} 
		else 
		{
		lockf(1,1,0); 
		printf("I am parent:%d\n",getpid()); 
		lockf(1,0,0); 
		}
	} 
	return 0; 
}

void stop()
{
	mark=0;
}
int process5()
{
	int pid1,pid2,a;
        pid1=fork();
	if(pid1==-1)
	  printf("error!!!\n");  
	if(pid1 ==0)
	{
		signal(16,stop);
		signal(SIGINT,SIG_IGN);
		//signal(SIGQUIT,SIG_IGN);
		while(mark);
		printf("Child Process1 is killed by Parent！\n"); 
		wait(&a);
		exit(0);
	}	    
	else    //father
	{ 		
                pid2=fork();     
		if(pid2==-1)		
		  printf("error!!!\n");		
		if(pid2 ==0)		
		{
			signal(17,stop); 
			signal(SIGINT,SIG_IGN);
			//signal(SIGQUIT,SIG_IGN);
			while(mark);
			printf("Child Process2 is killed by Parent！\n"); 
			wait(&a);
			exit(0);
		}	   
                else
		{	
			signal(SIGINT,stop);
			while(mark);		
			kill(pid1,16);
			kill(pid2,17);
			wait(&a);
			sleep(1);
                  	printf("Parent Process is killed！\n");  
			exit(0);
		}   
         }   
	  
         exit(0); 
}

int main()
{ 
	int choice;
        printf("1.输出字符2.输出字符串3.lockf里面4.lockf外面5.信号\n");
 	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			process1();
			break;
		case 2:
			process2();
			break;
		case 3:
			process3();
			break;
		case 4:
			process4();
			break;
		case 5:
			process5();
			break;
	}
	exit(0);
}
