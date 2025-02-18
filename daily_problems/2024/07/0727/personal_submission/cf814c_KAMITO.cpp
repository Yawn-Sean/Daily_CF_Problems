// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;
constexpr int N=1510;
int dp[N][N][26];
// 前i个元素不超过j次操作且以字符k结尾的最长长度
int ans[N][26];
// 不超过j次操作且以字符k结尾的最长长度

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;
    s=' '+s;
  
    for(int i=1;i<=n;i++){
        for(int k=0;k<26;k++){
            if(s[i]-'a'==k){
                dp[i][0][k]=dp[i-1][0][k]+1;
                ans[0][k]=max(ans[0][k],dp[i][0][k]);
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<26;k++){
                if(s[i]-'a'==k)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+1);
                else
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+1);
                ans[j][k]=max(ans[j][k],dp[i][j][k]);
            }
        }
    }

    int q;
    cin>>q;

    while(q--){
        int m;
        char c;
        cin>>m>>c;
        cout<<ans[m][c-'a']<<"\n";
    }
    return;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
    
    
    return 0;
}

