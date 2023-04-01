#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<vector<int> > dis;
queue<pair<int,int> > q;
int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,ii,jj,ni,nj;
    string s;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
        dis.push_back(vector<int>(m, 20000));
    }
    dis.push_back(vector<int>(m, 20000));
    q.push({0,0});
    dis[0][0] = 0;
    while(!q.empty()){
        ii = q.front().first;
        jj = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            ni = ii + di[i];
            nj = jj + dj[i];
            if(ni<0 || ni >= n)continue;
            if(nj<0 || nj >= m)continue;
            if(v[ni][nj] == '#') continue;
            if(dis[ni][nj] <= dis[ii][jj] + 1) continue;
            dis[ni][nj] = dis[ii][jj] + 1;
            if(ni == n-1 && nj == m-1){cout<<dis[n-1][m-1];return 0;}
            q.push({ni, nj});
        }
    }
    while(!q.empty()) q.pop();
    if(dis[n-1][m-1] == 20000) cout<<-1;
    else cout<<dis[n-1][m-1];
    return 0;
}