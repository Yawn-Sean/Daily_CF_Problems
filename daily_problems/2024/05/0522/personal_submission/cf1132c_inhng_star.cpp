#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, q, ans = 0;
    cin >> n >> q;
    vector<int> left(q), right(q), cnt(n + 1), pre(n + 2);
    for (int i = 0; i < q; ++i) {
        cin >> left[i] >> right[i];
        // 记录每个位置最开始被画多少次
        for (int j = left[i]; j <= right[i]; ++j) {
            cnt[j]++;
        }
    }
    for (int i = 0; i < q; ++i) {
        int l = left[i], r = right[i], count = 0;
        for (int j = l; j <= r; ++j) { // 先将这个位置画画的次数减一
            cnt[j]--;
        }
        for (int j = 0; j <= n; ++j) { // 前缀和计算在此之前有多少个位置被画的次数为 1
            pre[j + 1] = pre[j];
            if (cnt[j] >= 1) {
                count++;
            }
            pre[j + 1] += cnt[j] == 1;
        }
        for (int j = 0; j < i; ++j) { // 枚举在此之前的画家（第二个不需要的画家）
            ans = max(ans, count - (pre[right[j] + 1] - pre[left[j]]));
        }
        for (int j = l; j <= r; ++j) {
            cnt[j]++;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
