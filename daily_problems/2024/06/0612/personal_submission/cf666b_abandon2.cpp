#include<bits/stdc++.h>
using namespace std;
const int N=3010,inf=1e9;
vector<int>e[N];

void solve(){
    int n,m;cin>>n>>m;    
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(b);
    }

    vector<int>vis(n+1,0);
    vector d(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        d[i].assign(n+1,inf);
    }    
    auto bfs=[&](int s){
        queue<int>q;
        vis.assign(n+1,0);
        d[s][s]=0;
        q.push(s);
        while(q.size()){
            int u=q.front();q.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(int v:e[u]){
                if(d[s][v]>d[s][u]+1){
                    d[s][v]=d[s][u]+1;
                    q.push(v);
                }
            }
        }
    };

    for(int i=1;i<=n;i++){
        bfs(i);
    }
    vector<vector<int>>v(n+1),p(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]!=inf&&d[i][j]!=0){
                v[j].push_back(i);//到j的点的距离
                p[i].push_back(j);//能到哪个点
            }

        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(d[i][j]==inf){
    //             cout<<"-1 ";
    //         }
    //         else cout<<d[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }


    for(int i=1;i<=n;i++){
        if(v[i].size()){
            sort(v[i].begin(),v[i].end(),[&](int x,int y){
                return d[x][i]>d[y][i];
            });
        }
        if(p[i].size()){
            sort(p[i].begin(),p[i].end(),[&](int x,int y){
                return d[i][x]>d[i][y];
            });
        }
    }
    // for(auto x:p[2]){
    //     cout<<x<<"te\n";
    // }
    // cout<<"\n";
    int ans=0;
    vector<array<int,4>>res;
    res.push_back({0,0,0,0});
    for(int b=1;b<=n;b++){
        for(int c=1;c<=n;c++){
            if(c==b||d[b][c]==inf)continue;
            for(int i=0;i<3&&i<v[b].size();i++){
                int a=v[b][i];
                if(a==b||a==c||d[a][b]==inf)continue;
                for(int j=0;j<3&&j<p[c].size();j++){
                    int e=p[c][j];
                    if(e==a||e==b||e==c||d[c][e]==inf)continue;
                    //cout<<a<<" "<<b<<" "<<c<<" "<<e<<"\n";
                    int t=d[a][b]+d[b][c]+d[c][e];
                    if(ans<t){
                        ans=t;
                        res.pop_back();
                        res.push_back({a,b,c,e});
                    }
                    //ans=max(ans,d[a][b]+d[b][c]+d[c][e]);
                }
            }
        }
    }
    for(auto[a,b,c,e]:res){
        cout<<a<<" "<<b<<" "<<c<<" "<<e<<"\n";
    }


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
