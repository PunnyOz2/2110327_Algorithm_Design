#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
vector<int> ans;
int deg[1010];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,num;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> m;
        while(m--){
            cin >> num;
            v[num].push_back(i);
            deg[i]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto x:v[curr]){
            deg[x]--;
            if(deg[x] == 0) q.push(x);
        }
    }
    for(auto x:ans)cout << x << " ";
    return 0;
}