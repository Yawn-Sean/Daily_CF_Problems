#include <bits/stdc++.h>

using namespace std;

inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {  
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	while (cin >> n) {
		int cnt = 0;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] == 1) ++cnt;
		}
		int mn = 1e5 + 7;
		if (cnt) {
			cout << n - cnt << '\n';
			exit(0);
		} else {
			for (int i = 0; i < n; ++i) {
				int cur = a[i];
				cnt = 0;
				for (int j = i + 1; j < n; ++j) {
					cnt++;
					cur = gcd(a[j], cur);
					if (cur == 1) {
						break;
					}
				}
				if (cur == 1) mn = min(mn, cnt + n - 1);
				
			}
		}
		cout << (mn == 1e5 + 7 ? -1 : mn) << '\n';
	}

    return 0;  
}

