#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
using LL=long long;

//利用背包计算所有可能值，然后贪心二分

const int MXN=1e6+5;
void solve() {
	int n,q;
	cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	vector<vector<int>>adj(n+1);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool>vis(MXN+1,false);
	vis[0]=1;
	while(q--){
		int x;
		cin>>x;
		for(int i=MXN;i>=x;--i){
			if(vis[i-x]){
				vis[i]=1;
			}
		}
	}
	vector<int>s;
	for(int i=0;i<=MXN;++i){
		if(vis[i]){
			s.push_back(i);
		}
	}
	bool f=true;
	auto wk=[&](auto self,int u,int v)->int{
		int cur=0;
		for(auto &k:adj[v]){
			if(k==u){
				continue;
			}
			cur=max(cur,self(self,v,k));
		}
		if(cur>a[v]){
			LL l=0,r=sz(s)-1,res=-1;
			while(l<=r){
				LL mid=(l+r)>>1;
				if(a[v]+s[mid]>=cur){
					r=mid-1;
					res=mid;
				}else{
					l=mid+1;
				}
			}
			if(res==-1){
				f=false;
			}else{
				a[v]+=s[res];
			}
		}
		return a[v];
	};
	wk(wk,-1,1);
	if(!f){
		cout<<-1<<endl;
		return;
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[i];
	}
	cout<<ans<<endl;
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
