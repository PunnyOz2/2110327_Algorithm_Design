#include <bits/stdc++.h>
using namespace std;
vector<int> v[100100];
int deg[100100];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,x,y,cou = 0;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    for(int i = 0; i < n; i++){
        if(deg[i] == 1 || deg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        cou += 1;
        q.pop();
        for(auto x:v[node]){
            deg[x]--;
            deg[node]--;
            if(deg[x] == 1||deg[x] == 0) q.push(x); 
        }
    }
    cout << n - cou;
    return 0;
}