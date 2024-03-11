#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5;
int a[N], b[N], c[N], tot, n;
 
void solve(int n) {
	for (int64_t i = 2; i <= n / i; ++i) {
		if (n % i == 0) {
			c[++tot] = i;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) c[++tot] = n;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int64_t i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	solve(a[1]);
	solve(b[1]);
    bool flag = false;
	for (int i = 1; i <= tot; ++i) {
		bool ok = false;
		for (int j = 1; j <= n; ++j) {
			if (a[j] % c[i] && b[j] % c[i]) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << c[i] << '\n';
			flag = true;
			break;
		}
	}
    if (!flag) {
        cout << -1 << '\n'; 
    }
	return 0;
 
}
