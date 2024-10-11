#include <bits/stdc++.h>

#define DEBUG
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
//constexpr int mod = 1e9 + 7;
// 预处理 O(26*n*n+q)
void solve() {
    int n, q;cin>>n;
    string color;
    cin>>color;
    cin>>q;
    vector dp(26,vi(n + 1));
    for(int i=0;i<26;++i){
        char c = i + 'a';
        for(int j=0;j<n;++j){
            int cost = 0;
            for(int k=j;k<n;++k){
                if(color[k]!=c) cost++;
                dp[i][cost] = max(dp[i][cost],k-j+1);
            }
        }
    }
    for(int i=0;i<26;++i)
        for(int j=1;j<=n;++j)
            dp[i][j] = max(dp[i][j],dp[i][j-1]);

    while(q--){
        int x;char c;
        cin>>x>>c;
        cout << dp[c-'a'][x] << endl;
    }
}


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

}






