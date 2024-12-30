#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

int n, h[N], f[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> h[i];
		f[i] = min(h[i], f[i - 1] + 1);
	}
	for(int i = n; i >= 1; -- i) {
		f[i] = min(f[i], f[i + 1] + 1);
	}
	
	cout << *max_element(f, f + n + 1);
	return 0;
}
