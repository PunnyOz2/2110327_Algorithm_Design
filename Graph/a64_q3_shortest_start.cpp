#include <bits/stdc++.h>
using namespace std;
int dis[5010];
struct A{
    int x,y,cost;
};
vector<A> v;
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,finish,num,curr,cost,x,y;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d",&finish);
    for(int i = 0; i < n; i++)dis[i] = 1<<30;
    for(int i = 0; i < k; i++){
        scanf("%d",&num);
        dis[num] = 0;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&x,&y,&num);
        v.push_back({x,y,num});
    }
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m; j++){
            if(dis[v[j].y] > dis[v[j].x]+v[j].cost){
                dis[v[j].y] = dis[v[j].x]+v[j].cost;
            }
        }
    }
    printf("%d\n",dis[finish]);
    return 0;
}