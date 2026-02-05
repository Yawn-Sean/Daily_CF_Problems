#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
//B-F
void solve()
{
    int n, m;
		cin >> n >> m;

		vector<array<int, 3>> edges(m);
		for (auto &[u, v, w]: edges) {
			cin >> u >> v >> w;
			u --, v --;
		}

		sort(edges.begin(), edges.end(), [&] (array<int, 3> &x, array<int, 3> &y) {return x[2] < y[2];});

		vector<int> ans(n, n);
		ans[0] = 0;

		int pt = 0;
		while (pt < m) {
			int npt = pt;
			while (npt < m && edges[pt][2] == edges[npt][2])
				npt ++;
			
			vector<pair<int, int>> updates;
			for (int i = pt; i < npt; i ++) {
				auto [u, v, w] = edges[i];
				updates.emplace_back(v, ans[u]);
				updates.emplace_back(u, ans[v] + 1);
			}

			for (auto &[u, d]: updates)
				ans[u] = min(ans[u], d);
			
			pt = npt;
		}

		cout << (ans[n - 1] < n ? ans[n - 1] : -1) << '\n';
}   
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
