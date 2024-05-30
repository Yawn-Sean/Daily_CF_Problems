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

const int MOD = 1e9 + 7;

int dfs(int ind, int k, bool islimit, string &s, vector<vector<int>> &dp) {
    if (ind == s.size()) return !k;
    if (!islimit && dp[ind][k] != -1) return dp[ind][k];
    int res = 0;
    int up = 1;
    if (islimit) up = min(s[ind] - '0', 1);
    for (int i = 0; i <= up; i++) {
        if (i == 1 && k == 0) continue;
        (res += dfs(ind + 1, k - i, islimit && s[ind] - '0' == i, s, dp)) %= MOD;
    }
    if (!islimit) dp[ind][k] = res;
    return res;
}

int binary_one(int x) {
    int cnt = 0;
    while (x) cnt += 1, x ^= x & -x;
    return cnt;
}

void solve() { 
    string s; cin >> s;
    int k; cin >> k;
    if (k == 0) return (void)(cout << "1" << endl);
    if (k == 1) return (void)(cout << s.size() - 1 << endl);
    int ans = 0;
    vector<int> arr(1010);
    vector<vector<int>> dp(1005, vector<int> (1005, -1));
    for (int i = 2; i <= s.size(); i++) arr[i] = arr[binary_one(i)] + 1;
    for (int i = 1; i <= s.size(); i++) {
        if (arr[i] == k - 1) {
            (ans += dfs(0, i, true, s, dp)) %= MOD;
        }
    }
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
