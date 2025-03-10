#include <bits/stdc++.h>
// #define int long long
using namespace std;
int ch[30 * 1000000 + 5][2];
int cnt[30 * 1000000 + 5][2];
struct Trie {
    int n, idx;
    // vector<vector<int>> ch;
    // vector<vector<int>> cnt;
    Trie(int n) {
        this->n = n;
        idx = 0;
        // ch.resize(30 * (n + 1), vector<int>(2));
        // cnt.resize(30 * (n + 1), vector<int>(2));
    }
    void insert(int x) {
        int u = 0;
        for (int i = 30; ~i; i--) {
            int &v = ch[u][x >> i & 1];
            if (!v) v = ++idx;
            cnt[u][x >> i & 1]++;
            u = v;
        }
    }
    int query(int x) {
        int u = 0, res = x;
        for (int i = 30; ~i; i--) {
            int v = x >> i & 1;
            if (v) {
                if (ch[u][v] && cnt[u][v]) {
                    cnt[u][v]--;
                    res -= (1 << i);
                    u = ch[u][v];
                } else {
                    cnt[u][!v]--;
                    u = ch[u][0];
                }
            } else {
                if (ch[u][0] && cnt[u][v]) {
                    cnt[u][v]--;
                    u = ch[u][0];
                } else {
                    cnt[u][!v]--;
                    res += 1 << i;
                    u = ch[u][1];
                }
            }
        }
        return res;
    }
};

void solve(){
    int n;
    cin >> n;
    Trie t(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans[i] = x;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        t.insert(x);
    }
    for (int i = 0; i < n; i++) {
        ans[i] = t.query(ans[i]);
    }
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
