#include <bits/stdc++.h>
using namespace std;
int virus[10010];
int Time[10010];
vector<int> v[10010];
int dis[10010];
bool inT[10010];
struct A{
    int x,cost;
    bool operator<(const A&o)const{
        return cost > o.cost;
    }
};
priority_queue<A> q;
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,x,y,cost,curr;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < k; i++){
        scanf("%d",&virus[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&Time[i]);
        dis[i] = 1<<30;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < k; i++){
        q.push({virus[i],Time[virus[i]]});
        dis[virus[i]] = Time[virus[i]];
    }
    while(!q.empty()){
        curr = q.top().x;
        cost = q.top().cost;
        // inT[curr] = true;
        if(cost > dis[curr])continue;
        q.pop();
        for(auto x:v[curr]){
            if(dis[x] > Time[x] + cost){
                dis[x] = Time[x] + cost;
                q.push({x,dis[x]});
            }
        }
    }
    int Max = 0;
    for(int i = 0; i < n; i++)Max = max(Max, dis[i]);
    printf("%d\n",Max);
    return 0;
}