#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    map <int,int> mps;
    vector <int> nums(2*n);
    for (auto &x : nums) cin >> x;
    int res = 2*n;
    for (int i = 2*n-1, sum = 0; i >= n; -- i){
        sum += nums[i] == 1 ? 1 : -1;
        mps[sum] = i;
        if (!sum){
            res = min(res, i);
        }
    }
    for (int i = 0, sum = 0; i < n; ++ i){
        sum += nums[i] == 1 ? 1 : -1;
        if (!sum){
            res = min(res, 2*n-(i+1));
        }
        if (mps.count(-sum)){
            res = min(res, mps[-sum]-i-1);
        }
    }
    cout << res << "\n";
}
