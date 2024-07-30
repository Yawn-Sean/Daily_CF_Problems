#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num: nums) cin >> num;
    
    vector<int> cnt(5000);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < i; j ++)
            cnt[abs(nums[i] - nums[j])] ++;
    
    vector<long long> cnt2(5000);
    for (int i = 0; i < 5000; i ++)
        for (int j = 0; j < 5000 - i; j ++)
            cnt2[i + j] += cnt[i] * cnt[j];
    
    for (int i = 1; i < 5000; i ++)
        cnt2[i] += cnt2[i-1];

    long long ans = 0;
    for (int i = 1; i < 5000; i ++)
        ans += cnt2[i-1] * cnt[i];
    
    cout << setprecision(15) << 1.0 * ans / pow(1.0 * n * (n - 1) / 2, 3);

    return 0;
}