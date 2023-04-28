#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int fib(int n)
 {
 int i;
  int t1 = 0, t2 = 1;
  int nextTerm = t1 + t2;

 
  
  printf("Fibonacci Series: %d, %d, ", t1, t2);

  
  for (i = 3; i <= n; ++i) 
  {
    printf("%d, ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }

}
int main(int argc,char*argv[])
{
 int  n;
 printf("Enter no. of Terms:");
 n=atoi(argv[1]);
 printf("%d\n",n);
 fib(n);

 }
