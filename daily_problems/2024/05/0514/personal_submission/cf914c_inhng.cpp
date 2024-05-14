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
    int k, cur = 0, ans = 0;
    string n;
    cin >> n >> k;
    if (not k) {
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << n.size() - 1 << endl;
        return;
    }
    vector<int> cnt(1001), ones(1001);
    for (int i = 2; i <= 1000; ++i) {
        cnt[i] = cnt[__builtin_popcount(i)] + 1;
    }

    for (char c : n) {
        for (int i = 1000; i; --i) {
            ones[i] = (ones[i] + ones[i - 1]) % mod;
        }
        if (c == '1') {
            ones[cur] = (ones[cur] + 1) % mod;
            ++cur;
        }
    }
    for (int i = 1; i <= 1000; ++i) {
        if (cnt[i] == k - 1) {
            ans = (ans + ones[i]) % mod;
        }
    }
    cout << (ans + (cnt[cur] == k - 1)) % mod << endl;
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
