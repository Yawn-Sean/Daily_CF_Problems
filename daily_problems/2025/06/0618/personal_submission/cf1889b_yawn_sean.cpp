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

    int t;
    cin >> t;

    while (t --) {
        int n, c;
        cin >> n >> c;
        
        vector<long long> nums(n);
        for (auto &v: nums) cin >> v;

        vector<int> idxs(n - 1);
        iota(idxs.begin(), idxs.end(), 1);
        sort(idxs.begin(), idxs.end(), [&] (int i, int j) {return 1ll * i * c - nums[i] < 1ll * j * c - nums[j];});

        long long cur = nums[0];
        bool flg = true;

        for (auto &i: idxs) {
            if (cur + nums[i] >= 1ll * c * (i + 1)) cur += nums[i];
            else flg = false;
        }

        cout << (flg ? "Yes" : "No") << '\n';
    }

    return 0;
}