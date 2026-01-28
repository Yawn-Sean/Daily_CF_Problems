#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
void solve()
{   
    int n;
	cin >> n;
    //+v 只影响一个行/列/对角线
    /*
        1 0 0 0 0
        0 0 1 0 0
        0 0 0 1 0
        0 0 0 0 1
        0 1 0 0 0
    */ 
	if (n == 3) {
		cout << "1 1 2\n";
		cout << "1 4 3\n";
		cout << "2 3 3\n";
	}
	else {
		vector<vector<int>> ans(n, vector<int>(n, 1));
		int v = 1024 - n;

		if (n > 2) {
			if (n & 1) {
				ans[0][0] += v;
				ans[1][n - 2] += v;
				for (int i = 2; i < n - 2; i ++)
					ans[i][i - 1] += v;
				ans[n - 2][n - 1] += v;
				ans[n - 1][n - 3] += v;
			}
			else {
				ans[0][0] += v;
				for (int i = 1; i < n - 1; i ++)
					ans[i][i + 1] += v;
				ans[n - 1][1] += v;
			}
		}

		for (auto &x: ans) {
			for (auto &y: x) cout << y << ' ';
			cout << '\n';
		}
	}
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
