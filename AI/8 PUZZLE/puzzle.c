#include<stdio.h>
int i,j;
void swap(int x, int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void move_up(int arr_in[][3])
{
	for(i=0;i<3;i++)
	{
	for(i=0;j<3;j++)
	{
		if(arr_in[i][j]==0)
		{
		swap(arr_in[i][j],arr_in[i-1][j]);
		}
	}
	}
}
void move_down(int arr_in[][3])
{
	for(i=0;i<3;i++)
	{
	for(i=0;j<3;j++)
	{
		if(arr_in[i][j]==0)
		{
		swap(arr_in[i][j],arr_in[i+1][j]);
		}
	}
	}
}
void move_left(int arr_in[][3])
{
	for(i=0;i<3;i++)
	{
	for(i=0;j<3;j++)
	{
		if(arr_in[i][j]==0)
		{
		swap(arr_in[i][j],arr_in[i][j-1]);
		}
	}
	}
}
void move_right(int arr_in[][3])
{
	for(i=0;i<3;i++)
	{
	for(i=0;j<3;j++)
	{
		if(arr_in[i][j]==0)
		{
		swap(arr_in[i][j],arr_in[i][j+1]);
		}
	}
	}
}
void puzzle(int arr_in[][3],int i,int j,int arr_fi[][3])
{
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	{
		if(arr_in[i][j]==arr_fi[i][j])
		{
		continue;
		}
		else
		break;
	}
	}

}
void main()
{
	int arr_in[3][3],arr_fi[3][3],i,j;
	printf("enter puzzle's initial position: \n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
	scanf("%d",&arr_in[i][j]);
	}
	printf("enter puzzle's final position: \n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
	scanf("%d",&arr_fi[i][j]);
	}
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	{
	printf("%d ",arr_fi[i][j]);
	}
	printf("\n");
	}
}
