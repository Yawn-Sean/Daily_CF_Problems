#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e6 + 5;

int n, m, f[N], g[N], h[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++ i) {
		cin >> f[i];
		
		if(g[f[i]] == 0) {
			++ m;
			g[i] = m;
			h[m] = f[i];
			g[f[i]] = m;
		} 
		else {
			if(h[g[f[i]]] == f[i]) {
				g[i] = g[f[i]];
			}
			else {
				cout << -1;
				exit(0);
			}
		}
	}
	
	cout << m << '\n';
	for(int i = 1; i <= n; ++ i) cout << g[i] << " \n"[i == n];
	for(int i = 1; i <= m; ++ i) cout << h[i] << " \n"[i == m];
	
	return 0;
}
