#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const double pi = acos(-1);




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