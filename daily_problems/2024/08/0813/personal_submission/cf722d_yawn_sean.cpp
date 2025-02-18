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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    set<int> vis(nums.begin(), nums.end());
    priority_queue<int> hpq(nums.begin(), nums.end());

    while (true) {
        int x = hpq.top(), target = x;
        while (vis.find(target) != vis.end()) {
            target /= 2;
        }
        if (!target) break;
        hpq.pop();
        hpq.push(target);
        vis.erase(x);
        vis.emplace(target);
    }

    for (auto &x: vis) cout << x << ' ';

    return 0;
}