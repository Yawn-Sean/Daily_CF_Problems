#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for(auto &a : x) cin >> a;
	for(auto &a : y) cin >> a;
	vector<int> idxX(n);
	vector<int> idxY(n);
	iota(idxX.begin(),idxX.end(),1);
	iota(idxY.begin(),idxY.end(),1);
	sort(idxX.begin(),idxX.end(),[&](int i,int j) {return x[i - 1] < x[j - 1];});
	sort(idxY.begin(),idxY.end(),[&](int i,int j) {return y[i - 1] > y[j - 1];});
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		ans[idxX[i] - 1] = idxY[i];
	}
	for(const auto &a : ans){
		cout << a << " ";
	}
	cout << '\n';
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