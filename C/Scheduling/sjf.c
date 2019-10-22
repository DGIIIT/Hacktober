#include<stdio.h>
#include<stdlib.h>
int i,j,n,cpu,start=-1,end=-1,l=0, check=0, total=0;
float atat=0.0,awt=0;
struct data{
	int at,bt,p_no,rt,ct,p,tat,wt;
}rq[10],temp1;
int k=0;
int main()
{
	struct data aa[10];
	printf("enter number of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter process no. ,AT and BT respectively\n");
		scanf("%d%d%d",&aa[i].p_no,&aa[i].at,&aa[i].bt);
		aa[i].rt=aa[i].bt;
		aa[i].p=0;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(aa[j].at > aa[j+1].at)
			{
				temp1=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=temp1;
			}
		}
	}
	cpu=aa[0].at;
	int minbt;int mbt;
	while(l != n)
	{  mbt=-1;
		minbt=9999;
	for(j=0;j<n;j++)
		{
			if(aa[j].at<=cpu && aa[j].p==0 && aa[j].rt < minbt)
			{
				minbt=aa[j].rt;
				mbt=j;
			}

		}
		if(mbt !=-1)
		{
		cpu++;
		aa[mbt].rt--;
		if(aa[mbt].rt==0)
		{
			aa[mbt].ct=cpu;
			aa[mbt].p=1;
			l++;
			//printf("%d\t%d\t\n",aa[mbt].p_no,aa[mbt].ct);
		}
		}
		else cpu++;
	}
	for(i=0;i<n;i++){
		aa[i].tat=aa[i].ct-aa[i].at;
		aa[i].wt=aa[i].tat-aa[i].bt;
	}
	for(i=0;i<n;i++){
		atat+=aa[i].tat;
		awt+=aa[i].wt;
	}
	atat=atat/n;
	awt=awt/n;
	printf("p_no\tAT\tBT\tCT\tTAT\tWT\n");

	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",aa[i].p_no,aa[i].at,aa[i].bt,aa[i].ct,aa[i].tat,aa[i].wt);
	}
	printf("avg tat=%f\navg wt=%f",atat,awt);
}
