#include <bits/stdc++.h>

//#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
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
constexpr int mod = 1e9 + 7;




int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
//    t = 1;
    vector dp(101,vi(26*100+5));
    for(int i=1;i<=26;++i) dp[1][i] = 1;
    for(int i=2;i<=100;++i){
        for(int j=i;j<=26*i;++j){
            for(int k=max(1,j-26);k<=j-1;++k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }
    while (t--) {
        string s;
        cin>>s;
        int sum = 0;
        for(auto c:s) sum+=c-'a'+1;
        cout<<dp[s.size()][sum]-1<<endl;
    }
    return 0;
}






