#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

int n, a[N], in[N], f[N];
vector<int> g[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	for(int i = 1; i <= n; ++ i) {
		for(int d = a[i]; d <= n; d += a[i]) {
			for(auto j : {i + d, i - d}) {
				if(j < 1 || j > n || a[j] < a[i]) {
					continue;
				}
				g[j].eb(i), ++ in[i];
			}
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; ++ i) {
		if(!in[i])
			q.ep(i);
	}
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int y : g[x]) {
			if(!f[x]) {
				f[y] = 1;
			}
			if(!-- in[y]) {
				q.ep(y);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) cout << "BA"[f[i]];
	return 0;
}
