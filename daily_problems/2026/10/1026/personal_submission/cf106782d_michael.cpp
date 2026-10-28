#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;

	auto f = [&](auto &self,vector<int> &arr,int i){
		if(i > n) return;
		for(auto &x : arr) x += 1;
		arr.push_back(1);
		int sz = arr.size();
		for(int i = 0; i < sz; ++i){
			arr.push_back(arr[i]);
		}
		self(self,arr,i + 1);
	};
	vector<int> ans;
	f(f,ans,1);
	cout << (1 << n + 1) - 2 << '\n';
	for(auto &x : ans){
		cout << x << ' ';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}