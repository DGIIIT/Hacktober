/*
The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.

This program is an Example of banker's algorithm with predefined allocation of resources for the given 5 proceses. The total number of resources assumed here is 3.
*/

#include<stdio.h>
#define n 5
#define m 3
	

int fin=0,finrq=0;							//no of processes finished for work | finished after request
int allocation[n][m]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};   	//initial resource allocation
int max[n][m]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};		//maximum resource allocation for completion of the process
int available[m]={3,3,2};						//available resources
int work[m]={3,3,2};							//temp available resources for calculation of system as safe or unsafe
int finish[n]={0,0,0,0,0};						//array for determining the condition of ith process for work
int finishrq[n]={0,0,0,0,0};						//array for determining the condition of ith process after request alc
int need[n][m];								//array for determining the need of resources by a process
int request[m];								//the requested no of resources fot the process indexed by 'rq'
int rq;

//calculating the need
void calcneed()								
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			need[i][j]=max[i][j] - allocation[i][j];
		}
		finish[i]=0;
	}
}

//updating the work
void updatework(int i)
{
	for(int j=0;j<m;j++)
	{
		work[j]=work[j] + allocation[i][j];		
	}
	finish[i]=1;
	fin++;

}

//checking for system being safe or unsafe
int check()
{
	calcneed();
	int i,j,ctr=0,flag=0;
	while(fin<5)
	{
	
	for(i=0;i<n;i++)
	{
		ctr=0;
		if(finish[i]==0)
		{
			for(j=0;j<m;j++)
			{
				if(need[i][j] > work[j])
					ctr++;
			}
			if(ctr==0)
				updatework(i);
		}
	}
	flag++;
	if(flag>5) break;
	}
	if(fin!=5) {printf("SYSTEM is NOT SAFE !\n"); return 0;}
	else	{printf("SYSTEM IS SAFE !\n"); return 1;}
}
//Safety finished

//resource request

//this function updates for safety checking
void update(int i)
{
	for(int j=0;j<m;j++)
	{
		available[j]-=request[j];
		allocation[i][j]+=request[j];
		need[i][j]-=request[j];
	}
}
//reversing update in case of not safe !
void updaterev(int i)
{
	for(int j=0;j<m;j++)
	{
		available[j]+=request[j];
		allocation[i][j]-=request[j];
		need[i][j]+=request[j];
	}
}

//this checks if the resources requested is valid or not
int rsrq()
{
	int j,ctr=0;
	for(j=0;j<m;j++)
	{
		if(request[j]>need[rq][j]) ctr++;
	}
	if(ctr!=0) {printf("\nProcess request exceeds its max demand!\n");	return 0;}
	ctr=0;
	for(j=0;j<m;j++)
	{
		if(request[j]>available[j]) ctr++;
	}
	if(ctr!=0) {printf("\nProcess must wait as resources are not available !\n");	return 0;}
	update(rq);
	int ch1=check();
	if(ch1==0) updaterev(rq);
	else{
		
		for(j=0,ctr=0;j<m;j++)
		{
			if(allocation[rq][j]!=max[rq][j]) ctr++;
		}
		if(ctr!=0) return 0;
		for(int j=0;j<m;j++)
		{
			available[j]+=allocation[rq][j];
			allocation[rq][j]=0;max[rq][j]=0;
		}
		finishrq[rq]=1;finrq++;
		
	}
	
}
//displays allocated, maximum, needed and available resources
void display()
{
	int i1,j1;
	printf("Allocation:\n");
	for(i1=0;i1<n;i1++)
	{	
		for(j1=0;j1<m;j1++)
		{
			printf("%d\t",allocation[i1][j1]);
		}printf("\n");
	}
	//max available need 
	printf("Max:\n");
	for(i1=0;i1<n;i1++)
	{	
		for(j1=0;j1<m;j1++)
		{
			printf("%d\t",max[i1][j1]);
		}printf("\n");
	}
	printf("Need:\n");
	calcneed();
	for(i1=0;i1<n;i1++)
	{	
		for(j1=0;j1<m;j1++)
		{
			printf("%d\t",need[i1][j1]);
		}printf("\n");
	}
	printf("Available:\n");	
	for(j1=0;j1<m;j1++)
	{
		printf("%d\t",available[j1]);
	}
	printf("\n");
}
int main() 
{
	//initialize();
	int i,j,ch;
	top:
	display();
	ch=check();
	if(ch=0) return 0;
	
	printf("Enter Requested process (index starting from 0) :");scanf("%d",&rq);
	printf("Enter the request:");
	for(j=0;j<m;j++)
	{
		scanf("%d",&request[j]);
	}
	rsrq();
	printf("\nReq more: 1/0\n");
	int ans;	
	scanf("%d",&ans);
	while(finrq<5){ if(ans==1) goto top; else break;}
	
	return 0;
}



