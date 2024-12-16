#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
using i64 = long long;

void solve(){
    const i64 mod = (1ll << 32) -1;
    const i64 inf = 9e18;
    cout << mod << "\n";
    i64 n, l, r, x, y, z, b1, b2;
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    vector <i64> bs(n), nums(n);
    bs[0] = b1, bs[1] = b2;

    for (int i = 2; i < n; ++ i){
        bs[i] = (bs[i-2]*x + bs[i-1]*y + z) & mod;
    }
    for (int i = 0; i < n; ++ i){
        nums[i] = bs[i] % (r-l+1) + l;
    }

    i64 ans = inf;
    i64 cur_mi = nums[0];
    for (int i = 0; i < n; ++ i){
        if (nums[i] <= cur_mi) cur_mi = nums[i];
        else if (nums[i] >= 0 && nums[i] > cur_mi) fmin(ans, cur_mi*nums[i]);
    }
    i64 cur_ma = nums[n-1];
    for (int i = n-1; i >= 0; -- i){
        if (nums[i] >= cur_ma) cur_ma = nums[i];
        else if (nums[i] <= 0 && nums[i] < cur_ma) fmin(ans, cur_ma*nums[i]);
    }


    if (ans == inf) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
}
