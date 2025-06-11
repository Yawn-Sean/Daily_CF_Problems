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
    int ans = 0, n = s.size();
    for (int i = 0; i < n; ++i) { // 字符串起点
        int cur = 0, right = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '(') {
                ++cur;
            } else if (s[j] == ')') {
                --cur;
            } else { // 先暂时赋值为 ')'
                --cur;
                ++right; // 右括号个数
            }
            if (not cur) { // 当前刚好可以凑成功 "()"
                ans += 1;
            } else if (cur < 0) { // 说明在此之前的字符串凑不成 '()'
                if (not right) {
                    break;
                }
                --right;
                cur += 2;
            }
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
