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

    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < i; j ++) {
            int k = (nums[i] - nums[j]) * 2 / (i - j);
            set<long long> st;
            for (int idx = 0; idx < n; idx ++) {
                st.emplace(nums[idx] * 2 - 1ll * idx * k);
                if (st.size() > 2) break;
            }
            if (st.size() == 2)
                return cout << "Yes", 0;
        }
    }
    cout << "No";

    return 0;
}