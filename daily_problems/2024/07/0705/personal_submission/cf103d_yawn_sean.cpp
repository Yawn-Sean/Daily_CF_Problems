#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

    int q, bound = 500;
    cin >> q;

    vector<vector<int>> q_idxs(bound);
    vector<long long> idxs, ans(q);

    for (int q_idx = 0; q_idx < q; q_idx ++) {
        int i, k;
        cin >> i >> k, i --;
        if (k >= bound)
            for (int j = i; j < n; j += k)
                ans[q_idx] += nums[j];
        else q_idxs[k].push_back(q_idx);
        idxs.push_back(i);
    }

    vector<long long> acc(n);

    for (int i = 1; i < bound; i ++)
        if (q_idxs[i].size()) {
            for (int j = n - 1; j >= 0; j --)
                acc[j] = (j + i < n ? acc[j+i] : 0) + nums[j];
            for (auto &j: q_idxs[i])
                ans[j] = acc[idxs[j]];
        }
    
    for (auto &x: ans) cout << x << '\n';

    return 0;
}