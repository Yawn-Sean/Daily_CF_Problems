#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;
constexpr int N = 16, M = 1e4;

int n, m, a[N][M], b[N][N], c[N][N], f[N][1 << N];
int ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < m; ++ j) {
			cin >> a[i][j];
		}
	}
	memset(b, 0x3f, sizeof b), memset(c, 0x3f, sizeof c);
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			for(int k = 0; k < m; ++ k) {
				b[i][j] = min(b[i][j], abs(a[i][k] - a[j][k]));
				if(k) c[i][j] = min(c[i][j], abs(a[i][k - 1] - a[j][k]));
			}
		}
	}
	for(int st = 0; st < n; ++ st) {
		memset(f, 0, sizeof f);
		f[st][1 << st] = 0x3f3f3f3f;
		for(int s = 0; s < 1 << n; ++ s) {
			for(int i = 0; i < n; ++ i) if(s >> i & 1) {
				for(int j = 0; j < n; ++ j) {
					if(s >> j & 1) continue;
					f[j][s | 1 << j] = max(f[j][s | 1 << j], min(f[i][s], b[i][j]));
				}
			}
		}
		for(int i = 0; i < n; ++ i) {
			ans = max(ans, min(f[i][(1 << n) - 1], c[st][i]));
		}
	}
	cout << ans;
	return 0;
}
