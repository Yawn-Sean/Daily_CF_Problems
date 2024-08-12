#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    m--;
    int left = 0, right = n;
    vector<int> ans(n);
    for (int i = 1; i < n; ++i) {
        (m >> (n - i - 1) & 1 ? ans[--right] : ans[left++]) = i; 
    }
    ans[left] = n;
    for (int ai : ans) {
        cout << ai << " \n"[ai == ans.back()];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
