#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
using i64 = long long;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> nums(q);
    for (int i = 0; i < q; ++i) cin >> nums[i];
    
    const i64 mod = 1000000007;
    const i64 rev2 = (mod + 1) / 2; 
    
    vector<i64> ans(n + 1, 0);
    i64 cur = 0;
    
    for (int i = q - 1; i >= 0; --i) {
        int v = nums[i];
        ans[v] = (ans[v] + cur * rev2) % mod;
        cur = (cur + v) * rev2 % mod;
    }
    
    ans[1] = (ans[1] + cur) % mod;
    
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
}
