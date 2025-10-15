#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n1;
    fin >> n1;

    vector<int> nums1(n1);
    for (auto &v: nums1) fin >> v;

    int n2;
    fin >> n2;

    vector<int> nums2(n2);
    for (auto &v: nums2) fin >> v;

    nums1.emplace_back(0);
    nums2.emplace_back(0);

    int c1 = 0, c2 = 0;

    for (int i = 1; i <= n1; i ++) {
        if (nums1[i] != nums1[i - 1]) {
            c1 ++;
        }
    }
    
    for (int i = 1; i <= n2; i ++) {
        if (nums2[i] != nums2[i - 1]) {
            c2 ++;
        }
    }

    vector<int> vals;
    int p = 0;

    if (c1 < c2) {
        for (int i = 0; i < n2; i ++) {
            while (p < n1 && nums1[p] == nums2[i]) {
                fout << p + 1 << ' ';
                vals.emplace_back(nums1[p]);
                p ++;
            }
            fout << n1 + i + 1 << ' ';
            vals.emplace_back(nums2[i]);
        }

        while (p < n1) {
            fout << p + 1 << ' ';
            vals.emplace_back(nums1[p]);
            p ++;
        }
    }

    else {
        for (int i = 0; i < n1; i ++) {
            while (p < n2 && nums2[p] == nums1[i]) {
                fout << n1 + p + 1 << ' ';
                vals.emplace_back(nums2[p]);
                p ++;
            }
            fout << i + 1 << ' ';
            vals.emplace_back(nums1[i]);
        }

        while (p < n2) {
            fout << n1 + p + 1 << ' ';
            vals.emplace_back(nums2[p]);
            p ++;
        }
    }

    fout << '\n';

    vals.emplace_back(0);
    vector<int> idxs;

    for (int i = 1; i <= n1 + n2; i ++) {
        if (vals[i] != vals[i - 1]) {
            idxs.emplace_back(i);
        }
    }

    fout << idxs.size() << '\n';
    for (auto &idx: idxs) fout << idx << ' ';

    return 0;
}