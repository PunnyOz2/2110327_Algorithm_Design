#include <bits/stdc++.h>
using namespace std;
int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
vector<vector<int> > a;
vector<vector<int> > dis;
vector<int> temp;
struct A{
    int i,j,cost;
    bool operator<(const A&o)const{
        return cost > o.cost;
    }
};
priority_queue<A> q;
int main(){
    int n,m,num,ni,nj;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++){
        temp.clear();
        for(int j = 0;j<m;j++){
            scanf("%d",&num);
            temp.push_back(num);
        }
        a.push_back(temp);
        dis.push_back(vector<int>(m,1<<30));
    }
    dis[0][0] = 0;
    q.push({0,0,0});
    while(!q.empty()){
        int i = q.top().i;
        int j = q.top().j;
        int cost = q.top().cost;
        q.pop();
        for(int k = 0; k<4;k++){
            ni = i + di[k];
            nj = j + dj[k];
            if(ni<0 || ni>=n)continue;
            if(nj<0 || nj>=m)continue;
            if(dis[ni][nj] > a[ni][nj] + cost){
                dis[ni][nj] = a[ni][nj] + cost;
                q.push({ni,nj,dis[ni][nj]});
            }
        }
    }
    for(auto x:dis){
        for(auto y:x){
            printf("%d ",y);
        }
        printf("\n");
    }
    return 0;
}
/*
in:
4 4
1 1 1 1
9 8 7 1
1 1 1 1
1 2 4 9
out:
0 1 2 3
9 9 9 4
8 7 6 5
9 9 10 14
*/