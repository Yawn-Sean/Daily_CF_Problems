#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef array<int, 2> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int n = s.size(), ans = 0, cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    mp[1] = -1;

    int cur = 0;

    for (int i = 0; i < n; i ++) {
        int v = (st.find(s[i]) != st.end() ? -1 : 2);
        cur += v;
        if (mp.find(cur) == mp.end()) {
            if (v < 0) mp[cur] = i;
            else mp[cur - 1] = mp[cur - 2], mp[cur] = mp[cur - 2];
        }

        v = i;
        for (int j = 0; j <= 2; j ++) {
            if (mp.find(cur - j) != mp.end()) {
                v = min(v, mp[cur - j]);
            }
        }

        v = i - v;
        if (v == ans) cnt ++;
        else if (v > ans) {
            ans = v;
            cnt = 1;
        }
    }

    if (ans) cout << ans << ' ' << cnt;
    else cout << "No solution";

    return 0;
}