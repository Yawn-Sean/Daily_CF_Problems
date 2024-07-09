#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e5+5, inf = (1u<<31)-1, mod = 998244353;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> nums(n+1);
    for (int i = 1; i <= n; ++ i) cin >> nums[i];

    sort(nums.begin()+1, nums.end());
    int res1 = 0, res2;
    //左指针 不会向右走，因为向右走不会使答案更优且满足限制条件
    ll last = 0;
    for (int j = n, i = n+1; j >= 1; -- j){
        ll sum = k - (nums[j]*(j-i+1) - last);
        while (i-1 >= 1 &&  sum >= nums[j]-nums[i-1]){
            last += nums[i-1];
            sum -= nums[j]-nums[i-1];
            -- i;
        }
        if (j-i+1 >= res1) res1 = j-i+1, res2 = nums[j];
        last -= nums[j];
    }

    cout << res1 << " " << res2 << "\n";
}
