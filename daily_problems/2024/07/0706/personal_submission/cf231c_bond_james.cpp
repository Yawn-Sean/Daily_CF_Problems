/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(0);
#define int long long
using namespace std;
using ll=long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &num: nums) cin >> num;

    sort(nums.begin(), nums.end());

    int l = 0, r = 0;
    int ans = 0, val = 0;
    long long cur = 0;

    while (r < n) {
        if (r > l) {
            cur += 1LL * (nums[r] - nums[r - 1]) * (r - l);
        }
        while (cur > k) {
            cur -= nums[r] - nums[l];
            l++;
        }
        if (r - l + 1 > ans) {
            ans = r - l + 1;
            val = nums[r];
        }
        r++;
    }

    cout << ans << ' ' << val << '\n';


}

int32_t main()
{
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
    solve();
    }
    return 0;
}