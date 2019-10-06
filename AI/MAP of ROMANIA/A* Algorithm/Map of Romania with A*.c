/*
This assignment wishes to send the user(agent) from Arad to Bucharest 
or from any place in the map to Bucharest in the map of Romania using
the Greedy Best First Search. The Straight line distance to reach
Bucharest is the Heuristic Function for this Problem.
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>


int path[20][20];
int dist_bucharest[20];
int visited[20];
int availables[10][2];
char *name[20]={"Arad", "Bucharest" , "Craiova", "Dobreta", "Eforie", "Fagarus", "Giurgiu", "Hirsova", "Lasi", "Lugoj", "Mehadia", "Neamt", "Oradea", "Pitesti", "RimnicuVilcea", "Sibiu", "Timisora", "Urziceni", "Valsui", "Zerind"};
;

void create_map() //initialises the map
{
	for(int i=0; i<20;i++)
		for(int j=0; j<20; j++)
		{
			path[i][j] = 20000;
			path[i][i] = 0;
		}
	path[0][15] = 140;
	path[0][19] = 75;
	path[0][16] = 118;
	path[1][5] = 211;
	path[1][6] = 90;
	path[1][13] = 101;
	path[1][17] = 85;
	path[2][3] = 120;
	path[2][13] = 138;
	path[2][14] = 146;
	path[3][10] = 75;
	path[4][7] = 86;
	path[5][15] = 99;
	path[7][17] = 98;
	path[8][11] = 87;
	path[8][18] = 92;
	path[9][10] = 70;
	path[9][16] = 111;
	path[12][19] = 71;
	path[12][15] = 151;
	path[13][14] = 97;	
	path[14][15] = 80;
	path[17][18] = 142;

	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			path[j][i]= path[i][j];

	dist_bucharest[0]=366;
	dist_bucharest[1]=0;
	dist_bucharest[2]=160;
	dist_bucharest[3]=242;
	dist_bucharest[4]=161;
	dist_bucharest[5]=176;
	dist_bucharest[6]=77;
	dist_bucharest[7]=151;
	dist_bucharest[8]=226;
	dist_bucharest[9]=244;
	dist_bucharest[10]=241;
	dist_bucharest[11]=234;
	dist_bucharest[12]=380;
	dist_bucharest[13]=100;
	dist_bucharest[14]=193;
	dist_bucharest[15]=253;
	dist_bucharest[16]=329;
	dist_bucharest[17]=80;
	dist_bucharest[18]=199;
	dist_bucharest[19]=374;

	for(int i=0;i<20; i++)
		visited[i] = 0;


}

int minimum(int arr[][2],int n) //finds the minimum heuristic value from the "Available" array
{
	int mincount=0;
	int min = 9999;
	for(int i=0; i<n; i++)
	{
		if(arr[i][1] < min)
		{
			min=arr[i][1];
			mincount=arr[i][0];
		}

	}
	return mincount;
}

int stringCmpi (char *s1,char *s2)  // string comparision ignoring cases
{
	int i=0,diff=0;
	for(i=0; s1[i]!='\0'; i++)
	{
		if( toupper(s1[i])!=toupper(s2[i]) )
			return 1;           
	}
	return 0;
}


int main()
{

	create_map();
	printf("\nList of States of Romania..\n");
	for(int i=0; i<20; i++)
	{
		printf("%s\n",name[i]);
	}

	for(int i=0; i<10;i++)
	{
		availables[i][1] = 2000;
		availables[i][0] = 99;
	}

	int steps=0;
	char init[10],dest[10];
	int initpoint,destpoint,currpoint,minpoint, i=0,j=0,k=0;
	strcpy(dest,"Bucharest");
Loop:
	printf("\nEnter the Initial Place from where you want to reach Bucharest: ");
	scanf("%s",&init);


	for(i=0,initpoint=-1,destpoint=-1;i<20;i++)
	{
		if(stringCmpi(name[i],init)==0)
			initpoint=i;
		if(stringCmpi(name[i],dest)==0)
			destpoint=i;		
	}

	if(initpoint == -1 || destpoint == -1 ) {printf("Wrong Entry, Try Again..\n");goto Loop;}
	visited[initpoint]=1;
	currpoint=initpoint;

	printf("\nStarting.. Greedy BFS for the Map of Romania!\n\nThe nodes(States) covered in the process will be displayed below ..\n\nSt. line Distance from Bucharest\tState(Node)\n");
	while(visited[destpoint]!=1 )
	{
		k=0;
		for(j=0;j<20;j++)
		{
			if(path[currpoint][j]<20000 && path[currpoint][j]>0 && visited[j]!=1)
			{
				availables[k][0]=j;
				availables[k][1]=dist_bucharest[j] + path[currpoint][j];
				k++;
			}

		}

		printf("%d\t\t\t\t\t%s\n",dist_bucharest[currpoint],name[currpoint]);
		minpoint=minimum(availables,k);
		visited[currpoint]=1;
		steps++;
		currpoint=minpoint;
	}	
	if(steps!=0){ steps--;}
	if(steps==0){ printf("NIL\t\t\t\t\tBucharest\n\nThe Initial place is the Final place, i.e., You are already in Bucharest!\n");}
	printf("Total no of Steps(traveling to adjacent nodes)= %d\n", steps);
	return 0;
}



