#include <bits/stdc++.h>
using namespace std;
struct A{
    int x,y,c;
    bool operator<(const A&o)const{
        return c>o.c;
    }
};
priority_queue<A> q;
int p[5010];
vector<int> Sum;
int fin(int i){
    if(p[i] == i)return i;
    return p[i] = fin(p[i]);
}
int main(){
    int n,m,Q,x,y,c;
    scanf("%d %d %d",&n,&m,&Q);
    for(int i = 0; i<m;i++){
        scanf("%d %d %d",&x,&y,&c);
        q.push({x,y,c});
    }
    for(int i = 0; i<n; i++)p[i] = i;
    while(!q.empty()){
        x = q.top().x;
        y = q.top().y;
        c = q.top().c;
        q.pop();
        if(fin(x)!=fin(y)){
            p[fin(x)] = fin(y);
            Sum.push_back(c);
        }
    }
    n = Sum.size();
    while(Q--){
        scanf("%d",&x);
        printf("%d\n",Sum[max(n-x,0)]);
    }
    return 0;
}