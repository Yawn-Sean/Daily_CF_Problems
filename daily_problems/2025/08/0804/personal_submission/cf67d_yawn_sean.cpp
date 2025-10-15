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

    vector<int> pos1(n), pos2(n);

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pos1[x - 1] = i;
    }
    
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pos2[x - 1] = i;
    }

    vector<int> ar(n);
    for (int i = 0; i < n; i ++)
        ar[pos1[i]] = -pos2[i];
    
    vector<int> d;

    for (auto &x: ar) {
        int pos = lower_bound(d.begin(), d.end(), x) - d.begin();
        if (d.size() == pos) d.emplace_back(x);
        else d[pos] = x;
    }

    cout << d.size();

    return 0;
}