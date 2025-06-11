#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	int k, b;
	vector<pair<long long, long long>> P(n);
	for (int i = 0; i < n; i ++) {
		cin >> k >> b;
		P[i] = {1LL * k * x1 + b, 1LL * k * x2 + b};
	}
	sort(P.begin(), P.end());
	for (int i = 0; i < n - 1; i ++){
		if (P[i].second > P[i + 1].second){
			return cout << "YES" << endl, 0;
		}
	}
	return cout << "NO" << endl, 0;
}
