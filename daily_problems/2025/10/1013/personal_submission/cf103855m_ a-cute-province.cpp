#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n), ve1(n), ve2(n);
    for(int i = 0; i <n; i ++)cin >> p[i];
    for(int i = 0; i <n; i ++)cin >> q[i];
    for(int i = 0; i<n; i ++)ve1[i] = p[i]+q[i], ve2[i] = p[i]-q[i];
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(ve1.begin(), ve1.end());
    sort(ve2.begin(), ve2.end());
    int ans = 0, v1 = 0, v2 = 0, sum = 0;
    for(int i = 1 ; i < n; i ++)v2 += p[i];
    for(int i = 0; i < n; i ++){
        ans += v2 - (n-1-i) * p[i] + i * p[i] - v1;
        v1 += p[i];
        v2 -= p[i+1];
    }
    v1 = v2 = 0;
    for(int i = 1 ; i < n; i ++)v2 += q[i];
    for(int i = 0; i < n; i ++){
        ans += v2 - (n-1-i) * q[i] + i * q[i] - v1;
        v1 += q[i];
        v2 -= q[i+1];
    }

    v1 = v2 = 0;
    for(int i = 1 ; i < n; i ++)v2 += ve1[i];
    for(int i = 0; i < n; i ++){
        sum += v2 - (n-1-i) * ve1[i] + i * ve1[i] - v1;
        v1 += ve1[i];
        v2 -= ve1[i+1];
    }
    v1 = v2 = 0;
    for(int i = 1 ; i < n; i ++)v2 += ve2[i];
    for(int i = 0; i < n; i ++){
        sum += v2 - (n-1-i) * ve2[i] + i * ve2[i] - v1;
        v1 += ve2[i];
        v2 -= ve2[i+1];
    }
    sum /= 2;
    cout << ans - sum << '\n';

   
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
