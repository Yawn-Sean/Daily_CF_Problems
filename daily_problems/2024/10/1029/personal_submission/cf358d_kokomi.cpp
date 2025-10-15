#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
typedef long long ll;
ll a[N], b[N], c[N];
//每一个点的答案受前后点的状态影响，导致无法实现
//不妨考虑三个点的最后一个点
//dp[i][0] 先选择i dp[i][1]表示先先选择i-1
ll dp[N][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    memset(dp, -0x3f, sizeof dp);
    dp[1][0] = 0;
    for(int i = 2; i <= n + 1; i++){
        dp[i][0] = max(dp[i - 1][0] + b[i - 1], dp[i - 1][1] + c[i - 1]);
        dp[i][1] = max(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + b[i - 1]);
    }
    cout << dp[n + 1][1] << endl;
    return 0;
    
}