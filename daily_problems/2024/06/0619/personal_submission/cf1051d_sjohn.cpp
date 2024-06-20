#include <bits/stdc++.h>

using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()

constexpr int mod = 998244353;


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin >> n >> k;
    vector dp(k + 1, vl(4));
    dp[1][0] = 1;
    if(k>=2) {
        dp[2][1] = 1;
        dp[2][2] = 1;
    }
    dp[1][3] = 1;
    for(int i=1;i<n;++i){
        for(int j=k; j >= 0; --j){
            i64 t0 = dp[j][0], t1 = dp[j][1], t2 = dp[j][2], t3 = dp[j][3];
            dp[j][0] = t0 + t1 + t2;
            if(j >= 1) dp[j][0] += dp[j-1][3];
            dp[j][0] %= mod;
            if(j >= 1) dp[j][1] = t1 + dp[j - 1][0] + dp[j - 1][3];
            if(j >= 2) dp[j][1] += dp[j - 2][2];
            dp[j][1] %= mod;
            if(j >= 1) dp[j][2] =  t2 + dp[j - 1][0] + dp[j - 1][3];
            if(j >= 2) dp[j][2] += dp[j - 2][1];
            dp[j][2] %= mod;
            dp[j][3] = t1 + t2 + t3;
            if(j >= 1) dp[j][3] += dp[j-1][0];
            dp[j][3] %= mod;
        }
    }
    cout << (dp[k][0] + dp[k][1] + dp[k][2] +dp[k][3]) % mod <<endl;
}






