#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
vector<bool> mark(1010);
int n,m,t,e,x,y;
bool hasCycle(){
    int cur,head;
    bool cycle = false;
    stack<pair<int,int>> st;
    for(int ii = 0; ii < n; ii++){
        for(int i = 0; i < n; i++)mark[i] = false;
        st.push({ii,-1});
        while(!st.empty()){
            cur = st.top().first;
            head = st.top().second;
            mark[cur] = true;
            st.pop();
            for(auto x:v[cur]){
                if(x==head)continue;
                if(mark[x] == true) cycle = true;
                st.push({x,cur});
            }
            if(cycle)break;
        }
        while(!st.empty())st.pop();
        if(cycle)return true;
    }
    return cycle;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&e);
        for(int i = 0; i < e; i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(hasCycle())printf("YES\n");
        else printf("NO\n");
        for(int i = 0; i < n; i++)v[i].clear();
    }
    return 0;
}