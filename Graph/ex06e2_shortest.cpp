#include <bits/stdc++.h>
using namespace std;
struct A{
    int x,y,cost;
    bool operator<(const A&o)const{
        return cost>o.cost;
    }
};
vector<A> v;
int dis[110];
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n,e,s,x,y,cost;
    scanf("%d %d %d",&n,&e,&s);
    for(int i = 0; i<e;i++){
        scanf("%d %d %d",&x,&y,&cost);
        v.push_back({x,y,cost});
    }
    for(int i = 0; i<n;i++)dis[i] = 1<<30;
    dis[s] = 0;
    bool change = false;
    for(int i = 0; i < n; i++){
        change = false;
        for(auto x:v){
            if(dis[x.y] > dis[x.x] + x.cost){
                dis[x.y] = dis[x.x] + x.cost;
                change = true;
            }
        }
    }
    if(change)printf("-1\n");
    else{
        for(int i = 0; i < n; i++){
            printf("%d ",dis[i]);
        }
    }
    return 0;
}