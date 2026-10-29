#include <bits/stdc++.h>
using namespace std;

#define ll long long

bitset<1000005> bs;

void solve(){
	int n,q;
	cin >> n >> q;
	vector<vector<int>> graph(n);
	vector<int> nums(n);
	for(auto &x : nums) cin >> x;
	for(int i = 0,u,v; i < n - 1; ++i){
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	vector<int> val(q);
	for(auto &x : val) cin >> x;
	bs.set(0,1);
	for(auto &x : val){
		bs |= (bs << x);
	}
	vector<int> pv;
	for(int i = 0; i < 1000005; ++i){
		if(bs[i]){
			pv.push_back(i);
		}
	}

	bool flag = true;
	auto f = [&](auto &self,int u,int p) -> void{
		int mx = 0;
		for(auto &v : graph[u]){
			if(v != p){
				self(self,v,u);
				mx = max(mx,nums[v]);
			}
		}
		int idx = lower_bound(pv.begin(),pv.end(),mx - nums[u]) - pv.begin();
		if(idx == pv.size()) flag = false;
		else nums[u] += pv[idx];
	};

	f(f,0,-1);
	if(!flag) cout << -1;
	else{
		ll ans = 0;
		for(auto &x : nums){
			ans += x;
		}
		cout << ans;
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