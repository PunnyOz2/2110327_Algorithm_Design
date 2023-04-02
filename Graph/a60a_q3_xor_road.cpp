#include <bits/stdc++.h>
using namespace std;
long long a[2010];
struct A{
    int i,j;
    long long num;
    bool operator<(const A&o)const{
        return num<o.num;
    }
};
priority_queue<A> q;
int p[2010];
int fin(int i){
    if(p[i] == i) return i;
    return p[i] = fin(p[i]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lld",&a[i]);
    }
    for(int i = 0; i < n; i++){
        p[i] = i;
        for(int j = i+1; j<n; j++){
            q.push({i,j,a[i]^a[j]});
        }
    }
    long long Sum = 0;
    while(!q.empty()){
        if(fin(q.top().i)!=fin(q.top().j)){
            p[fin(q.top().i)] = fin(q.top().j);
            Sum += q.top().num;
        }
        q.pop();
    }
    printf("%lld\n",Sum);
    return 0;
}