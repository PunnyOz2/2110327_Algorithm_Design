#include <bits/stdc++.h>
using namespace std;
int p[10010],deg[10010];
int fin(int i){
    if(p[i] == i)return i;
    return p[i] = fin(p[i]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,x,y;
    cin >> n >> m;
    for(int i = 0; i < n; i++)p[i] = i;
    while(m--){
        cin >> x >> y;
        deg[x]++,deg[y]++;
        if(fin(x)!=fin(y)){
            p[fin(x)] = fin(y);
        }
    }
    set<int> s;
    set<int> s2;
    set<int> s3;
    for(int i = 0; i < n; i++){
        s.insert(fin(i));
        if(deg[i]>=3) s3.insert(fin(i));
        if(deg[i]<=1) s2.insert(fin(i));
    }
    int cou=0;
    for(auto x:s){
        if(s2.find(x)!=s2.end() && s3.find(x)==s3.end()) cou++;
    }
    cout << cou;
    return 0;
}