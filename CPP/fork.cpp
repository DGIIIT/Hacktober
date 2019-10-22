//program to use the fork function of the STL

#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;

int fibo(int n)
{
	int i;
	if(n==0) return 0;
	if(n==1) return 1;
	else return fibo(n-1)+fibo(n-2);

}
void fact(int n)
{
	long int prod=1;
	for(;n>0;n--)
		prod*=n;
	cout<<"Factorial n = "<<prod;
}

int main()
{
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	int pid=fork();
	if(pid<0) { cout<<"Child process can not be created!"<<endl;
	}
	else if (pid==0)
	{
		if(n%2==0 ) 
		{
			cout<<"Entered number is even!"<<endl;
			if(fork()==0)
			{cout<<"nth Fibonacci series= ";
			for(int i=0;i<n;i++)
			{
				int t=fibo(i);
				cout<<t<<" ";
			}
			}
		}
		else if(n%2!=0)
		{
			cout<<"Entered number is odd!"<<endl;
		       if(fork()==0)	fact(n);
	}
}
cout<<endl;
}

