#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int fa[100050];
i64 dep[100050];

i64 mod = 1e9 + 7;

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	int root = find(fa[x]);
	dep[x] = (dep[fa[x]] + dep[x]) % mod;
	fa[x] = root;
	return fa[x];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	i64 ans = 0;
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j++) {
			int v, x;
			cin >> v >> x;
			
			int fv = find(v);
			fa[fv] = i;
			dep[fv] = (dep[v] + x) % mod;
			ans = (ans + dep[fv]) % mod;
		}	
	}
	cout << (ans + mod) % mod;
    return 0;
}
