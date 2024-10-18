#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	int even_move = 0, odd_move = 0, swap = 0;
	
	auto add = [&](int& x, int y) {
		x += y;
		if (x >= n) x -= n;
		if (x < 0) x += n;
	};

	while (q--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int x;
			cin >> x;
			add(odd_move, x);
			add(even_move, x);
			swap ^= (x & 1);
		} else {
			if (swap) {
				add(even_move, 1);
				add(odd_move, -1);
			} else {
				add(even_move, -1);
				add(odd_move, 1);
			}
			swap ^= 1;
		}
	}
	
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			ans[(i + even_move) % n] = i + 1;
		} else {
			ans[(i + odd_move) % n] = i + 1;
		}
	}
	for (auto& x: ans) { cout << x << ' '; }
	
    return 0;
}
