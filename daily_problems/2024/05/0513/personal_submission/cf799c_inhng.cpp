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

int f(vector<PII> a, int money) {
    int ans = 0, cnt = 0;
    vector<int> pre(a.size() + 1);
    ranges::sort(a);
    for (int i = 0; i < a.size(); ++i) {
        pre[i + 1] = max(pre[i], a[i].ss);
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        while (cnt < i and a[i].ff + a[cnt].ff <= money) {
            ++cnt;
        }
        cnt = min(cnt, i);
        if (cnt) {
            ans = max(ans, pre[cnt] + a[i].ss);
        }
    }
    return ans;
}

void solve() {
    int n, c, d, mx_d = 0, mx_c = 0;
    cin >> n >> c >> d;
    vector<PII> C, D;
    while (n--) {
        int b, p;
        char ch;
        cin >> b >> p >> ch;
        if (ch == 'C' and p <= c) {
            C.emplace_back(p, b);
            mx_c = max(mx_c, b);
        } else if (ch == 'D' and p <= d) {
            D.emplace_back(p, b);
            mx_d = max(mx_d, b);
        }
    }
    cout << max({(mx_c and mx_d ? mx_c + mx_d : 0), f(C, c), f(D, d)});
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
