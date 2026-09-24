#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXM = 1e5 + 1;

void solve(){
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> fp(MAXM,-1),lp(MAXM,-1),res(MAXM);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		nums[i] = x;

		if(fp[x] == -1) fp[x] = i;
		else res[x] = max(res[x],i - lp[x] - 1);
		lp[x] = i;
	}
	int mnGap = n;
	for(int i = 0; i < n; ++i){
		int x = nums[i];
		res[x] = max(res[x],fp[x] + n - 1 - lp[x]);
		mnGap = min(mnGap,res[x]);
	}

	cout << mnGap + n;
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