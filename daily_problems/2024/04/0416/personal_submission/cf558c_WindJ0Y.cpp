#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    
    vector<int> nums(n);
    vector<int> ncnt(1e5 + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        int t = nums[i];
        while (t) {
            ncnt[t]++;
            t >>= 1;
        }
    }

    int mxcnt = 0;
    int mxval = -1;

    for (int i = 0 ; i <= 1e5; i ++) {
        if (ncnt[i] >= mxcnt) {
            mxcnt = ncnt[i];
            mxval = i;
        }
    }

    set<int> oknums;
    for (int t = mxval; t < 1e8; t <<= 1) {
        oknums.insert(t);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!oknums.count(nums[i])) {
            nums[i] >>= 1;
            ans ++;
        }
    }

    sort(nums.begin(), nums.end());
    int target = nums[n/2];

    for (int i = 0; i < n; i++) {
        while (nums[i] < target) {
            nums[i] <<= 1;
            ans ++;
        }
        while (nums[i] > target) {
            nums[i] >>= 1;
            ans ++;
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("558c.in", "r", stdin);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}