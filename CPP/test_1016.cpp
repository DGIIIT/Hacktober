// hackerrank climbing the leaderboard
#include<iostream>
using namespace std;
#define MAX 50000

struct other_players {
       int score;
       int rank;
};

struct alice {
       int points;
       int position;
};

void give_rankings(struct other_players p[],int players){
     p[0].rank = 1;
     for(int i=1;i<players;i++){
        p[i].rank =98;
     }
     for(int i=1;i<players;i++){
        if(p[i].score == p[i-1].score){
            p[i].rank = p[i-1].rank;
        }
        else {
            p[i].rank = p[i-1].rank+1;
        }
     }
 }

void alice_rankings(struct alice q[],int alice_played,struct other_players p[],int players){
     
     for(int i=0;i<alice_played;i++){    
     for(int k=players-1;k>=0;k--){
     if(q[i].points >=p[0].score){
         q[i].position = p[0].rank;
     }    

     else if(q[i].points >= p[k].score && q[i].points < p[k-1].score){
         q[i].position = p[k].rank;
         k = 0;
     }
     else {
     }
   }
 }
}

int main () {
    int players;
    int alice_played;
    struct other_players p[MAX];
    struct alice q[MAX];

    cin >> players;
    for(int i=0;i<players;i++){
        cin >> p[i].score;
    }
    give_rankings(p,players);

    cin >> alice_played;

    for(int i=0;i<alice_played;i++){
        cin >> q[i].points;
    }
   
    for(int i=0;i<alice_played;i++){
        q[i].position = p[players-1].rank+1;
    }
    alice_rankings(q,alice_played,p,players);
   
    for(int i=0;i<alice_played;i++){
        cout << q[i].position << endl;
    }
    
    return 0;
}
