#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
#define sz(x) (int)(x.size())
using PII=pair<int,int>;

//

void solve() {
	int o;
	cin>>o;
	vector<int>a(o);
	for(int i=0;i<o;++i){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	int m=sz(a);
	auto wk=[&](int x)->int{     
		int res=0;
		while(x){
			if(x&1)++res;
			x>>=1;
		}
		return res;
	};
	vector<int>P;
	for(int i=2;i<=50;++i){
		bool f=1;
		for(int j=2;j*j<=i;++j){
			if(i%j==0){
				f=false;
			}
		}
		if(f){
			P.push_back(i);
		}
	}
	int n=sz(P),N=1<<n;
	vector<PII>f(m,make_pair(0,1));
	vector<bool>vis(2511);
	for(int i=0;i<m;++i){
		int cur=a[i];
		for(int j=0;j<n;++j){
			if(cur%P[j]==0){
				f[i].fi+=(1<<j);
				while(cur%P[j]==0){
					cur/=P[j];
				}
			}
		}
		f[i].se=cur;
	}
	int ans=2e5;
	for(int msk=0;msk<N;++msk){
		int res=wk(msk);
		bool t=true;
		vector<int>act;
		for(int i=0;i<m;++i){
			if(!(f[i].fi&msk)){
				if(f[i].se==1){
					t=false;
					break;
				}else if(!vis[f[i].se]){
					++res;
					vis[f[i].se]=1;
					act.push_back(f[i].se);
				}
			}
		}
		if(t){
			ans=min(res,ans);
		}
		for(auto &x:act){
			vis[x]=false;
		}
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