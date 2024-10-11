/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll = long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    int g = 0;
    for (auto &num: nums)
        cin >> num, g = __gcd(g, num);
    
    cout << "YES\n";
    if (g > 1) 
        cout << 0;
    else {
        int ans = 0, cnt = 0;
        for (auto &num: nums) {
            if (num & 1) 
                cnt ++;
            else
                ans += cnt / 2 + cnt % 2 * 2, cnt = 0;
        }
        ans += cnt / 2 + cnt % 2 * 2;
        cout << ans;
    }
}

int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}