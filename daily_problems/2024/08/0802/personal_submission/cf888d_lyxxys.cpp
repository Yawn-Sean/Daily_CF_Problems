#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 200050, mod = 1e9 + 7, inf = 1e9;

void solve(){
    ll n, k;
    cin >> n >> k;

    ll res = 1;
    if (k >= 2){
        res += n*(n-1)/2;
    }
    if (k >= 3){
        res += n*(n-1)*(n-2)/3;
    }
    if (k >= 4){
        res += n*(n-1)*(n-2)*(n-3)*3/8;
    }
    cout << res << "\n";
}
