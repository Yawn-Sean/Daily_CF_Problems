#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> y(n);
	for (int i = 0; i < n; i ++){
		cin >> y[i];
	}
	auto check = [&](int mid){
		set<int> s;
		for (auto x : y){
			int t = x;
			while (t > mid || s.count(t)){
				t >>= 1;
			}
			if (!t) return set<int>();
			s.insert(t);
		}
		return s;
	};
	int l = 0, r = 1E9 + 10;
	while (l < r){
		int mid = (l + r) / 2;
		if ((int)check(mid).size() == n){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	for (auto x : check(l)){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
