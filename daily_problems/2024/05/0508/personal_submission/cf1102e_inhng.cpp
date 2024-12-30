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
const int mod = 998244353;

void solve() {
    int n, ans = 1;
    cin >> n;
    map<int, int> left, right;
    vector<int> diff(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (not left.count(x)) {
            left[x] = i;
        }
        right[x] = i;
    }
    for (map<int, int>::iterator it = left.begin(); it != left.end(); ++it) {
        diff[left[it->ff]]++;
        diff[right[it->ff]]--;
    }
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
        if (not diff[i - 1]) {
            ans = ans * 2 % mod;
        }
    }
    cout << ans;
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
