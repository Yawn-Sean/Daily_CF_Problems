#include<bits/stdc++.h>
using namespace std;
int n, k, x, cnt[1030], add[1030];//
int main() {
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		cnt[t]++;
	}
	int f = 0;
	while (k--) {
		f = 0;
		for (int i = 0; i <= 1023; i++) {
			if (cnt[i]) {
//				cnt[i] -= f;
				int t = cnt[i] - f;
				if (t % 2) f = 1;
				else f = 0;
				add[i ^ x] += (t + 1) / 2;
				cnt[i] -= (t + 1) / 2;
			}
		}
		for (int i = 0; i <= 1023; i++) {
			cnt[i] += add[i];
			add[i] = 0;
		}
	}
	for (int i = 1023; i >= 0; i--) {
		if (cnt[i]) {
			cout << i << " ";
			break;
		}
	}
	for (int i = 0; i <= 1023; i++) {
		if (cnt[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}
