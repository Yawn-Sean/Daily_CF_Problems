#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int n, k, q;
	cin >> n >> k >> q;
 
	vector<string> strs(n);
	for (auto &s: strs) cin >> s;
 
	vector<int> vis(k, 0);
	atcoder::dsu uf(n);
	int cur = 1;
 
	while (q --) {
		int t;
		cin >> t;
 
		if (t == 1) {
			int idx;
			cin >> idx; idx --;
			
			if (!vis[idx]) {
				vis[idx] = 1;
				vector<int> tmp(10, -1);
 
				for (int i = 0; i < n; i ++) {
					if (tmp[strs[i][idx] % 10] != -1)
						uf.merge(tmp[strs[i][idx] % 10], i);
					tmp[strs[i][idx] % 10] = i;
					cur = max(cur, uf.size(i));
				}
			}
		}
		else if (t == 2) {
			int idx;
			cin >> idx;
			cout << uf.size(idx - 1) << '\n';
		}
		else cout << cur << '\n';
	}
 
	return 0;
}