#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main() {
int res,n;
char buffer[100];

res=open("fifo1",O_RDONLY);
n=read(res,buffer,100);
printf("Reader  having PID %d sent the data\n",getpid());
printf("Data received by the receiver %d is: %s\n",getpid(),buffer);
}
