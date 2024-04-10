#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), m = nxt(), i;
	vector<int> a(n), b(m);
	generate(all(a), nxt);
	generate(all(b), nxt);	
	sort(all(b), greater());
	sort(all(a));
	n = min(n, m);
	int64_t res = 0;
	for (i = 0; i < n; ++i) {
		if (b[i] > a[i]) {
			res += b[i] - a[i];
		} else {
			break;
		} 
	}

	cout << res << '\n';
	return 0;
}

/*
首先取出a数列的最小值x与b数列的最大值y进行操作(只是保证满足题意，取min(n,m)对x，y)。
最少的操作肯定就是变到同一个数c(c是任意的)，那么有ans=(y-c)+(c-x)=y-x。这个最终的c介于这么多对的x，y之间。
*/