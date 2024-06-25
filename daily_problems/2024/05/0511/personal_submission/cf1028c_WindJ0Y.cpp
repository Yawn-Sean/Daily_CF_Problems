#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;

    vector<int> x0(n), y0(n), x1(n), y1(n);
    for (int i = 0; i < n; i++) {
        cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
    }

    vector<int> x0_max;
    {
        vector<int> nums = x0;
        sort(nums.begin(), nums.end(), greater());
        x0_max = {nums[0], nums[1]};
    }
    vector<int> y0_max;
    {
        vector<int> nums = y0;
        sort(nums.begin(), nums.end(), greater());
        y0_max = {nums[0], nums[1]};
    }
    vector<int> x1_min;
    {
        vector<int> nums = x1;
        sort(nums.begin(), nums.end());
        x1_min = {nums[0], nums[1]};
    }
    vector<int> y1_min;
    {
        vector<int> nums = y1;
        sort(nums.begin(), nums.end());
        y1_min = {nums[0], nums[1]};
    }

    for (int i = 0; i < n; i++) {
        int tx0 = (x0[i] == x0_max[0]) ? x0_max[1] : x0_max[0]; 
        int ty0 = (y0[i] == y0_max[0]) ? y0_max[1] : y0_max[0]; 
        int tx1 = (x1[i] == x1_min[0]) ? x1_min[1] : x1_min[0]; 
        int ty1 = (y1[i] == y1_min[0]) ? y1_min[1] : y1_min[0];
        if (tx0 <= tx1 && ty0 <= ty1) {
            cout << tx0 << " " << ty0 << "\n";
            return;
        } 
    }
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;
    
    while (T--) {
        solve();
    }

}
