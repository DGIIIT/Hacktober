#include<stdio.h>
char NODE[10];
int NEXT[10],ADJ[10],DEST[12],LINK[12],STATUS[10];

void FIND(char* INFO1,int* NEXT1,int STATUS1,char ITEM1);

int LOC;
int START,AVAILN,AVAILE;

void main()
{
	int PTR1, PTR;
	char N, STACK[25];
	int TOP;

	START=3;
	AVAILN=4;
	AVAILE=1;
	TOP=-1;

	NODE[1]='C'; NODE[3]='A'; NODE[5]='E'; NODE[6]='B'; NODE[8]='D';

	NEXT[0]=2; NEXT[1]=8; NEXT[2]=7; NEXT[3]=6; NEXT[4]=0;
	NEXT[5]=-1; NEXT[6]=1; NEXT[7]=9; NEXT[8]=5; NEXT[9]=-1;

	ADJ[1]=-1; ADJ[3]=2; ADJ[5]=10; ADJ[6]=5; ADJ[8]=0;

	DEST[0]=1; DEST[2]=6; DEST[3]=8; DEST[5]=8; DEST[6]=5;
	DEST[9]=1; DEST[10]=1;

	LINK[0]=6; LINK[1]=4; LINK[2]=9; LINK[3]=-1; LINK[4]=7; LINK[5]=-1;
	LINK[6]=-1; LINK[7]=-8; LINK[8]=11; LINK[9]=3; LINK[10]=-1; LINK[11]=-1;

	STATUS[1]=1; STATUS[3]=1; STATUS[5]=1; STATUS[6]=1; STATUS[8]=1;

	TOP=TOP+1;
	STACK[TOP]='A';
	FIND(&NODE[0],&NEXT[0],START,'A');
	STATUS[LOC]=2;
	PTR=ADJ[LOC];

	do
	{
		N=STACK[TOP];
		TOP=TOP-1;
		printf("%c\t",N);
		FIND(&NODE[0],&NEXT[0],START,'A');
		STATUS[LOC]=3;
		while(PTR!=-1)
		{
			FIND(&NODE[0],NEXT[0].START,NODE[DESST[PTR]]);
			if(STATUS[LOC]==1)
			{
				TOP=TOP+1;
				STACK[TOP]=NODE[LOC];
				STATUS[LOC]=2;
			}
			PTR1=LINK[PTR1];
		}
	}while(TOP!=-1);
}


void FIND(char* INFO1,int* NEXT1, int START1.char ITEM1)
{
	int PTR=START1;
	while(PTR!=-1)
	{
		if(ITEM1==INFO[PTR])
		{
			LOC=PTR;
			return;
		}
		else
			PTR=NEXT1[PTR];
	}
	LOC=-1;
}


