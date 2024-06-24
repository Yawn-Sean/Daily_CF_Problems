#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void solve() { 
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j <= k; j++) mp[a * j] = j;
    }
    int q; cin >>  q;
    while (q--) {
        int ans = INT_MAX;
        int target; cin >> target;
        for (auto &[x, val] : mp) {
            if (mp.count(target - x)) ans = min(ans, val + mp[target - x]);
        }
        if (ans > k) ans = -1;
        cout << ans << endl;
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
