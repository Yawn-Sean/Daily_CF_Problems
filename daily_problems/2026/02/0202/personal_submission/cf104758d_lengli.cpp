#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    vector<long long> pref = nums, suff = nums;

    for(int i = 1; i < n; ++i){
        pref[i] = max(pref[i - 1], pref[i]);
    }
    for(int i = n - 2; i >= 0; --i){
        suff[i] = max(suff[i], suff[i + 1]);
    }

    long long ans = 0;
    long long cur = 0;

    for(int i = 0; i < n; ++i){
        long long x = min(pref[i], suff[i]) - nums[i];
        if(x == 0){
            cur = 0;
        } else {
            cur += x;
        }
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}
