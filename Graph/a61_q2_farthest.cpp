#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
struct A{
    int x,cost;
    bool operator<(const A&o)const{
        return cost>o.cost;
    }
};
priority_queue<A> q;
int dis[1010];
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n,curr,cost;
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        dis[i] = 1<<30;
        for(int j = 0;j <n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    q.push({0,0});
    dis[0] = 0;
    while(!q.empty()){
        curr = q.top().x;
        cost = q.top().cost;
        q.pop();
        for(int i = 0; i < n; i++){
            if(curr == i)continue;
            if(a[curr][i]==-1)continue;
            if(dis[i] > a[curr][i] + cost){
                dis[i] = a[curr][i] + cost;
                q.push({i,dis[i]});
            }
        }
    }
    int Maxx = 0;
    for(int i = 1; i<n;i++){
        Maxx = max(Maxx, dis[i]);
    }
    if(Maxx == 1<<30)printf("-1\n");
    else printf("%d\n",Maxx);
    return 0;
}