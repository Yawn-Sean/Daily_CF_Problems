#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using ull = unsigned long long;
const int N = 1011, P = 1e9+7, inf = 1e9;

ll qmi(ll a, ll b){
    ll res = 1;
    // 都要开ll不然强制转换会tle
    while (b){
        if (b&1) res = res*a%P;
        a = a*a%P;
        b >>= 1;
    }
    return res;
}
void solve(){
    ll n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // 输入两个子矩阵的左上角
    if (x1 == x2 && y1 == y2) cout << qmi(k, n*m) << "\n";
    else cout << qmi(k, n*m-r*c) << "\n";
}
