#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+11;

struct Hash {
    vector <int> h, ne, val, cnt;
    int idx = -1;
    Hash(){}
    Hash(int n): h(n, -1), ne(n), val(n), cnt(n){}
    void insert(ll x){
        ll k = (x%N+N)%N;
        for (int i = h[k]; ~i; i = ne[i])
            if (val[i] == x){
                ++ cnt[i];
                return;
            }
        ++ idx;
        ne[idx] = h[k], h[k] = idx;
        val[idx] = x, cnt[idx] = 1;
    }
    ll find(ll x){
        ll k = (x%N+N)%N;
        for (int i = h[k]; ~i; i = ne[i])
            if (val[i] == x) return cnt[i];
        return 0;
    }
} mp[12](N);

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n+1);
    auto bits = [](int x){
        int res = 0;
        while (x) x /= 10, ++ res;
        return res;
    };

    for (int i = 1; i <= n; ++ i)
        cin >> a[i], mp[bits(a[i])].insert(a[i]%k); //(num[i]*pow(10, k) + num[j])%k == 0，其中k是num[j]的位数

    ll res = 0;
    for (int i = 1, len; i <= n; ++ i){
        len = bits(a[i]);
        ll x = a[i];
        for (int j = 1; j <= 10; ++ j){
            x *= 10, x %= k;
            res += mp[j].find((-x%k+k)%k);
            if (len == j && (x+a[i])%k == 0) -- res;
        }
    }
    
    cout << res << "\n";
}
