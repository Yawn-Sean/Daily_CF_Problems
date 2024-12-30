#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;cin >> n;
	using ll = long long;
	vector<ll> h(n);
	vector<ll> le(n);
	for (int i = 0;i < n;++i) {
		cin >> h[i];
	}
	le[0] = 1;
	for (int i = 1;i < n;++i) {
		le[i] = min(le[i - 1] + 1, h[i]);
	}
	ll rt = 1;
	ll r = 1;
	for (int i = n - 2;i >= 0;--i) {
		rt = min(rt + 1, h[i]);
		r = max(r, min(rt, le[i]));
	}
	cout << r;

	return 0;
}