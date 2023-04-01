#include <bits/stdc++.h>
using namespace std;
int p[10010];
int fin(int i){
    if(p[i] == i)return i;
    return p[i] = fin(p[i]);
}
int main(){
    int n,k,x,y;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)p[i] = i;
    while(k--){
        cin >> x >> y;
        if(fin(x)!=fin(y)){
            p[fin(x)] = fin(y);
        }
    }
    set<int> s;
    for(int i = 1; i <= n; i++)s.insert(fin(i));
    cout << s.size();

    return 0;
}