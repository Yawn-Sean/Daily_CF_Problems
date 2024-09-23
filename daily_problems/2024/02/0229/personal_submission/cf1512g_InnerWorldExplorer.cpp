#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int N = 10000001;
int f[N], m[N * 10];

void solve() {
	int c;
	cin >> c;
	if (m[c]) cout << m[c];
	else cout << -1;
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < N; i ++) {
		for (int j = i; j < N; j += i) {
			f[j] += i;
		}
	}
	for (int i = N - 1; i > 0; i --){
		m[f[i]] = i;
	}
	int t;
	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}
