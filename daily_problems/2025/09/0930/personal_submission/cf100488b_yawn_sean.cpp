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

set<int> query(int l, int r) {
    cout << "Q " << l << ' ' << r << endl;
    set<int> st;
    for (int i = l; i <= r; i ++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    return st;
}

void answer(vector<int> &ans) {
    cout << 'A';
    for (auto &x: ans) cout << ' ' << x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ans(n);

    set<int> to_fill;
    for (int i = 1; i <= n; i ++)
        to_fill.insert(i);
    
    if (n & 1) {
        auto res = query(n, n);
        ans[n - 1] = *res.begin();
        to_fill.erase(ans[n - 1]), n --;
    }

    if (n > 1) {
        auto left = query(1, n / 2);
        set<int> right;

        for (auto &v: to_fill)
            if (left.find(v) == left.end())
                right.insert(v);
        
        for (int i = 2; i <= n / 2; i ++) {
            auto mid = query(i, n + 1 - i);
            
            for (auto v: left) {
                if (mid.find(v) == mid.end()) {
                    left.erase(v);
                    ans[i - 2] = v;
                    break;
                }
            }

            for (auto v: right) {
                if (mid.find(v) == mid.end()) {
                    right.erase(v);
                    ans[n - i + 1] = v;
                    break;
                }
            }
        }

        ans[n / 2 - 1] = *left.begin();
        ans[n / 2] = *right.begin();
    }

    answer(ans);

    return 0;
}