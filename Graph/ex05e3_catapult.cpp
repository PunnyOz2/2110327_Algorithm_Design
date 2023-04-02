#include <bits/stdc++.h>
using namespace std;
int mark[1010];
stack<int> st;
vector<int> v[1010],vt[1010];
void dfs(int i){
    mark[i] = 1;
    for(auto x:vt[i]){
        if(!mark[x]) dfs(x);
    }
    st.push(i);
}
int dfs2(int i){
    mark[i] = 1;
    int cou = 1;
    for(auto x:v[i]){
        if(!mark[x]) cou += dfs2(x);
    }
    return cou;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,num;
    vector<int> cou;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        while(m--){
            cin >> num;
            v[i].push_back(num);
            vt[num].push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(!mark[i]) dfs(i);
    }
    for(int i = 0; i < n; i++)mark[i] = 0;
    while(!st.empty()){
        if(!mark[st.top()]){
            cou.push_back(dfs2(st.top()));
        }
        st.pop();
    }
    sort(cou.begin(),cou.end());
    for(auto x:cou)cout << x << " ";
    return 0;
}