#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> cnt(n, vector<int>(n));

    while (true) {
        vector<string> strs(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 20; j ++) {
                strs[i] += (rng() & 1) ? 'X' : 'O';
            }
        }

        set<int> vis;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                string vs = strs[i] + strs[j];
                set<string> st;

                for (int x = 0; x < vs.size(); x ++) {
                    for (int y = x; y < vs.size(); y ++) {
                        st.insert(vs.substr(x, y - x + 1));
                    }
                }

                cnt[i][j] = st.size();
                vis.insert(cnt[i][j]);
            }
        }

        if (vis.size() == n * n) {
            for (auto &x: strs) cout << x << endl;
            break;
        }
    }

    int q;
    cin >> q;

    while (q --) {
        int target;
        cin >> target;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (cnt[i][j] == target) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
        }
    }

    return 0;
}