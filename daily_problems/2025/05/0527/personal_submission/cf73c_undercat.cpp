#include<bits/stdc++.h>
using namespace std;
#define int long long
int v[30][30];
int dp[110][110][30];
void solve(){
    string s;cin>>s;
    int k,m;cin>>k>>m;
    for(int i=0,x;i<m;i++){
        char a,b;cin>>a>>b>>x;
        v[a-'a'][b-'a']=x;
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=k;j++){
            for(int x=0;x<26;x++){
                dp[i][j][x]=-1e18;
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=1;j<=k;j++){
            dp[0][j][i]=0;
        }
        if(i==s[0]-'a'){
            dp[0][0][i]=0;
        }
    }
    for(int i=1;i<s.size();i++){
        for(int j=0;j<=k;j++){
            for(int x=0;x<26;x++){
                for(int y=0;y<26;y++){
                    if((y+'a')==s[i]){
                        dp[i][j][y]=max(dp[i][j][y],dp[i-1][j][x]+v[x][y]);
                        if(j){
                            dp[i][j][y]=max(dp[i][j][y],dp[i][j-1][y]);
                        }
                    }else{
                        if(j){
                            dp[i][j][y]=max(dp[i][j][y],dp[i-1][j-1][x]+v[x][y]);
                            dp[i][j][y]=max(dp[i][j][y],dp[i][j-1][y]);
                        }
                    }
                }
            }
        }
    }
    int res=-1e18;
    for(int j=0;j<26;j++){
        res=max(res,dp[s.size()-1][k][j]);
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}