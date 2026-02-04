#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> outs;
    outs.reserve(t);

    while(t--){
        int n;
        cin >> n;
        vector<long long> nums(n);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }

        long long mi = *min_element(nums.begin(), nums.end());
        long long ma = *max_element(nums.begin(), nums.end());

        if(mi == ma){
            long long val = 1;
            for(int i = 0; i < n; ++i) val *= 10;
            outs.push_back(val);
        } else {
            long long ans = 1;
            for(long long x : nums){
                if(x == mi){
                    ans *= x;
                } else if(x == ma){
                    ans *= (11 - x);
                }
            }
            outs.push_back(ans);
        }
    }

    for(size_t i = 0; i < outs.size(); ++i){
        cout << outs[i] << "\n";
    }

    return 0;
}
