#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18;
PII a[N];
int b[N];
signed main() {
    int t=1;
    //cin >> t;
    while(t--) {
    	int n,h;cin>>n>>h;
		for(int i=1;i<=n;i++)cin>>a[i].fi,a[i].se=i; 
		sort(a+1,a+n+1);
		int mi=a[1].fi+a[2].fi,ma=a[n-1].fi+a[n].fi;
		int ans=ma-mi;
		if(n>=3){
			if(abs(max(ma,a[n].fi+h+a[1].fi)-min(mi+h,a[2].fi+a[3].fi))<=ma-mi){
				b[a[1].se]=1;
				ans=abs(max(ma,a[n].fi+h+a[1].fi)-min(mi+h,a[2].fi+a[3].fi));
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			if(b[i]==1)cout<<1<<' ';
			else cout<<2<<' ';
		}
    }
    return 0;
}
