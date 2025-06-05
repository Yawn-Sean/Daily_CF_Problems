#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n,vector<int>(m));
    for(auto&i:g)for(auto&j:i)cin>>j;
    vector<pair<string,int>>res;
    if(m>n){
        for(int i=0;i<n;i++){
            int mi=1e9;
            for(int j=0;j<m;j++){
                mi=min(g[i][j],mi);
            }
            for(int j=0;j<mi;j++){
                res.push_back({"row",i});
            }
            for(int j=0;j<m;j++){
                g[i][j]-=mi;
            }
            for(int j=0;j<m;j++){
                if(g[i][j]){
                    int t=g[i][j];
                    for(int k=0;k<n;k++){
                        if(g[k][j]<t){
                            cout<<-1;return;
                        }
                        g[k][j]-=t;
                    }
                    for(int k=0;k<t;k++){
                        res.push_back({"col",j});
                    }
                }
            }
        }
    }else{
        for(int i=0;i<m;i++){
            int mi=1e9;
            for(int j=0;j<n;j++){
                mi=min(g[j][i],mi);
            }
            for(int j=0;j<mi;j++){
                res.push_back({"col",i});
            }
            for(int j=0;j<n;j++){
                g[j][i]-=mi;
            }
            for(int j=0;j<n;j++){
                if(g[j][i]){
                    int t=g[j][i];
                    for(int k=0;k<m;k++){
                        if(g[j][k]<t){
                            cout<<-1;return;
                        }
                        g[j][k]-=t;
                    }
                    for(int k=0;k<t;k++){
                        res.push_back({"row",j});
                    }
                }
            }
        }
    }
    cout<<res.size()<<'\n';
    for(auto&[a,b]:res)cout<<a<<' '<<b+1<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}