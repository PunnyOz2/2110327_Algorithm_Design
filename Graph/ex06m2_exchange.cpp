#include <bits/stdc++.h>
using namespace std;
int n;
double v[510][510];
double dis[510];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Q;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                scanf("%lf",&v[i][j]);
            }
        }
        bool change = false;
        for(int i = 0; i < n; i++)dis[i]=0.0;
        dis[0] = 1.0;
        for(int i = 0; i < n; i++){
            change = false;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(dis[j]*v[j][k]-dis[k]>0){
                        dis[k] = dis[j]*v[j][k];
                        change = true;
                    }
                }
            }
        }
        if(change)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1 
2
1 0.7
1.2 1
*/