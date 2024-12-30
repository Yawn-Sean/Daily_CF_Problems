#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
ll a[N];
ll dp[N];
ll pre[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = pre[1] = 2;
    for(int i = 2; i <= n; i++){
        dp[i] = pre[i - 1] - pre[a[i] - 1] + 2;
        if(dp[i] < 0) dp[i] += MOD;
        pre[i] = (pre[i - 1] + dp[i]) % MOD; 
    }
    cout << pre[n];
    return 0;
}