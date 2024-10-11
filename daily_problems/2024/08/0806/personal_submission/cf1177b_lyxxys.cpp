#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1050, M = 1<<10, mod = 998244353, inf = 1e9;

void solve(){
    ll step = 1, base = 9;
    ll k;
    cin >> k;
    ll sum = 0, cur = 0;

    while (sum + step*base <= k){
        sum += step*base;
        cur += base;
        ++ step, base *= 10;
    }
    
    k -= sum;
    int ans = 0;
    if (k){
        ll digit = cur + ceil(1.0*k/step), to = (k-1)%step;
        string num = to_string(digit);
        ans = num[to] - '0';
    } else ans = 9;

    cout << ans << "\n";
}
