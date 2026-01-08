#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9+7;
const int N = 1e6 + 10;
//x ^ y > max(x, y)等价x的最高位在y是0, y的最高位在x是0
void solve() {
    
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> vis(1 << 22, 0);//msb可以添加的x
    for (auto &x: nums) {
        int bit = 32 - __builtin_clz(x);
        vis[((1 << bit) - 1) ^ x] |= 1 << (bit - 1);
    }
    //推到子集
    for (int j = (1 << 22)-1; j >= 0; j --) {
        for (int i = 0; i < 22; i ++) {
            if (j >> i & 1) {
                vis[j ^ (1 << i)] |= vis[j];
            }
        }
    }
    //dp[msb]
    vector<int> dp(1 << 22, 0);
    for (int i = 0; i < 1 << 22; i ++) {
        for (int j = 0; j < 22; j ++) {
            if (vis[i] >> j & 1) {
                int ni = i | (1 << j);
                dp[ni] = max(dp[ni], dp[i] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
