#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		对于k=偶数可以发现不行 sum_d = (k-1) + xk 是一个奇数
		对于k=奇数进行构造
	*/
	
	int k;
	cin >> k;
	if (k % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	i64 tot = 1 + 2 * ((k - 1) + (k - 1) / 2 + (k - 1) * (k - 1));
	cout << 4 * k - 2 << ' ' <<  tot << '\n';
	
	auto add_edge = [&](int i, int j) {
		cout << i << ' ' << j << '\n';
	};
	
	// b1是桥的一端
	int b1 = 1;
	// 1->i
	for (int i = 2; i <= k; i++) {
		add_edge(b1, i);
	}
	
	for (int i = 2; i <= k; i++) {
		for (int j = k + 1; j<= 2 * k - 1; j++) {
			add_edge(i, j);
		}
	}
	for (int j = k + 1; j <= 2 * k - 1; j += 2) {
		add_edge(j, j + 1);
	}
		
	int b2 = 2 * k;
	add_edge(b1, b2);
	for (int i = 2 * k + 1; i <= 3 * k - 1; i++) {
		add_edge(b2, i);
	}
	
	for (int i = 2 * k + 1; i <= 3 * k - 1; i++) {
		for (int j = 3 * k; j<= 4 * k - 2; j++) {
			add_edge(i, j);
		}
	}
	for (int j = 3 * k; j<= 4 * k - 2; j += 2) {
		add_edge(j, j + 1);
	}
	
    return 0;
}
