#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
constexpr int mod = 1e9 + 7;
i64 powf(i64 x, i64 y, i64 _mod) {
    if (y < 0) return 0;
    i64 res = 1;
    while (y > 0) {
        if (y & 1)
            res *= x, res %= _mod;
        x = x * x, x %= _mod;
        y >>= 1;
    }
    return res;
}
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    i64 a,b,n,x;
    cin>>a>>b>>n>>x;;
    if(a == 1){
        cout << (n  % mod * b  + x) % mod << endl;
        return 0;
    }
    i64 ans , an, inv_as1;
    an = powf(a,n,mod);
    inv_as1 = powf(a - 1,mod-2,mod);
    ans = (an * x ) % mod;
    ans += (an -1 ) * b % mod * inv_as1 % mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
