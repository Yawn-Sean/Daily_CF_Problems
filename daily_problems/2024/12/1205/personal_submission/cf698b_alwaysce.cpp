#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int root = -1;
	vector<int> fa(n+1);
	for (int i = 1; i <= n; i++) {
		int u = i, v = a[i];
		fa[u] = v;
		if (u == v) {
			root = u;
		}
	}
	int ans = 0;
	vector<int> vis(n+1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int j = i;
			while (!vis[j]) {
				vis[j] = i;
				
				j = fa[j];
			}
			if (vis[j] == i and j != root) {
				ans++;
				if (root > 0) {
					a[j] = root;
				} else {
					a[j] = j;
					root = j;
				}
			}
			
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	
	return 0;
}
