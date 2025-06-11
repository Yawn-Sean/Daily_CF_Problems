#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5e6+7, mod = 1e9+7, inf = 1e9;
ll f[N];
/*
	根据奇偶性来筛出每一个数字的最大约数:
		若这些数字的最大约数是x
			若x是奇数：
				这些数字有：{2*x,3*x,4*x,···,x*x}
			若x是偶数：
				这些数字有：{2*x}
			
*/
void solve(){
    ll t, l, r;
    cin >> t >> l >> r;
    for (ll i = 2; i <= r; ++ i){
        if (!f[i]) f[i] = i*(i-1)/2%mod;
        if (i%2){
            for (ll j = i+i, c = 2; j <= r && c <= i; ++ c, j += i){
                f[j] = (i*f[c]%mod + f[i])%mod;
            }
        } else {
            if (2*i <= r){
                f[2*i] = (i*f[2]%mod + f[i])%mod;
            }
        }
    }
    ll res = 0;
    for (ll i = l, sum = 1; i <= r; ++ i){
        (res += sum*f[i]%mod) %= mod;
        sum = sum*t%mod;
    }
    cout << res << "\n";
}
