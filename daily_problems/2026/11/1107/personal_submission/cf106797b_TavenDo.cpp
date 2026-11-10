#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
//

void solve() {
	int n,k;
	cin>>n>>k;
	vector<vector<int>>adj(n+1);
	int f;
	for(int i=2;i<=n;++i){
		cin>>f;
		adj[f].push_back(i);
	}
	vector<bool>res(n+1,true);
	int tot=n;
	auto wk=[&](auto self,int u)->int{
		int cur=1;
		for(auto &k:adj[u]){
			cur=max(cur,self(self,k)+1);
		}
		if(cur<k){
			res[u]=false;
			--tot;
			return cur;
		}
		return 0;
	};
	wk(wk,1);
	if(!res[1]){
		++tot;
		res[1]=true;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;++i){
		if(res[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}