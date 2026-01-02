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
const int N = 1e6 + 10;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[x] = y;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve()
{
    int n;
		cin >> n;

		vector<vector<pair<int, int>>> pos(2 * n + 1);

		for (int i = 0; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			pos[x].emplace_back(i, 0);
			pos[y].emplace_back(i, 1);
		}

		bool flg = true;
		DSU uf = DSU(2 * n);

		for (int i = 0; i <= 2 * n; i ++) {
			if (pos[i].size() > 2) flg = false;
			else if (pos[i].size() == 2) {
				auto [idx1, f1] = pos[i][0];
				auto [idx2, f2] = pos[i][1];
				if (f1 != f2) {
					uf.merge(idx1, idx2);
					uf.merge(idx1 + n, idx2 + n);
				}
				else {
					uf.merge(idx1, idx2 + n);
					uf.merge(idx1 + n, idx2);
				}
			}
		}

		for (int i = 0; i < n; i ++) {
			if (uf.same(i, i + n)) {
				flg = false;
			}
		}

		if (!flg) cout << -1 << '\n';
		else {
			vector<int> cnt(n, 0), cnt1(n, 0);
			for (int i = 0; i < 2 * n; i ++) {
				if (uf.find(i) < n) {
					cnt[uf.find(i)] ++;
					if (i < n) cnt1[uf.find(i)] ++;
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i ++)
				ans += min(cnt1[i], cnt[i] - cnt1[i]);
			
			cout << ans << '\n';
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
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
