#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using uLL = unsigned long long;
const int N = 3E5 + 5 , base = 999991;
uLL p[N];

void init() {
	p[0] = 1;
	for (int i = 1 ; i < N ; ++i) {
		p[i] = p[i - 1] * base;
	}
}

void solve() {

	int n;
	cin >> n;

	vector<int> len(n);
	vector<string> s(n);
	vector<vector<int>> adj(n);
	vector<vector<uLL>> h(n);
	for (int i = 1 ; i <= n - 1 ; ++i) {
		int p;
		cin >> p >> s[i];
		p --;
		adj[p].push_back(i);
		len[i] = s[i].size();
		s[i] = " " + s[i];
		h[i].resize(len[i] + 1 , 0);
		for (int j = 1 ; j <= len[i] ; ++j) {
			h[i][j] = h[i][j - 1] * base + (s[i][j] - 'a' + 1);
		}
	}

	string t;
	cin >> t;
	int len_t = t.size();
	uLL val_t = 0;
	for (int i = 0 ; i < len_t ; ++i) {
		val_t = val_t * base + (t[i] - 'a' + 1);
	}
	
	auto get = [&] (uLL x , uLL y , int len) {
		uLL ans = x * p[len] + y;
		return ans;
	};	

	const int M = 20;
	vector<int> dep(n);
	vector<vector<int>> bz(n , vector<int>(M));
	vector<vector<int>> bz_len(n , vector<int>(M));
	vector<vector<uLL>> bz_h(n , vector<uLL>(M));
	function<void(int,int)> dfs = [&] (int u,int par) {
		if (par != -1) {
			bz[u][0] = par , bz_len[u][0] = len[u] , bz_h[u][0] = h[u][len[u]];
			for (int j = 1 ; j < M ; ++j) {
				bz[u][j] = bz[bz[u][j - 1]][j - 1];
				bz_len[u][j] = bz_len[u][j - 1] + bz_len[bz[u][j - 1]][j - 1];
				bz_h[u][j] = get(bz_h[bz[u][j - 1]][j - 1] , bz_h[u][j - 1] , bz_len[u][j - 1]);
			}
			dep[u] = dep[par] + len[u];
		}
		for (auto v : adj[u]) {
			if (v == par) {
				continue;
			}
			dfs(v , u);
		}
	};
	dfs(0 , -1);

	auto get_q = [&] (int i,int l,int r) {
		uLL ans = h[i][r] - h[i][l - 1] * p[r - l + 1];
		return ans;
	};

	int ans = 0;
	for (int v = 1 ; v <= n - 1 ; ++v) {
		uLL val = 0;
		for (int j = 1 ; j <= len[v] ; ++j) {
			val = val * base + (s[v][j] - 'a' + 1);
			if (len_t <= j) {
				if (val_t == get_q(v , j - len_t + 1 , j)) {
					++ans;
				}
			} else if (bz[v][0] != 0) {
				uLL num = 0;
				int u = bz[v][0] , tmp_len_t = len_t , cnt = 0;
				tmp_len_t -= j;
				if (dep[u] < tmp_len_t) continue;
				for (int k = M - 1 ; k >= 0 ; --k) {
					if (tmp_len_t >= bz_len[u][k]) {
						tmp_len_t -= bz_len[u][k];
						num = get(bz_h[u][k]  , num , cnt);
						cnt += bz_len[u][k];
						u = bz[u][k];
					}
				}
				num = get(num , val , j);
				cnt += j;
				if (cnt < len_t) {
					int diff = len_t - cnt;
					num = get(get_q(u , len[u] - diff + 1 , len[u]) , num , cnt);
				}
				if (num == val_t) {
					++ans;
				}
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
