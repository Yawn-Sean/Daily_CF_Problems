#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const long double eps = 1e-10;
inline void solve()
{
    int n, k;
    double l, v1, v2;
    cin >> n >> l >> v1 >> v2 >> k;
    int tot = (n+k-1) / k;
    auto check = [&](long double x) {
        long double t = x / v2;
        long double s1 = v1 * t;
        long double s2 = x;
        for(int i=1; i<=tot-1; i++) {
            long double t = (s2-s1) / (v1+v2);
            s1 += v1 * t;
            s2 += v1 * t;
            t = (s2-s1) / (v2-v1);
            s1 += v1 * t;
            s2 += v1 * t;
        }
        return s2 <= l;
    };
    auto cal = [&](long double x) {
        long double t = x / v2;
        long double s1 = v1 * t;
        long double s2 = x;
        long double res = t;
        for(int i=1; i<=tot-1; i++) {
            t = (s2-s1) / (v1+v2);
            res += t;
            s1 += v1 * t;
            s2 += v1 * t;
            t = (s2-s1) / (v2-v1);
            res += t;
            s1 += v1 * t;
            s2 += v1 * t;
        }
        return res;
    };
    long double L = 0, R = l;
    while((R-L) >= eps) {
        long double mid = (L + R) / 2.0;
        if(check(mid)) L = mid;
        else R = mid;
    }
    cout << cal(L) << endl;
}
