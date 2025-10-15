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

    vector<int> p1(n), p2(n);
    for (auto &x: p1) cin >> x, x --;
    for (auto &x: p2) cin >> x, x --;

    vector<int> pos1(n), pos2(n);
    for (int i = 0; i < n; i ++)
        pos1[p1[i]] = i, pos2[p2[i]] = i;
    
    vector<vector<int>> updates1_add(n + 1), updates1_remove(n + 1), updates2_add(n + 1), updates2_remove(n + 1);

    for (int i = 0; i < n; i ++) {
        int x = pos2[i], y = pos1[i], v = abs(x - y);
        if (x >= y) {
            updates1_add[0].emplace_back(v);
            updates1_remove[v].emplace_back(v);

            updates2_add[v].emplace_back(-v);
            updates2_remove[x + 1].emplace_back(-v);

            updates1_add[x + 1].emplace_back((x + 1) + (n - 1 - y));
        }
        else {
            updates2_add[0].emplace_back(v);
            updates2_remove[x + 1].emplace_back(v);

            updates1_add[x + 1].emplace_back((x + 1) + (n - 1 - y));
            updates1_remove[(x + 1) + (n - 1 - y)].emplace_back((x + 1) + (n - 1 - y));

            updates2_add[(x + 1) + (n - 1 - y)].emplace_back(-((x + 1) + (n - 1 - y)));
        }
    }

    multiset<int> v1, v2;
    int inf = 1e7;

    v1.insert(inf), v2.insert(inf);

    for (int i = 0; i < n; i ++) {
        for (auto &x: updates1_add[i]) v1.insert(x);
        for (auto &x: updates1_remove[i]) v1.erase(v1.find(x));
        for (auto &x: updates2_add[i]) v2.insert(x);
        for (auto &x: updates2_remove[i]) v2.erase(v2.find(x));

        cout << min(*v1.begin() - i, *v2.begin() + i) << '\n';
    }

    return 0;
}