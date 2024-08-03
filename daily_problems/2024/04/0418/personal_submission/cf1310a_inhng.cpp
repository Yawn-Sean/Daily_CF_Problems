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
    int n, ans = 0, cur = 0, sum = 0;
    cin >> n;
    vector<PII> a(n);
    priority_queue<int> q;
    for (PII &ai : a) {
        cin >> ai.ff;
    }
    for (PII &ai : a) {
        cin >> ai.ss;
    }
    ranges::sort(a);
    for (PII ai : a) {
        while (cur < ai.ff and q.size()) {
            sum -= q.top(); // 最大的 t_i 不加
            ans += sum;
            q.pop();
            cur++;
        }
        cur = ai.ff;
        sum += ai.ss;
        q.emplace(ai.ss);
    }
    while (q.size()) {
        sum -= q.top();
        ans += sum;
        q.pop();
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
