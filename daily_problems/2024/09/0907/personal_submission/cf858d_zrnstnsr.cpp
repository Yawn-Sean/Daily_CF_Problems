#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> hash(n, vector<int>(81));
    vector<map<int, int>> mps(n);
    map<int, int> mp;
    auto base = 11;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int l = 0; l < 9; ++l) {
            int h = 0;
            for (int m = 0; m < 9 - l; ++m) {
                h = h * base + s[i][l+m] - '0' + 1;
                hash[i][l * 9 + m] = h;
                ++mp[h];
                ++mps[i][h];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int m = 0; m < 9; ++m) for (int l = 0; l < 9 - m; ++l) {
            int j = l * 9 + m;
            if (mp[hash[i][j]] == mps[i][hash[i][j]]) {
                println("{}", string_view(s[i].data() + l, m + 1));
                goto next;
            }
        }
        next:;
    }
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
