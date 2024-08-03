	#include<bits/stdc++.h>
	using namespace std;
	const int N=3e5+10;
	typedef long long LL;
	int cnt[N],s[N];
	typedef pair<int,int>PII;
	#define x first
	#define y second

	void solve(){
		int n,p;cin>>n>>p;
		map<PII,int>mp;
		for(int i=1;i<=n;i++){
			int x,y;cin>>x>>y;
			cnt[x]++,cnt[y]++;
			if(x>y)swap(x,y);
			mp[{x,y}]++;
		}	
		LL ans=0;
		for(auto [u,v]:mp){
			if(cnt[u.x]+cnt[u.y]>=p&&cnt[u.x]+cnt[u.y]-v<p){
				ans--;
			}
		}
		sort(cnt+1,cnt+1+n);
		for(int i=1;i<=n;i++){
			auto t=lower_bound(cnt+1+i,cnt+n+1,p-cnt[i])-cnt;
			if(t==n+1)continue;
			ans+=(n-t+1);
		}


		cout<<ans<<"\n";

	}

	signed main(){
		ios::sync_with_stdio(0);
		cin.tie(0);
		solve();
		return 0;
	}
