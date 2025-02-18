#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	int type, d, odd = 0, even = 0;
	for (int i = 0; i < q; i ++) {
		cin >> type;
		if (type == 1) {
			cin >> d;
			odd = (odd + d + n) % n;
			even = (even + d + n) % n;
		} else {
			if (odd % 2) {
				odd -= 1;
				even += 1;
			} else {
				even -= 1;
				odd += 1;
			}
		}
	}
	vector<int> ans(n);
	for (int i = 1; i <= n; i ++) {
		if (i % 2) {
			ans[(i + odd - 1) % n] = i;
		} else {
			ans[(i + even - 1) % n] = i;
		}
	}

	for (int i = 0; i < n; i ++){
		cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}
