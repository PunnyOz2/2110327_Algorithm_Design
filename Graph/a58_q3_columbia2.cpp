#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > a,temp2;
vector<vector<vector<int> > > dis;
vector<int> temp;
int num;
struct A{
    int i,j,cost,power;
    bool operator<(const A&o)const{
        return cost>o.cost;
    }
};
priority_queue<A> q;
int di[12] = {1,-1,0,0,1,1,-1,-1,2,-2,0,0}, dj[12] = {0,0,1,-1,1,-1,1,-1,0,0,2,-2};
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,ni,nj;
    vector<int> tempFordis = vector<int>(4,1<<30);
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        temp.clear();
        temp2.clear();
        for(int j = 0; j < m; j++){
            scanf("%d",&num);
            temp.push_back(num);
            temp2.push_back(tempFordis);
        }
        a.push_back(temp);
        dis.push_back(temp2);
    }
    q.push({0,0,0,0});
    dis[0][0][0] = 0;
    while(!q.empty()){
        int i = q.top().i;
        int j = q.top().j;
        int cost = q.top().cost;
        int power = q.top().power;
        q.pop();
        for(int k = 0; k < 4; k++){
            ni = i + di[k];
            nj = j + dj[k];
            if(ni<0 || ni>=n)continue;
            if(nj<0 || nj>=m)continue;
            if(dis[ni][nj][power] > cost + a[ni][nj]){
                dis[ni][nj][power] = cost + a[ni][nj];
                q.push({ni,nj,dis[ni][nj][power],power});
            }
        }
        if(power<2){
            for(int k = 0; k < 12; k++){
                ni = i + di[k];
                nj = j + dj[k];
                if(ni<0 || ni>=n)continue;
                if(nj<0 || nj>=m)continue;
                if(dis[ni][nj][power+1] > cost){
                    dis[ni][nj][power+1] = cost;
                    q.push({ni,nj,dis[ni][nj][power+1],power+1});
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ",min({dis[i][j][0],dis[i][j][1],dis[i][j][2]}));
        }
        printf("\n");
    }
    return 0;
}