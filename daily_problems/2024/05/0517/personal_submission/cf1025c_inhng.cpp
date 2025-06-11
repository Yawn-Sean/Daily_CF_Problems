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
    string s;
    cin >> s;
    int ans = 1, cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    if (s[0] == s.back()) {
        cout << ans << endl;
        return;
    }
    cnt = 1;
    int i = 1, j = s.size() - 2;
    while (i < s.size() and s[i] != s[i - 1]) {
        ++i;
    }
    while (j >= 0 and s[j] != s[j + 1]) {
        --j;
    }
    if (i > j) {
        cout << s.size() << endl;
    } else if (i == j) {
        cout << s.size() - 1 << endl;
    } else {
        cout << max(ans, i + (int)(s.size() - j - 1)) << endl;
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
