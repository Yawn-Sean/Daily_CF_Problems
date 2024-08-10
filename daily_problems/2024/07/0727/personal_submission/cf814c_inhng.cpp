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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<map<char, int>> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            int left = 0, right = 0, diff = 0;
            while (left < n) {
                while (right < n and diff + (s[right] != c) <= i) {
                    diff += (s[right++] != c);
                }
                cnt[i][c] = max(cnt[i][c], right - left);
                diff -= (s[left++] != c);
            }
        }
    }
    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        cout << cnt[m][c] << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
