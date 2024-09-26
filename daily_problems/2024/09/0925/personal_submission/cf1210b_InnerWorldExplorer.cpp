#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<i64> a(n), b(n);
	map<i64, int> m;
	for (auto &x : a){
		cin >> x;
		m[x] ++;
	}
	for (auto &x : b){
		cin >> x;
	}
	i64 ans = 0;
	vector<int> used(n + 1);
	for (auto &[k, v] : m){
		if (v > 1){
			for (int i = 0; i < n; i ++){
				if (!used[i] && (a[i] & k) == a[i]){
					used[i] = 1;
					ans += b[i];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
