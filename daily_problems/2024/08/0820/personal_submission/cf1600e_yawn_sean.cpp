#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int l = 0, r = n - 1;

    while (l < n - 1 && nums[l+1] > nums[l]) l ++;
    while (r > 0 && nums[r-1] > nums[r]) r --;

    cout << (((l + 1) | (n - r)) & 1 ? "Alice" : "Bob");

    return 0;
}