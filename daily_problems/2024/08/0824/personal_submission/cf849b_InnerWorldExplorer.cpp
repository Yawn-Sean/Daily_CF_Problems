#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> y(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> y[i];
	}
	for (int i = 1; i <= 2; i ++) {
		for (int j = i + 1; j <= 3; j ++) {
			int k = (y[j] - y[i]) * 2 / (j - i);
			set<long long> s;
			for (int x = 1; x <= n; x ++ ) {
				s.insert(y[x] * 2 - 1LL * k * x);
				if (s.size() > 2) {
					break;
				}
			}
			if (s.size() == 2){
				return cout << "YES", 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
