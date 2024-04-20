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
    int a, b, x = 0;
    cin >> a >> b;
    while (x * (x + 1) / 2 <= a + b) {
        ++x;
    }
    --x;
    vector<int> ans1, ans2, memo(x + 1);
    for (int i = x; i; --i) {
        if (not memo[i] and i <= a) {
            ans1.emplace_back(i);
            memo[i] = 1;
            a -= i;
        }
    }
    for (int i = x; i; --i) {
        if (not memo[i] and i <= b) {
            ans2.emplace_back(i);
            memo[i] = 1;
            b -= i;
        }
    }
    ranges::sort(ans1);
    ranges::sort(ans2);
    cout << ans1.size() << endl;
    for (int ai : ans1) {
        cout << ai << " \n"[ai == ans1.back()];
    }
    cout << ans2.size() << endl;
    for (int ai : ans2) {
        cout << ai << " \n"[ai == ans2.back()];
    }
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
