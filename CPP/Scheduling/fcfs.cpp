#include<iostream>
using namespace std;
class process{
	public:
	int at, bt, ct, tat, wt;
	void input()
	{
	cout<<"enter at and bt\n";
	cin>>at>>bt;
	}
	void fcfs()
	{
	tat=ct-at;
	wt=ct-at-bt;
	}
};
int main()
{
	process temp;
	int i,j,n,ct=0;
	float avgwt=0, avgtat=0;
	cout<<"enter number of process:- ";
	cin>>n;
	process p[n];
	for(i=0;i<n;i++)
	p[i].input();

	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	{
		if(p[i].at>p[j].at)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
	if(i==0)
	p[i].ct=p[i].at;
	else
	p[i].ct=ct;
	p[i].ct+=p[i].bt;
	p[i].fcfs();
	ct=p[i].ct;
	}
	for(i=0;i<n;i++)
	{
		avgwt+=p[i].wt;
		avgtat+=p[i].tat;
	}
	avgwt=avgwt/n;
	avgtat=avgtat/n;
	cout<<"at\tbt\tct\ttat\twt\t\n";
	for(i=0;i<n;i++)
	{
	cout<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n";
	}
	cout<<"avg wt="<<avgwt<<"\n";
	cout<<"avg tat="<<avgtat<<"\n";
	return 0;

