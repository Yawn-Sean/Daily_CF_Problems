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

int f(string s) { // 前缀和求噪声
    int ans = 0, cnt = 0;
    for (char c : s) {
        cnt += c == 's';
        ans += (c == 'h' ? cnt : 0);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (string &si : s) {
        cin >> si;
    }
    // 噪声大的排法放前面
    ranges::sort(s, [](string a, string b) {
        return f(a + b) > f(b + a);
    });
    string ans;
    for (string si : s) {
        ans += si; // 最后计算总噪声
    }
    cout << f(ans) << endl;
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
