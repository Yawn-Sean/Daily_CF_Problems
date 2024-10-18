#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void ops(int i, int j, string &s, string &t, vector<PII> &ans) {
    swap(s[i], t[j]);
    ans.emplace_back(i, j);
    return;
}

void solve() { 
    int n; cin >> n;
    vector<PII> ans;
    string s, t; cin >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        bool flag = true;
        for (int j = i + 1; j < n; j++) {
            if (t[j] == t[i]) {
                ops(i, j, s, t, ans);
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = i + 1; j < n; j++) {
                if (t[i] == s[j]) {
                    ops(j, i + 1, s, t, ans);
                    ops(i, i + 1, s, t, ans);
                    flag = false;
                    break;
                }
            }
        }
        if (flag) return (void)(cout << "NO" << endl);
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto &x : ans) cout << x.first + 1 << " " << x.second  + 1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
