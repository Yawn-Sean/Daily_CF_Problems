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

void solve() { 
    string s; cin >> s;
    int n = s.size();
    s = s + s;
    int ans = 1, cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) cnt += 1;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = min(max(ans, cnt), n);
    cout << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
