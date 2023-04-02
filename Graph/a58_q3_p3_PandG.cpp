#include <bits/stdc++.h>
using namespace std;
struct A{
    int ti,ri,ci;
    bool operator<(const A&o)const {
        return ti>o.ti;
    }
};
int di[5] = {1,-1,0,0,0},dj[5] = {0,0,1,-1,0};
priority_queue<A> q;
int dis[110][110];
bool mark[110][110];
vector<string> board;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int R,C,n,T,r,c,ti,ri,ci,ni,nj,Q;
    cin >> Q;
    while(Q--){
        cin >> R >> C >> n >> T >> r >> c;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                dis[i][j] = 1<<30;
                mark[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            cin >> ti >> ri >> ci;
            q.push({ti,ri,ci});
            dis[ri][ci] = ti;
        }
        string s;
        board.clear();
        for(int i = 0; i < R; i++){
            cin >> s;
            board.push_back(s);
        }
        while(!q.empty()){
            A curr = q.top();
            q.pop();
            for(int i = 0; i < 4;i++){
                ni = curr.ri + di[i];
                nj = curr.ci + dj[i];
                if(ni<0 || ni>=R)continue;
                if(nj<0 || nj>=C)continue;
                if(board[ni][nj]=='#')continue;
                if(dis[ni][nj] > curr.ti+1){dis[ni][nj] = curr.ti+1, q.push({curr.ti+1,ni,nj});}
            }
        }
        while(!q.empty())q.pop();
        q.push({0,r,c});
        mark[r][c] = true;
        while(!q.empty()){
            A curr = q.top();
            q.pop();
            if(dis[curr.ri][curr.ci] > T){cout << "YES\n";goto jump;}
            for(int i = 0; i < 4;i++){
                ni = curr.ri + di[i];
                nj = curr.ci + dj[i];
                if(ni<0 || ni>=R)continue;
                if(nj<0 || nj>=C)continue;
                if(board[ni][nj]=='#')continue;
                if(dis[ni][nj] <= curr.ti+1) continue;
                if(mark[ni][nj])continue;
                mark[ni][nj] = true;
                q.push({curr.ti+1,ni,nj});
            }
        }
        cout << "NO\n";
        jump:;
        while(!q.empty())q.pop();
        
        // for(int i = 0; i < R; i++){
        //     for(int j = 0; j < C; j++){
        //         cout << dis[i][j]<< " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}