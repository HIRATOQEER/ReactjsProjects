include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
	pid_t p;
	p=fork();
	
	if(p==0)
	{
		execv("fib",argv);
	}
	
	return 0;
}
