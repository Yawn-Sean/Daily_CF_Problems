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
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    vector<int> a(n + 1), ans;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i] >> __builtin_ctzll(a[i])].emplace_back(i);
    }
    // for (auto [_, it] : mp) {
    for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); ++it) {
        map<int, int> idx;
        // for (int i : it) {
        for (int i : it->ss) {
            if (idx[a[i]]) {
                while (idx[a[i]]) {
                    a[idx[a[i]]] = 0;
                    idx.erase(a[i]);
                    a[i] <<= 1;
                }
                idx[a[i]] = i;
            } else {
                idx[a[i]] = i;
            }
        }
    }
    for (int ai : a) {
        if (ai) {
            ans.emplace_back(ai);
        }
    }
    cout << ans.size() << endl;
    for (int ai : ans) {
        cout << ai << " \n"[ai == ans.back()];
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
