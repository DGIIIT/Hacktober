// HACKERRANK QUEEN'S ATTACK II
#include<iostream>
using namespace std;
#define MAX 5000

int queen_attack(int size,int queen_row,int queen_column,int obstacles,int r[],int c[]){
    int count = 0;
    char chess[MAX][MAX];
    for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        chess[i][j] = 'X'; 
    }    
    }
    chess[size-queen_row][queen_column-1] = 'Q';
    for(int i=0;i<obstacles;i++){
        chess[size-r[i]][c[i]-1] = 'O';
    }

    for(int i=queen_column;i<size;i++){
        
        if(chess[size-queen_row][i] == 'O'){
            i = size;
        }
        else if(chess[size-queen_row][i] == 'X'){    
              count = count+1;
        }
        else {}
    } // 1st right side
    
      for(int i=queen_column-2;i>=0;i--){
        
        if(chess[size-queen_row][i] == 'O'){
            i = 0;
        }
        else if(chess[size-queen_row][i] == 'X'){    
              count = count+1;
        }
        else {}
    }  // 2nd left side
      
      for(int i=1;size-queen_row+i<size;i++){
          if(chess[size-queen_row+i][queen_column-1] == 'O'){
                   i = queen_row;
          }
          else if(chess[size-queen_row+i][queen_column-1] == 'X'){
              count = count+1;
          }
              else {}
          } // 3rd down side
    
          for(int i=1;size-queen_row-i>=0;i++){
          if(chess[size-queen_row-i][queen_column-1] == 'O'){
                       i = size-queen_row;
          }    
          else if(chess[size-queen_row-i][queen_column-1] == 'X'){
              count = count+1;
          }
          else {}
          } // 4th up side
    
          for(int i=1;queen_column-1+i<size;i++){
          if(chess[size-queen_row+i][queen_column-1+i] == 'O'){
                        i = size+1-queen_column;
          }    
          else if(chess[size-queen_row+i][queen_column-1+i] == 'X'){
              count = count+1;
          }
          else {}
          } // 5th right down ,
    
          for(int i=1;size-queen_row-i>=0;i++){
          if(chess[size-queen_row-i][queen_column-1-i] == 'O'){
                           i = size-queen_row;
          }    
          else if(chess[size-queen_row-i][queen_column-1-i] == 'X'){
              count = count+1;
          }
           else {}
          }   // 6th left up
    
          for(int i=1;size-queen_row-i>=0;i++){
          if(chess[size-queen_row-i][queen_column-1+i] == 'O'){
                               i = size-queen_row;
          }    
          else if(chess[size-queen_row-i][queen_column-1+i] == 'X'){
              count = count+1;
          }
          else {}
          } // 7th right up 
         
          for(int i=1;queen_column-1-i>=0;i++){
          if(chess[size-queen_row+i][queen_column-1-i] == 'O'){
                      i = queen_column+1;
          }    
          else if(chess[size-queen_row+i][queen_column-1-i] == 'X'){
              count = count+1;
          }
          else {}
          }   // 8th left down
          return count;
    }

int main() {

int size;
int obstacles;

cin >> size >> obstacles;
int queen_row,queen_column;
int r[MAX],c[MAX];

cin >> queen_row >> queen_column;
for(int i=0;i<obstacles;i++){
    cin >> r[i] >> c[i];
}
int result = queen_attack(size,queen_row,queen_column,obstacles,r,c);
cout << result;
return 0;
}
