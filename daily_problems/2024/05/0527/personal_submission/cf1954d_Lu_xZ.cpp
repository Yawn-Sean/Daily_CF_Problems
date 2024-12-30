#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5e3 + 5, P = 998244353;

ll n, a[N], f[N][N], ans, s[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	s[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 5000; j >= a[i]; -- j) {
			f[a[i]][j] = (f[a[i]][j] + s[j - a[i]]) % P;
			s[j] = (s[j] + s[j - a[i]]) % P;
		}
	}
	for(int i = 1; i <= a[n]; ++ i) {
		for(int j = i; j <= 5000; ++ j) {
			if(i >= j - i) {
				ans = (ans + f[i][j] * i) % P;
			}
			else {
				ans = (ans + f[i][j] * (j + 1 >> 1)) % P;
			}
		}
	}
	cout << ans;
	return 0;
}
