#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 105;

int n, d, a[N], f[N][N], x[N], y[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(f, 0x3f, sizeof f);
	
	cin >> n >> d;
	for(int i = 2; i <= n - 1; ++ i) cin >> a[i];
	
	for(int i = 1; i <= n; ++ i) {
		cin >> x[i] >> y[i];
		for(int j = 1; j < i; ++ j) {
			f[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[i];
			f[j][i] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[j];
		}
	}
	
	for(int k = 1; k <= n; ++ k) {
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j) {
				f[i][j]  = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	cout << f[1][n];
	return 0;
}
