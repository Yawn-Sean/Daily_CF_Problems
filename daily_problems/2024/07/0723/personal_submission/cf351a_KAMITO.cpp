#include <bits/stdc++.h>

using namespace std;
using i64=long long;

// constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr double inf=numeric_limits<double>::max()/2;

void solve(){
    int n;
    cin>>n;
    vector<double> a(2*n+1);

    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    vector<vector<double>> dp(2*n+1,vector<double>(n+1,inf));

    dp[0][0]=0;
    for(int i=1;i<=2*n;i++){
        dp[i][0]=dp[i-1][0]+floor(a[i])-a[i];
        for(int j=1;j<=min(i,n);j++){
            if(abs(dp[i-1][j-1]+ceil(a[i])-a[i])<abs(dp[i][j]))
                dp[i][j]=dp[i-1][j-1]+ceil(a[i])-a[i];
            if(abs(dp[i-1][j]+floor(a[i])-a[i])<abs(dp[i][j]))
                dp[i][j]=dp[i-1][j]+floor(a[i])-a[i];
        }
    }
    
    cout<<fixed<<setprecision(3)<<abs(dp[2*n][n])<<"\n";

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

