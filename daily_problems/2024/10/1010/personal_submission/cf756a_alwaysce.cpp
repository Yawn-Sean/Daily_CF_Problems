#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> perm(n);
	for (auto& v: perm) {
		cin >> v;
		v--;
	}
	
	// 找环的个数
	vector<int> vis(n, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			while (!vis[perm[i]]) {
				i = perm[i];
				vis[i] = 1;
			}
			cnt++;
		}
	}
	
	// 绕一圈回来flip次数是奇数就行
	int b = 0, v = 1;
	while (n--) {
		cin >> b;
		v ^= b;
	}
	
	cout << (cnt > 1 ? cnt : 0) + v;
	return 0;
}
