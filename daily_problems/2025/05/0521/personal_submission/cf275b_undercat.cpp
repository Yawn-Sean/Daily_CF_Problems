#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>>g(n,vector<char>(m));
    vector<vector<int>>add(n,vector<int>(m));
    auto add2=add;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>g[i][j];if(g[i][j]=='B')add[i][j]++,add2[i][j]++;}
    for(int i=1;i<n;i++)for(int j=0;j<m;j++)add[i][j]+=add[i-1][j];
    for(int i=0;i<n;i++)for(int j=1;j<m;j++)add2[i][j]+=add2[i][j-1];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]=='B'){
        for(int x=0;x<n;x++)for(int y=0;y<m;y++)if(g[x][y]=='B'&&!(i==x&&j==y)){
           int cnt=0;
           if(g[x][j]=='B'&&(add[x][j]-add[i][j])==(x-i)&&(add2[x][y]-add2[x][j])==(y-j))cnt++;
           if(!cnt&&g[i][y]=='B'&&add[x][y]-add[i][y]==(x-i)&&(add2[i][y]-add2[i][j]==(y-j)))cnt++;
           if(!cnt){cout<<"NO";return;}
        }
    }
    cout<<"YES";
};
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}