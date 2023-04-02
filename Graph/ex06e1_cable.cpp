#include <bits/stdc++.h>
using namespace std;
struct A{
    int x,y,cost;
    bool operator<(const A&o)const {
        return cost > o.cost;
    }
};
priority_queue<A> q;
int p[1010];
int fin(int i) {
    if(i==p[i]) return i;
    return p[i] = fin(p[i]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,num;
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            scanf("%d",&num);
            q.push({i,j,num});
        }
    }
    int Sum = 0;
    for(int i = 0; i < n; i++)p[i] = i;
    while(!q.empty()){
        int x = q.top().x;
        int y = q.top().y;
        int cost = q.top().cost;
        q.pop();
        if(fin(x)!=fin(y)){
            p[fin(x)] = fin(y);
            Sum += cost;
        }
    }
    printf("%d\n",Sum);
    return 0;
}