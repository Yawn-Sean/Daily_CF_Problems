#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k, x;
    cin >> n >> x >> k;
    vector <long long> nums(n);
    for (auto &y : nums) cin >> y;
    sort(nums.begin(), nums.end());

    auto low_find = [&](long long x)->int{
        return lower_bound(nums.begin(), nums.end(), x)  - nums.begin();
    };
    auto find = [&](long long x)->int{
        return upper_bound(nums.begin(), nums.end(), x) - nums.begin();
    };

    long long res = 0;
    for (auto &L : nums){
        long long L1 = x * (k + (L-1)/x), L2 = x * (k+1 + (L-1)/x);
        int l = find(max(L1-1, L-1)), r = find(L2-1)-1;
        if (l <= r) res += r-l+1;
    }

    cout << res << "\n";
}
 
