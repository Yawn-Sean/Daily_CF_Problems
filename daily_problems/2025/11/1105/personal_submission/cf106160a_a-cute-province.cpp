#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e7 + 10;
long double dp[N];
void solve()
{
    string n;
	cin >> n;

	int k = n.size();

	long double ans = 0, val = 0, cur = 1;

	for (int i = 0; i < k - 1; i ++) {
		val += (n[i] - '0') * cur;
		ans += val;
		cur /= 10;
        
	}

	val += (n.back() - '0') * cur;

	cout << fixed << setprecision(15) << ans * 0.9 + val;
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
