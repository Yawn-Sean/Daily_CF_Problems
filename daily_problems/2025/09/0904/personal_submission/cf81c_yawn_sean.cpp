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

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    if (a == b) {
        while (a --) cout << "1 ";
        while (b --) cout << "2 ";
    }
    else {
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);

        if (a < b) stable_sort(idxs.begin(), idxs.end(), [&] (int i, int j) {return nums[i] > nums[j];});
        else stable_sort(idxs.begin(), idxs.end(), [&] (int i, int j) {return nums[i] < nums[j];});

        vector<int> ans(n, 2);
        for (int i = 0; i < a; i ++) ans[idxs[i]] = 1;

        for (auto &v: ans) cout << v << ' ';
    }

    return 0;
}