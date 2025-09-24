#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
struct Trie {
    vector<int> one, zero;
    int size, pt;
    Trie(int size) : one(size + 1), zero(size + 1) {
        this->size = size;
        pt = 1;
    }
    void insert(int x) {
        int cur = 1;
        for (int i = 32; i >= 0; i--) {
            if (x >> i & 1) {
                if (!one[cur])
                    one[cur] = ++pt;
                cur = one[cur];
            } else {
                if (!zero[cur])
                    zero[cur] = ++pt;
                cur = zero[cur];
            }
        }
    }
    int find(int x) {
        int cur = 1, ans = 0;
        for (int i = 32; i >= 0; i--) {
            ans <<= 1;
            if (x >> i & 1) {
                if (zero[cur])
                    cur = zero[cur], ans++;
                else
                    cur = one[cur];
            } else {
                if (one[cur])
                    cur = one[cur], ans++;
                else
                    cur = zero[cur];
            }
        }
        return ans;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (auto& v : a)
        cin >> v;
    for (int i = 1; i < n - 1; i++) {
        a[i] ^= a[i - 1];
    }
    Trie T(n * 32);
    T.insert(0);
    for (auto& v : a)
        T.insert(v);
    for (int i = 0; i < n; i++) {
        if (T.find(i) == n - 1) {
            cout << i;
            for (auto& v : a)
                cout << ' ' << (i ^ v);
            return;
        }
    }
}

signed main() {
    IOS;
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}