#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, m, d;
    cin >> n >> m >> d;
 
    vector<int> nums(n);
    for (auto &v: nums) cin >> v;
 
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});
 
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        bool flg = true;
 
        for (int i = m; i < n; i ++) {
            if (nums[order[i]] - nums[order[i - m]] <= d) {
                flg = false;
            }
        }
 
        if (flg) r = m - 1;
        else l = m + 1;
    }
 
    cout << l << '\n';
 
    vector<int> ans(n);
 
    for (int i = 0; i < n; i ++)
        ans[order[i]] = i % l + 1;
    
    for (auto &x: ans) cout << x << ' ';
 
    return 0;
}
