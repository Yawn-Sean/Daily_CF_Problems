#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
const int N = 0x7fffffff;
const int mod = 998244353;
const int X4[4] = {1, -1, 0, 0}, Y4[4] = {0, 0, 1, -1};
const int X8[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Y8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int Xh[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int Yh[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const double pi = acos(-1);
mt19937 rng(time(nullptr));




double work(double len, double n) {
    return n * (len * len) / 4 / tan(pi / n);
}

void solve(){
    double m, t;
    cin >> m >> t;
    int l = 3, r = t / m;
    if (r <= 2) {cout << 0 << endl; return;}
    while (l < r) {
        int mid = l + r >> 1;
        if (work(double(t / mid - m), double(mid)) > work(double(t / (mid + 1) - m), double(mid + 1))) r = mid;
        else l = mid + 1;
    }
    cout << work(double(t / l - m), double(l)) << endl;
}

signed main(){
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}