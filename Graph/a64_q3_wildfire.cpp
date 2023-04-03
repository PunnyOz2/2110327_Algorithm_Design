#include <bits/stdc++.h>
using namespace std;
int b[5010];
int w[5010];
queue<int> q;
vector<int> v[5010];
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,num,x,y,currday,currnode;
    int Sum = 0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0 ;i<n;i++){
        scanf("%d",&b[i]);
        Sum += b[i];
    }
    for(int i = 0; i < k; i++){
        scanf("%d",&w[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
    }
    for(int day = 0; day < k; day++){
        q.push(w[day]);
        if(b[w[day]]>0){
            Sum -= b[w[day]];
            b[w[day]] = 0;
        }
        while(!q.empty()){
            currnode = q.front();
            q.pop();
            for(auto x: v[currnode]){
                if(b[x]>0){
                    Sum -= b[x];
                    b[x] = 0;
                    q.push(x);
                }
            }
        }
        printf("%d ",Sum);
    }
    return 0;
}