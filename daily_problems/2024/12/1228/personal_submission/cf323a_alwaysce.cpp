#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	if (n & 1) {
		cout << -1;
		return 0;
	}
	char b = 'b', w = 'w';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if ((j / 2 + k / 2) & 1) {
					cout << b;
				} else {
					cout << w;
				}
			}
			cout << '\n';
		}
		cout << '\n';
		swap(b, w);
	}
	return 0;
}
