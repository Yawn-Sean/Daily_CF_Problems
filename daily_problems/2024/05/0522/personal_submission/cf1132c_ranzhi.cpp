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
    int n, q; cin >> n >> q;
    vector<PII> arr;
    vector<int> cnt(n + 10);
    int ans = INT_MAX;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        arr.emplace_back(l, r);
        for (int j = l; j <= r; j++) cnt[j] += 1;
    }
    for (int i = 0; i < q; i++) {
        int x = 0;
        int l = arr[i].first, r = arr[i].second;
        for (int j = l; j <= r; j++) cnt[j] -= 1;
        vector<int> pre(n + 1);
        for (int j = 1; j <= n; j++) {
            pre[j] = pre[j - 1];
            if (cnt[j] == 1) pre[j] += 1;
            else if (cnt[j] == 0) x += 1;
        }
        for (int j = 0; j < q; j++) {
            if (i == j) continue;
            ans = min(ans, pre[arr[j].second] - pre[arr[j].first - 1] + x);
        }
        for (int j = l; j <= r; j++) cnt[j] += 1;
    }
    cout << n - ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
