#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> arr1(n);
	vector<int> arr2(m);
	for(auto &x : arr1) cin >> x;
	for(auto &x : arr2) cin >> x;
	
	int l = 0,r = min(n,m);
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		vector<int> v1,v2;
		for(const auto &x : arr1) if(x <= mid) v1.push_back(x);
		for(const auto &x : arr2) if(x <= mid) v2.push_back(x);

		if(v1 == v2) l = mid + 1;
		else r = mid - 1;
	}

	cout << n + m - r * 2 << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}