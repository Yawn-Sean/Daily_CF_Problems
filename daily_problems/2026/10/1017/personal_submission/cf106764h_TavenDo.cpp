#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//

void solve() {
	int n,k;
	cin>>n>>k;
	int mxn=0;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mxn=max(a[i],mxn);
	}
	mxn+=k+5;
	vector<int>r(n+1),b(n+1);
	for(int i=1;i<=n;++i){
		cin>>r[i];
		int x=max(1,i-r[i]),y=min(n,i+r[i]);
		b[x]=max(b[x],y);
	}
	for(int i=2;i<=n;++i){
		b[i]=max(b[i],b[i-1]);
	}
	LL L=1,R=mxn,ans=0;
	auto wk=[&](int x)-> bool{
		vector<int>cur=a;
		vector<int>diff(n+2);
		int t=k,tot=0;
		for(int i=1;i<=n;++i){
			tot+=diff[i];
			cur[i]+=tot;
			if(cur[i]>=x){
				continue;
			}else{
				int p=x-cur[i];
				if(p>t){
					return false;
				}
				tot+=p;
				diff[b[i]+1]-=p;
				t-=p;
			}
		}
		return true;
	};
	while(L<=R){
		LL mid=(L+R)>>1;
		if(wk(mid)){
			L=mid+1;
			ans=mid;
		}else{
			R=mid-1;
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