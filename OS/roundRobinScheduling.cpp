#include<iostream>
#include<stdlib.h>
using namespace std;
int front = -1;
int rear = -1;
int arr[5000];
class AB{
public:
	int n,at,bt,ct,tat,wt,btt,v;
	void input()
	{
		cout<<"Enter the Process No:-";		cin>>n;
		cout<<"Enter the AT:-";			cin>>at;
		cout<<"Enter the BT:-";			cin>>bt;

	}
};

void enqueue(int a)
{  if(rear==4999)
	{printf("QUEUE OVERFLOW\n");}

else{
	if(front==-1)
		{front=0;}
	rear++;
	arr[rear]=a;
    }
 
}

int dequeue()
{
	if(rear==-1||front>rear)
		{cout<<"Hii\n";}
 else
 	front++;
 	return arr[front-1];
    
}
void display()
{
	if(rear==-1||front==rear+1)
		{printf("The queue is empty\n");}
	else{
	printf("The queue is :-\n");
	for(int i=front;i<=rear;i++)
	{
		printf("%d\n",arr[i]);
			}
}
}

int main()
{   int nn,nnn;
	cout<<"Enter the no of process:-";
	cin>>nn;  nnn=nn+1;
    
    AB a[nnn],temp;
    int i,j,sum=0,z,k=1,b,s,y=0;
    float s1=0,s2=0;
	for(i=1;i<=nn;i++)
	{
		a[i].input();
		a[i].btt=a[i].bt;
		sum=sum+a[i].btt;
	}
 

	cout<<"Enter the Time Quantum :-";
	cin>>z;

	for(i=0;i<nn-1;i++)
	{
		for(j=1;j<nn-i;j++)
		{

			if(a[j].at>a[j+1].at)
			{
        	    temp=a[j];
           		a[j]=a[j+1];
           		a[j+1]=temp;
			}
		} 
	}  
      
for(i=1;i<=nn;i++)
{
	a[i].v=i;
}
      

  	if(a[1].at==0)
  		{
   			for(i=1;i<=nn;i++)
    			{
        		if(a[i].at==0)
    			{enqueue(a[i].v); k++;} 	
    			 }
  		}

	 else 
 		{ 	enqueue(a[1].v); k++;}
	
 	b=a[1].at;
    //while(y<nn)
  	while(b<sum)
    	{   
    	
       	  	s=dequeue();
       	  	
	    	if(a[s].btt >= z)
					{ a[s].btt -= z;  b += z;} 

			else 
		      	{  b += a[s].btt;   a[s].btt = 0; }

		      
             	       	
		  				

     	 	for(i=k;i<=nn;i++)
     			{
       				if(a[i].at<=b)
						{
							enqueue(a[i].v);
							k++;
						}
	 			}


	 		if(a[s].btt != 0)
	 		 	{
	 		 		//cout<<"\n"<<s<<" "<<a[s].btt;
	 		 		enqueue(s);} 
					 
	 		else if(a[s].btt==0)
				{	a[s].ct=b; }//y++;}
			
					
		}

	for(i=1;i<=nn;i++)
	{
		a[i].wt=0; a[i].tat=0;
		a[i].tat = a[i].ct - a[i].at;
		a[i].wt=a[i].ct-a[i].at-a[i].bt;
		

	}
	cout<<"Pro_no."<<"\t\t"<<"AT"<<"\t\t"<<"BT"<<"\t\t"<<"CT"<<"\t\t"<<"TAT"<<"\t\t"<<"WT"<<"\n";
	for(i=1;i<=nn;i++)
     {
     	s1 += a[i].tat;
		s2 += a[i].wt;
     	 	cout<<a[i].n<<"\t\t"<<a[i].at<<"\t\t"<<a[i].bt<<"\t\t"<<a[i].ct<<"\t\t"<<a[i].tat<<"\t\t"<<a[i].wt<<"\n";
     }
    s1=s1/6; s2=s2/6;
     cout<<"Avg_TAT:-\t"<<s1<<endl;
     cout<<"Avg_WT:-\t"<<s2<<endl;

    return 0;

	}

