#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int cnt1[N], cnt2[N];
void solve()
{   
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i =1 ; i <= n;i ++){
        cin >> a[i] >> b[i];
        cnt1[a[i]]++;
        cnt2[b[i]]++;
    }
    int sum = 0;
    for(int i = 1; i <= n; i ++)sum += (cnt1[a[i]]-1) * (cnt2[b[i]]-1);
    cout << n*(n-1)*(n-2)/6 - sum << '\n';
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
