#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1.5e5 + 5;
int n, a[N], d[N], idx;
bool f(int i) {
	if (i % 2) {
		if (a[i] >= a[i + 1]) return 0;
	} else {
		if (a[i] <= a[i + 1]) return 0;
	}
	return 1;
}
bool check(int i, int j) {
	swap(a[i], a[j]);
	bool fg = 1;
	for (int k = i - 1; k <= i + 1; k++) {
		if (!f(k)) fg = 0;
	}
	for (int k = j - 1; k <= j + 1; k++) {
		if (!f(k)) fg = 0;
	}
	swap(a[i], a[j]);
	return fg;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = N;
	if (n % 2 == 0) a[n + 1] = -1, a[n + 2] = N;
	else a[n + 1] = N, a[n + 2] = -1;

	for (int i = 1; i < n; i++) {
		if (i % 2) {
			if (a[i] >= a[i + 1]) d[++idx] = i;
		} else {
			if (a[i] <= a[i + 1]) d[++idx] = i;
		}
	}
	if (idx == 1) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (check(i, d[1])) res++;
			if (check(i, d[1] + 1)) res++;
		}
		if (check(d[1], d[1] + 1)) res--;
		cout << res;
	} else if (idx == 2) {
		int res = 0;
		for (int i = d[1]; i <= d[1] + 1; i++) {
			for (int j = d[2]; j <= d[2] + 1; j++) {
				if (check(i, j)) res++;
			}
		}
		if (d[2] - d[1] == 1) {
			for (int i = 1; i <= n; i++) {
				if (abs(d[2] - i) <= 1) continue;
				if (check(i, d[2])) res++;
			}
		}
		cout << res;
	} else if (idx == 3) {
		int res = 0;
		if (d[2] - d[1] == 1) {
			for (int i = d[3]; i <= d[3] + 1; i++) {
				if (check(d[2], i)) res++;
			}
		}
		if (d[3] - d[2] == 1) {
			for (int i = d[1]; i <= d[1] + 1; i++) {
				if (check(d[3], i)) res++;
			}
		}
		if (d[2] - d[1] == 1 && d[3] - d[2] == 1 && check(d[2], d[3])) res--;
		cout << res;
	} else if (idx == 4) {
		if (d[4] - d[1] == 3||(d[2]-d[1]==1&& d[4]-d[3]==1)) {//
			if (check(d[2], d[4])) cout << 1;
			else cout << 0;
		} else cout << 0;
	} else if (idx == 5|| idx==6) {
		if (d[idx] - d[1] == idx-1) {
			cout<<"-"<<endl;
			if (check(d[2], d[5])) cout << 1;
			else cout << 0;
		} else cout << 0;
	} else {
		cout << 0;
	}
	return 0;
}
