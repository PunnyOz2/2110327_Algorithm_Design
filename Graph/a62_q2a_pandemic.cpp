#include <bits/stdc++.h>
using namespace std;
int a[510][510];
int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
struct A{
    int first,second,third;
};
queue<A > q;
A curr;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,t,ii,jj,cou=0;
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) q.push({i,j,0}),cou++;
        }
    }
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr.third<t){
            for(int i = 0; i < 4; i++){
                ii = curr.first + di[i];
                jj = curr.second + dj[i];
                if(ii < 1 || ii > n) continue;
                if(jj < 1 || jj > m) continue;
                if(a[ii][jj] > 0)continue;
                a[ii][jj] = 1;
                q.push({ii,jj,curr.third+1});
                cou++;
            }
        }
    }
    cout << cou;
    return 0;
}