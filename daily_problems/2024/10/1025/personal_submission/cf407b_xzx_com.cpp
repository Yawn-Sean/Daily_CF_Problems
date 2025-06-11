#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l28 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18,mod=1e9+7;
int a[N],f[N];
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
    	int n;cin>>n;
    	for(int i=1;i<=n;i++)cin>>a[i];
    	for(int i=1;i<=n;i++){
    		f[i+1]=(2*f[i]-f[a[i]]+2+mod)%mod;
		}
		cout<<f[n+1]<<'\n';
    }
    return 0;
}
