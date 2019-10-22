#include<stdio.h>
#define LIMIT 100
void show(int mat[LIMIT][LIMIT], int n);
void new_graph();
int adjacency_matrix[LIMIT][LIMIT];
int n;
int main()
{
      int P[LIMIT][LIMIT];
      int i, j, k;
      new_graph();
      printf("\nadjacency_matrixacency Matrix\n");
      show(adjacency_matrix, n);
      for(i = 0; i < n; i++)
      {
            for(j = 0; j < n; j++)
            {
                  P[i][j] = adjacency_matrix[i][j];
            }
      }
      for(k = 0; k < n; k++)
      {
            for(i = 0; i < n; i++)
            {
                  for(j = 0; j < n; j++)
                  {
                        P[i][j] = (P[i][j] || (P[i][k] && P[k][j]));
                  }
            }
            printf("P%d is: \n", k);
            show(P, n);
      }
      printf("P%d is the path matrix of the given graph\n", k - 1);
      return 0;
}
void show(int mat[LIMIT][LIMIT], int n)
{
      int i, j;
      for(i = 0; i < n; i++)
      {
            for(j = 0; j < n; j++)
            {
                  printf("%3d", mat[i][j]);
            }
            printf("\n");
      }
}
void new_graph()
{
      int count, maximum_edges, origin, destination;
      printf("Enter Total Number of Vertices:\t");
      scanf("%d", &n);
      maximum_edges = n * (n - 1);
      for(count = 1; count <= maximum_edges; count++)
      {
            printf("\nCo - Ordinates for Edge No. %d [(-1 -1) To Quit]:\t", count);
            printf("\nEnter Origin Point:\t");
            scanf("%d", &origin);
            printf("\nEnter Destination Point:\t");
            scanf("%d", &destination);
            if((origin == -1) && (destination == -1))
            {
                  break;
            }
            if(destination >= n ||  origin < 0 || origin >= n || destination < 0)
            {
                  printf("Invalid Edge Input:\n");
                  count--;
            }
            else
            {
                  adjacency_matrix[origin][destination] = 1;
            }
      }
}
