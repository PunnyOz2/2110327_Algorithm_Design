#include <bits/stdc++.h>
using namespace std;
struct A{
    int x,y,cou;
    bool operator< (const A&o)const {
        return cou > o.cou;
    }
};
priority_queue<A> q;
A curr;
bool board[1010][1010];
int dis[1010][1010];
int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,b,x,y,ni,nj;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)cin >> x >> y, board[x][y] = true;
    for(int i = 0; i <= 1000; i++)for(int j = 0; j <= 1000; j++)dis[i][j] = 1001000;
    q.push({a,b,0});
    dis[a][b] = 0;
    while(!q.empty()){
        curr = q.top();
        q.pop();
        if((curr.x == 1 || curr.x == 1000) || (curr.y == 1 || curr.y == 1000)){cout << dis[curr.x][curr.y];return 0;}
        for(int i = 0; i < 4; i++){
            ni = curr.x + di[i]; 
            nj = curr.y + dj[i]; 
            if(ni<1 || ni>1000)continue;
            if(nj<1 || nj>1000)continue;
            if(board[ni][nj]){
                if(dis[ni][nj] > curr.cou+1){q.push({ni,nj,curr.cou+1}); dis[ni][nj] = curr.cou+1;}
            }
            else if(dis[ni][nj] > curr.cou) {q.push({ni,nj,curr.cou});   dis[ni][nj] = curr.cou;  }
        }
    }
    return 0;
}