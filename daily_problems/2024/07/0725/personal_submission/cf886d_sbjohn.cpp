#include <bits/stdc++.h>

#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
//constexpr int mod = 1e9 + 7;

bool check(string &s) {
    unordered_map<char, int> mp;
    for (auto c: s) {
        mp[c]++;
        if (mp[c] > 1) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<string> vs(n);
    vi next(26, -1), cnt(26), cnts(26);
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
        if (!check(vs[i])) {
            cout << "NO" << endl;
            return;
        }
        int l = vs[i].length();
        for (int k = 0; k < l - 1; ++k) {
            int c = vs[i][k] - 'a', v = vs[i][k + 1] - 'a';
            cnt[c] = cnt[v] = 1;
            if (next[c] >= 0 && next[c] != v) {
                cout << "NO" << endl;
                return ;
            }
            next[c] = v;
            cnts[v] = 1;
        }
        cnt[vs[i][l - 1] - 'a'] = 1;
    }
    string ans = "";
    vi vis(26);
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] && !cnts[i]) {
            for (int x = i; x != -1; x = next[x]) {
                if (vis[x]) {
                    cout << "NO" << endl;
                    return;
                }
                vis[x] = 1;
                ans += char(x + 'a');
            }
        }
    }
    int s1 = accumulate(all(cnt),0),s2 = accumulate(all(vis),0);
    if (s1 != s2)
        cout << "NO" << endl;
    else
        cout << ans << endl;
}


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

}






