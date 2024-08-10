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

    vector<int> vals, cnts;
    int last = 0, cnt = 0;

    for (auto &num: nums) {
        if (num != last) {
            if (cnt)
                vals.push_back(last), cnts.push_back(cnt);
            last = num, cnt = 1;
        }
        else cnt ++;
    }
    vals.push_back(last), cnts.push_back(cnt);

    int k = vals.size();
    vector<int> pre(k), nex(k);
    
    iota(pre.begin(), pre.end(), -1);
    iota(nex.begin(), nex.end(), 1);

    function<void(int)> f = [&] (int x) {
        cnts[x] = 0;
        if (pre[x] >= 0) nex[pre[x]] = nex[x];
        if (nex[x] < k) pre[nex[x]] = pre[x];
    };

    priority_queue<pair<int, int>> hpq;
    for (int i = 0; i < k; i ++)
        hpq.push({cnts[i], -i});
    
    int ans = 0;
    while (!hpq.empty()) {
        auto [c, i] = hpq.top();
        hpq.pop();
        i = -i;
        if (cnts[i] != c) continue;
        ans ++;
        if (pre[i] >= 0 && nex[i] < k && vals[pre[i]] == vals[nex[i]]) {
            cnts[pre[i]] += cnts[nex[i]];
            f(nex[i]);
            hpq.push({cnts[pre[i]], -pre[i]});
        }
        f(i);
    }
    cout << ans << '\n';

    return 0;
}