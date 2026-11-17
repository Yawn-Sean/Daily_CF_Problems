#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

const int N = 151, mod = 998244353;
int dp[N][N][N], ndp[N][N][N];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s, s1, s2, choice = "01";
	cin >> s;
	s1 = s, sort(s1.begin(), s1.end());
	s2 = s, sort(s2.rbegin(), s2.rend());

	dp[0][0][0] = 1;

	for (int i = 0; i < n; i ++) {
		for (int x = 0; x <= i; x ++) {
			for (int y = 0; y <= i; y ++) {
				for (int z = 0; z <= i; z ++) {
					if (dp[x][y][z]) {
						for (auto &c: choice) {
							int nx = x + (c != s[i]);
							int ny = y + (c != s1[i]);
							int nz = z + (c != s2[i]);
							add(ndp[nx][ny][nz], dp[x][y][z]);
						}
					}
				}
			}
		}

		for (int x = 0; x <= i + 1; x ++) {
			for (int y = 0; y <= i + 1; y ++) {
				for (int z = 0; z <= i + 1; z ++) {
					dp[x][y][z] = ndp[x][y][z];
					ndp[x][y][z] = 0;
				}
			}
		}
	}

	int ans = 0;

	for (int x = 0; x <= n; x ++) {
		for (int y = 0; y <= n; y ++) {
			for (int z = 0; z <= n; z ++) {
				if (x <= k || y < k || z < k) {
					add(ans, dp[x][y][z]);
				}
			}
		}
	}

	cout << ans;

	return 0;
}