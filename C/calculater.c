#include<stdio.h>
void main()
{
	char x;
	float a, b, c=0;
	printf("ENTER YOUR CHOICE\n(+)ADDITION\n(-)SUBSTRACTION\n(*)MULTIPLICATION\n(/)DIVISION\n");
	x=getchar();
	printf("ENETR FIRST NUMBER\n");
	printf("ENETR SECOND NUMBER\n");
	scanf("%f",&a);
	scanf("%f",&b);
	switch(x)
	{
		case '+' :
		c=a+b;
		printf("RESULT=%f",c);
		break;
		case '-' :
		c=a-b;
		printf("RESULT=%f",c);
		break;
		case '*' :
		c=a*b;
		printf("RESULT=%f",c);
		break;
		case '/' :
		if(b==0)
		{ printf("DENOMINATOR CAN NOT BE 0\n");
		}
		else
		{c=a/b;
		printf("RESULT=%f",c);}
		break;
		default :
		printf("WRONG INPUT....\n  PLEASE ENTER CORRECT OPERATION LIKE+-*/");
	}
}
