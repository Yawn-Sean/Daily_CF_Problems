#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 1005, P = 998244353;

int n, k, f[N][N * 2][4];
int v[] = {0, 1, 1, 0};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
	for(int i = 2; i <= n; ++ i) {
		for(int j = 1; j <= 2 * i; ++ j) {
			for(int s = 0; s < 4; ++ s) {
				for(int t = 0; t < 4; ++ t) {
					int d = 0;
					if(s != t) {
						if(!v[t]) d = 1;
						else if(v[s]) d = 2;
					}
					if(j > d) {
						(f[i][j][s] += f[i - 1][j - d][t]) %= P;
					}
				}
			}
		}
	}
	cout << accumulate(f[n][k], f[n][k] + 4, 0ll) % P;
	return 0;
}
