#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
const int N = 0x7fffffff;
const int mod = 1e9 + 7;
const int X4[4] = {1, -1, 0, 0}, Y4[4] = {0, 0, 1, -1};
const int X8[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Y8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int Xh[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int Yh[8] = {2, 1, -1, -2, -2, -1, 1, 2};
mt19937 rng(time(nullptr));



vector<ll> fac(200000);

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> nums(2 * n + 5);
    vector<int> x(2 * n + 5), y(2 * n + 5);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> nums[i].first >> nums[i].second;
        x[i] = nums[i].first, y[i] = nums[i].second;
    }
    sort(x.begin() + 1, x.begin() + 1 + 2 * n);
    sort(y.begin() + 1, y.begin() + 1 + 2 * n);
    int xlim, ylim;
    if (x[n] != x[n + 1]) xlim = x[n];
    else {cout << 0 << endl; return;}
    if (y[n] != y[n + 1]) ylim = y[n];
    else {cout << 0 << endl; return;}
    ll a = 0, b = 0, c = 0, d = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (nums[i].first <= xlim) {
            if (nums[i].second <= ylim) a++;
            else b++;
        }
        else {
            if (nums[i].second <= ylim) c++;
            else d++;
        }
    }
    cout << (fac[a] * fac[b]) % mod << endl;
}

signed main(){
    fac[0] = 1;
    for (int i = 1; i <= 2e5; i++) fac[i] = (fac[i - 1] * i) % mod;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}