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
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int c = 'z'; c > 'a'; --c) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                int j = i;
                while (j < s.size() and s[j] == c) {
                    ++j;
                }
                if (i > 0 and s[i - 1] == c - 1 or j < s.size() and s[j] == c - 1) {
                    s.erase(i, j - i);
                    ans += j - i;
                    --i;
                }
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
