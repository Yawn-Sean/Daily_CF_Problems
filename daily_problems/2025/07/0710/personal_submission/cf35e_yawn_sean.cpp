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

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    map<int, vector<int>> diff;
    while (n --) {
        int h, l, r;
        fin >> h >> l >> r;
        diff[l].emplace_back(h);
        diff[r].emplace_back(-h);
    }

    int cur_h = 0;
    multiset<int> vals;
    vals.insert(0);

    vector<pair<int, int>> pts;

    for (auto &[k, v]: diff) {
        for (auto &x: v) {
            if (x > 0) vals.insert(x);
            else vals.erase(vals.find(-x));
        }
        int new_h = *vals.rbegin();
        if (cur_h != new_h) {
            pts.emplace_back(k, cur_h);
            pts.emplace_back(k, new_h);
            cur_h = new_h;
        }
    }

    fout << pts.size() << '\n';
    for (auto &[x, y]: pts) fout << x << ' ' << y << '\n';

    return 0;
}