#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;

class FenwickTree {
public :
	int n;
	vector<int> c;
	FenwickTree(int t) : n(t), c(t + 10) {}

	int lowbit(int x) {
		return x & -x;
	}

	void add(int i, int x) {
		while (i <= n) c[i] += x, i += lowbit(i);
		return;
	}

	int query(int i) {
		int sum = 0;
		while (i) {
			sum += c[i];
			i -= lowbit(i);
		}
		return sum;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> arr(n + 1);
	FenwickTree tr(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = n; i >= 1; i--) {
		cnt += tr.query(arr[i]);
		tr.add(arr[i], 1);
	}
	cout << (cnt % 2 == n % 2 ? "Petr" : "Um_nik") << endl;
	return 0;
}
