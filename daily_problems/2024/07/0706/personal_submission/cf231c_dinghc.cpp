#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    ranges::sort(a);
    vector<long long> b(n + 1, 0LL);
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    pair<int, int> ans{1, -a[0]};
    for (int i = 1; i < n; i++) {
        int lo = 0, hi = i;
        while (lo <= hi) {
            int m = (lo + hi) >> 1;
            long long sum = 1LL * (i - m) * a[i] - (b[i] - b[m]);
            if (sum > k) {
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }
        ans = max(ans, pair<int, int> {i - lo + 1, -a[i]});
    }
    cout << ans.first << " " << -ans.second;
    return 0;
}

