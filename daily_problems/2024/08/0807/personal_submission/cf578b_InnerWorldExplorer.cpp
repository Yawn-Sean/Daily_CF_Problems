#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;


template <class T> bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, x;
	cin >> n >> k >> x;
	const int N = 63;
	vector<int> a(n);
	vector<int> bits(N);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		for (int j = 0; j < N; j ++) {
			if (a[i] & (1LL << j)) {
				bits[j] ++;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		vector<int> tmp_bits = bits;
		for (int j = 0; j < N; j ++) {
			if (a[i] & (1LL << j)) {
				tmp_bits[j] --;
			}
		}
		long long tmp = a[i];
		for (int u = 0; u < k; u ++) {
			tmp *= x;
		}
		long long cur = 0;
		for (int j = 0; j < N; j ++) {
			if (tmp & (1LL << j)) {
				tmp_bits[j] ++;
			}
			if (tmp_bits[j])
				cur |= (1LL << j);
		}
		ckmax(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
