#include<bits/stdc++.h>
using namespace std;
// #define int long long
void solve(){
    int n,m;cin>>n>>m;
    vector<string>g(n);
    for(auto&i:g)cin>>i;
    int cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]!='.')cnt=max(cnt,g[i][j]-'a'+1);
    vector<int>son[cnt],fa(cnt);
    vector<pair<int,int>>lu(cnt,{1e9,1e9}),rd(cnt,{-1e9,-1e9});
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]!='.'){
        int v=g[i][j]-'a';
        lu[v]=min(lu[v],{i,j});
        rd[v]=max(rd[v],{i,j});
    }
    for(int i=0;i<cnt;i++){
        if(lu[i].first==1e9)continue;
        if(lu[i].first==rd[i].first){
            int x=lu[i].first;
            for(int y=lu[i].second;y<=rd[i].second;y++){
                if(g[x][y]=='.'||g[x][y]=='a'+i)continue;
                son[g[x][y]-'a'].push_back(i);
                fa[i]++;
            }
        }else if(lu[i].second==rd[i].second){
            int y=lu[i].second;
            for(int x=lu[i].first;x<=rd[i].first;x++){
                if(g[x][y]=='.'||g[x][y]=='a'+i)continue;
                son[g[x][y]-'a'].push_back(i);
                fa[i]++;
            }
        }else{
            cout<<"NO\n";return;
        }
    }
    vector<vector<char>>temp(n,vector<char>(m,'.'));
    for(int i=0;i<cnt;i++){
        if(lu[i].first==1e9)continue;
        for(int x=lu[i].first;x<=rd[i].first;x++){
            for(int y=lu[i].second;y<=rd[i].second;y++){
                temp[x][y]='a'+i;
            }
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]!=temp[i][j]){
        cout<<"NO\n";return;
    }
    cout<<"YES\n"<<cnt<<'\n';
    for(int i=cnt-2;i>=0;i--){
        if(lu[i].first==1e9)lu[i]=lu[i+1],rd[i]=rd[i+1];
    }
    for(int i=0;i<cnt;i++){
        cout<<lu[i].first+1<<' '<<lu[i].second+1<<' '<<rd[i].first+1<<' '<<rd[i].second+1<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}