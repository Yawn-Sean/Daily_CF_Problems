#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l28 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18,mod=1e9+7;
int a[N];
int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
    	int x,y;cin>>x>>y;
    	int ans=0;a[1]=y,a[2]=y,a[3]=y;
    	while(1){
    		sort(a+1,a+3+1);
    		a[1]=min(a[2]+a[3]-1,x);
    		ans++;
    		//cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<'\n';
    		if(a[1]==x&&a[2]==x&&a[3]==x)break;
		}
		cout<<ans<<'\n';
    }
    return 0;
}
