#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 4e6 + 5;
int n, m, f[N] = {1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		f[i] = (f[i] + f[i - 1]) % m;
		for(int k = 2; k <= n / i; ++ k) {
			int t = i * k;
			f[t] = (f[t] + f[i]) % m;
			if((t += k) <= n) {
				f[t] = (f[t] - f[i] + m) % m;
			}
		}
		if(i != 1) {
			f[i + 1] = (f[i + 1] + f[i]) % m;
		}
	}
	cout << f[n];
	return 0;
}
