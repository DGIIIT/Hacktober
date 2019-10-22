#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define frames 3
int queue[frames]={0,0,0};
int dist[frames]={0,0,0};
int hit=0,miss=0;
int max,maxi,pmax;
int search(int num,int arr[],int k)
{
	
	int ctr=0,flag=0;
	for(int i=0;i<frames;i++)
	{
		if(queue[i]==num)
			flag++;
	}
	if(flag!=0) return 99;
	else
	{
		
		for(int i=0;i<frames;i++)
		{
		for(int j=k;j>=0;j--)
		{
			if(arr[j]==queue[i])
			{
				dist[i]=k-j;
				break;

			}
			dist[i]=50;
		}


		}
//
	printf("\nDist: ");
	for(int i=0;i<frames;i++)
	{
		printf("%d\t",dist[i] );
	}
	printf("\n");
	
//
		max=0;
		for(int i=0;i<frames;i++)
		{
			if(dist[i]>max)		{max=dist[i];	maxi=i;	}	
		/*	else
			{
				maxi=(pmax+1)%frames;
			}
		*/
		}
		pmax=maxi;
		return maxi;
		
	}	
}
void display()
{
	for(int i=0;i<frames;i++)
	{
		printf("%d\t",queue[i] );
	}
	printf("\n");
}
int main()
{
	int arr[20];
	int i,j,k;
	for(i=0;i<20;i++)
	{
		arr[i]=rand();
		arr[i]%=10;
	}
	printf("Reference Tree:\n");
	for(i=0;i<20;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nStacks are:\n");
	i=0;
	for(k=0;k<3;k++,i++)
	{
		queue[i]=arr[k];
		display();
	}
	i=0;
	while(k<20)
	{
		int ref=search(arr[k],arr,k);
		printf("\nRef=%d\n",ref);
		if(ref == 99)
		{
			hit++;
			printf("PH\n");
		}
		else
		{
			miss++;
			queue[ref]=arr[k];
			display();	
		}
		
		k++;
	}
	printf("\nHit= %d\nMiss=%d",hit,miss);
	return 0;
}