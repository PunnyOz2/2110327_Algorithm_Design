#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
bool mark[1010];
queue<pair<int,int> > q;
int main(){
    int n,m,k,x,y,cur,cou,icou,Max=-1;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < m; i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    q.push({0,k});
    icou = 0;
    mark[0]=true;
    while(!q.empty()){
        cur = q.front().first;
        cou = q.front().second;
        q.pop();
        if(cou == 0)icou++;
        if(cou < 0) break;
        else{
            for(auto x:v[cur]){
                if(!mark[x]){
                    mark[x] = true;
                    q.push({x,cou-1});
                }
            }
        }
    }
    while(!q.empty())q.pop();
    printf("%d\n",icou);
    return 0;
}