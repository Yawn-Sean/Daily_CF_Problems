/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll=long long;
using lld = long double;
const int mod = 998244353;
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve(){
    int n;
    cin >> n;

    vector<int> nums(n), cnt(11);
    for (auto &num: nums) cin >> num;

    int ans = 0, mod = 998244353;

    for (auto x: nums) {
        int len = 0;
        while (x) x /= 10, len ++;
        cnt[len] ++;
    }

    for (auto x: nums) {
        long long a = x, b = 0, power = 1;

        for (int i = 1; i < 11; i ++) {
            b = (b + a % 10 * power) % mod;
            a /= 10;
            ans += (a * 10 * power + b) % mod * cnt[i] * 10 % mod;
            if (ans >= mod) ans -= mod;
            ans += (a * 100 * power + b) % mod * cnt[i] % mod;
            if (ans >= mod) ans -= mod;
            power = power * 100 % mod;
        }
    }
    cout << ans << '\n';
    
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