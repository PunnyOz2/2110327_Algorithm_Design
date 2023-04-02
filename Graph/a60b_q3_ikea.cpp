#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int deg[1010],deg_temp[1010];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        deg[y]++;
    }
    int ch = 0,num;
    for(int i = 0; i < 5; i++){
        ch = 0;
        for(int j = 1; j <= n; j ++)deg_temp[j] = deg[j];
        for(int j = 0; j < n; j++){
            scanf("%d",&num);
            if(deg_temp[num]!=0)ch = 1;
            else {
                for(auto x:v[num]){
                    deg_temp[x]--;
                }
            }
        }
        if(ch) printf("FAIL\n");
        else printf("SUCCESS\n");
    }
    return 0;
}