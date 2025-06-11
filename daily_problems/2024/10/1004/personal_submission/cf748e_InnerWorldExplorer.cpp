#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	i64 tot = 0;
	int mx = 0;
	for (int i = 0; i < n; i ++){
		cin >> a[i];
		tot += a[i];
		mx = max(mx, a[i]);
	}
	if (tot < k){
		return cout << -1 << endl, 0;
	}
	vector<int> f(mx + 1);
	auto check = [&](int mn){
		for (int i = mn; i <= mx; i ++){
			int half = i / 2;
			if (half >= mn){
				f[i] = f[half] + f[i - half];
			}else{
				f[i] = 1;
			}
		}
		i64 sum = 0;
		for (auto &x : a){
			if (x >= mn){
				sum += f[x];
			}
		}
		return sum >= k;
	};
	int l = 1, r = mx;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check(mid)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << l << endl;
	return 0;
}
