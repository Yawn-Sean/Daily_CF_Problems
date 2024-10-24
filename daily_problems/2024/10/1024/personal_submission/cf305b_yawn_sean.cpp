#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long p, q;
    cin >> p >> q;

    vector<long long> vec;

    while (q) {
        vec.emplace_back(p / q);
        p %= q;
        swap(p, q);
    }

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    if (n > 1 && nums.back() == 1) {
        nums.pop_back();
        n --;
        nums.back() ++;
    }

    if (vec.size() == n) {
        for (int i = 0; i < n; i ++) {
            if (nums[i] != vec[i]) {
                return cout << "NO", 0;
            }
        }
        cout << "YES";
    }
    else cout << "NO";

    return 0;
}