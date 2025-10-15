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

    auto query = [&] (int i, int x) -> bool {
        cout << "? " << i + 1 << ' ' << x << endl;
        char c; cin >> c;
        return c == '<';
    };

    int n;
    cin >> n;

    vector<int> ans(n);

    int cur = 1;
    for (int i = 0; i < n; i ++) {
        while (query(i, cur)) cur ++;
        ans[i] = cur;
    }

    cout << '!';
    for (auto &x: ans) cout << ' ' << x;

    return 0;
}