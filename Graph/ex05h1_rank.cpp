#include <bits/stdc++.h>
using namespace std;
vector<int> v[5010],vt[5010];
bool mark[5010];
stack<int> st;
int Rank[5010];
void dfst(int i){
    mark[i] = true;
    for(auto x:vt[i]){
        if(!mark[x]) {dfst(x);}
    }
    st.push(i);
}
int max_rank;
int ans[5010];
vector<int> component;
void dfs(int i){
    mark[i] = true;
    component.push_back(i);
    for(auto x:v[i]){
        if(!mark[x]) dfs(x);
        else max_rank = max(max_rank, Rank[x]);
    }
}
int main(){
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++){
        scanf("%d %d",&x,&y);
        vt[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < n; i++)mark[i] = false;
    for(int i = 0; i < n; i++){
        if(!mark[i]) dfst(i);
    }
    for(int i = 0; i < n; i++)mark[i] = false;
    while(!st.empty()){
        if(!mark[st.top()]){
            max_rank = 0;
            dfs(st.top());
            for(auto x:component){
                Rank[x] = max_rank+1;
            }
            ans[max_rank+1]+=component.size();
            // for(int i = 0 ; i < n; i++)printf("%d ",Rank[i]);
            printf("\n");
            component.clear();
        }
        st.pop();
    }
    for(int i = 1; i<=n && ans[i] > 0; i++){
        printf("%d ",ans[i]);
    }
    return 0;
}