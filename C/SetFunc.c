#include<stdio.h>
void input(int *a,int *b,int *c,int n,int m) //Taking Inputs of the 2 Sets
{
  printf("Enter Set A Elements\n");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("Enter Set B Elements\n");
  for(int i=0;i<m;i++)
  scanf("%d",&b[i]);
}
void Display(int *c, int len) //function to Display the set
{
    for(int i=0;i<len;i++)
    printf("%d ",c[i]);
}
void Union(int *a,int *b,int *c,int n,int m){ //Function to Find
                                              //the Union of Sets
    int k=0,l=0,flag=1;
    for(int i=0;i<n;i++)
    {
        c[i]=a[i];
        k++;

    }
    l=k;
    for(int i=0;i<m;i++)
    {   flag=1;
        for(int j=0;j<l;j++)
        if(c[j]==b[i])
        flag=0;
    if(flag==1)
    {
        c[k]=b[i];
        k++;
    }

    }
    Display(c,k);                         //Function Call to Display Result
}

int Difference(int *a,int *b,int *c,int n,int m,int fl)//Function To
                                  //Find Difference and Intersection of Sets
{
  int f=0,k=0;
  for(int i=0;i<n;i++)
  { f=0;
    for(int j=0;j<m;j++)
    {
      if(a[i]==b[j])
      f=1;
    }
    if(f==0)
    {c[k]=a[i];
    k++;
  }
  }

  if(fl==1)
  Display(c,k);                   //Function Call to Display Result
  return k;
}
void Member(int x,int *s,int n) //To check if a number belongs
                                  //to a particular set
{
  int f=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]==x)
      { f=1;
        printf("Yes,It is a Member of the Set\n");
        break;
      }
    }
    if(f==0)
    printf("No,It is not a Member of the Set\n");
}

int main(){
    int n,m;
    printf("Enter the size of Set A and Set B\n");
    scanf("%d %d",&n,&m);
    int a[n],b[m],c[n+m],d[n+m],k,ch,x;
    input(a,b,c,n,m);
    do{
    printf("\nEnter To Find :\n1.Union\n2.Intersection\n3.A-B\n4.B-A\n5.Check if Member of A\n6.Check if Member of B\n0.To Exit\n");
    scanf("%d",&ch);
    switch(ch)          //Menu For User to Choose From
    {
        case 1:
        printf("\nThe Union is:");
        Union(a,b,c,n,m);
        break;
        case 2:
        printf("\nThe Intersection is:");
        k=Difference(a,b,c,n,m,0);
        Difference(a,c,d,n,k,1);
        break;
        case 3:
        printf("\nThe Difference(A-B) is:");
        Difference(a,b,c,n,m,1);
        break;
        case 4:
        printf("\nThe Difference(B-A) is:");
        Difference(b,a,c,m,n,1);
        break;
        case 5:
        printf("\nEnter Number to check if it is a Member\n");
        scanf("%d",&x);
        Member(x,a,n);
        break;
        case 6:
        printf("\nEnter Number to check if it is a Member\n");
        scanf("%d",&x);
        Member(x,b,m);
        break;


    }
  }while(ch!=0);





}
