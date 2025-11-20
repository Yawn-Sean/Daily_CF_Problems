#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 5), b(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> nums(2 * n + 5);
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            nums[2 * i - 1] = a[i];
            nums[2 * i] = b[i];
        }
        else {
            nums[2 * i - 1] = b[i];
            nums[2 * i] = a[i];
        }
    }
    vector<int> low;
    for (int i = 1; i <= 2 * n; i++) {
        int pos = lower_bound(low.begin(), low.end(), nums[i]) - low.begin();
        if (pos == low.size()) low.push_back(nums[i]);
        else low[pos] = nums[i];
    }
    cout << low.size();
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}