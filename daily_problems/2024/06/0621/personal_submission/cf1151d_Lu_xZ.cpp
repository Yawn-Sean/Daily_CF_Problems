#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

ll n, a, b, c[N], ans;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a >> b;
		ans += n * b - a;
		c[i] = a - b;
	}
	sort(c + 1, c + n + 1);
	for(int i = 0; i < n; ++ i) {
		ans += c[n - i] * (i + 1);
	}
	cout << ans;
	return 0;
}
