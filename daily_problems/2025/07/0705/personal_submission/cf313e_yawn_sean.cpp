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

    int n, m;
    cin >> n >> m;

    vector<int> c1(m, 0), c2(m, 0);

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        c1[x] ++;
    }

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        c2[x] ++;
    }

    vector<int> ans, stk;

    for (int i = 0; i < m; i ++) {
        while (c1[i] --)
            stk.emplace_back(i);
        
        while (c2[m - i - 1] && !stk.empty()) {
            c2[m - i - 1] --;
            int v = stk.back(); stk.pop_back();
            ans.emplace_back(v + m - i - 1);
        }
    }

    for (int i = m - 1; i >= 0; i --) {
        while (c2[i] --) {
            int v = stk.back(); stk.pop_back();
            ans.emplace_back(v + i - m);
        }
    }

    sort(ans.rbegin(), ans.rend());

    for (auto &v: ans) cout << v << ' ';

    return 0;
}