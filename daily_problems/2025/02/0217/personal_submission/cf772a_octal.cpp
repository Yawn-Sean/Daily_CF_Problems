#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const long double eps = 1e-5;
inline void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
    auto judge = [&]() {
        long double s = 0;
        for(int i=1; i<=n; i++) {
            s += a[i];
        }
        return p >= s;
    };
    if(judge()) {
        cout << -1 << endl;
        return;
    }
    auto check = [&](double x) {
        long double s = 1.0*p*x;
        for(int i=1; i<=n; i++) {
            s -= max(0.0, x*a[i]-b[i]);
        }
        return s >= 0.0;
    };
    long double l = 0.0, r = 1e11;
    while((r-l) >= eps) {
        long double mid = (l+r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}
