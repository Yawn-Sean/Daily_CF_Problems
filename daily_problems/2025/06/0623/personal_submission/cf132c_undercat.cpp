#include<bits/stdc++.h>
using namespace std;
int dp[101][300][51][2];
void solve(){
    string s;cin>>s;
    int n;cin>>n;
    dp[0][150][0][0]=1;
    for(int i=1;i<=(int)s.size();i++){
        char c=s[i-1];
        for(int j=0;j<2;j++){
            for(int k=0;k<=n;k++){
                for(int x=0;x<300;x++){
                    if(dp[i-1][x][k][j]){
                        int f=j^(c=='T');
                        int add=(c=='F')*(f*2-1);
                        dp[i][x+add][k][f]=1;
                        f=j^(c!='T');
                        add=(c!='F')*(f*2-1);
                        if(k<n)dp[i][x+add][k+1][f]=1;
                    }
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<300;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<=n;k++)
                if(dp[(int)s.size()][i][k][j]&&(n-k)%2==0)
                    res=max(res,abs(i-150));
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}