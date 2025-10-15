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

// Let's set a bit and flow!
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<char> equation;

    while (true) {
        char s;
        cin >> s;
        if (s == '=') break;
        equation.emplace_back(s);
    }

    int target;
    cin >> target;

    int pos = 1, neg = 0;

    for (int i = 1; i < equation.size(); i += 2) {
        if (equation[i] == '+') pos ++;
        else neg ++;
    }

    if (pos - neg * target <= target && pos * target - neg >= target) {
        cout << "Possible\n";
        int to_add = target - (pos - neg * target);
        
        vector<int> v1(pos, 1), v2(neg, target);
        for (auto &v: v1) {
            int diff = min(to_add, target - 1);
            v += diff, to_add -= diff;
        }
        for (auto &v: v2) {
            int diff = min(to_add, target - 1);
            v -= diff, to_add -= diff;
        }
        cout << v1.back(); v1.pop_back();
        for (int i = 1; i < equation.size(); i += 2) {
            if (equation[i] == '+') cout << " + " << v1.back(), v1.pop_back();
            else cout << " - " << v2.back(), v2.pop_back();
        }
        cout << " = " << target;
    }
    else cout << "Impossible\n";

    return 0;
}