#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
using LL=long long;
using i128=__int128;

void solve() {
	LL A,S,L,R;
	cin>>A>>S>>L>>R;
	if(S<A){
		cout<<0<<endl;
		return;
	}
	if(S==A){
		cout<<1<<endl;
		return;
	}
	int D=max(A-L+1,R-A+1);
	LL ans=0;
	for(int d=1;d<=D;++d){
		LL Y=(R-A)/d;
		for(LL x=0;A-x*d>=L;++x){
			LL l=0,r=Y,res=-1;
			while(l<=r){
				LL mid=(l+r)>>1;
				i128 T=((i128)(A)*2+(i128)(d)*(mid-x))*(x+mid+1)/2;
				if(T<=S){
					l=mid+1;
					res=mid;
				}else{
					r=mid-1;
				}
			}
			if(res==-1){
				continue;
			}
			i128 T=((i128)(A)*2+(i128)(d)*(res-x))*(x+res+1)/2;
			if(T==S){
				++ans;
			}
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
